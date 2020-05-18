import tensorflow as tf
import numpy as np
import time
import os
import re

from network_structure import fruit_network as network
from network_structure import utils

from utils import constants

# default number of iterations to run the training
iterations = 75000
# default number of iterations after we display the loss and accuracy
acc_display_interval = 1000
# default number of iterations after we save the model
save_interval = 5000
# default number of iterations after we display the total number of steps done and the time spent training the past step_display_interval iterations
step_display_interval = 100
# use the saved model and continue training
useCkpt = False

train_iterator_key = "train_iterator"
validation_iterator_key = "validation_iterator"
validation_iterator_init_op_key = "validation_init_op"


# create two datasets from the previously created training tfrecord files
# the first dataset will apply data augmentation and shuffle its elements and will continuously queue new items - used for training
# the second dataset will iterate once over the training images - used for evaluating the loss and accuracy during the training
def build_datasets(filenames, batch_size):
    train_dataset = tf.data.TFRecordDataset(filenames).repeat()
    train_dataset = train_dataset.map(utils.parse_single_example).map(lambda image, label: (utils.augment_image(image), label))
    train_dataset = train_dataset.shuffle(buffer_size=10000, reshuffle_each_iteration=True)
    train_dataset = train_dataset.batch(batch_size)
    test_dataset = tf.data.TFRecordDataset(filenames)
    test_dataset = test_dataset.map(utils.parse_single_example).map(lambda image, label: (utils.build_hsv_grayscale_image(image), label))
    test_dataset = test_dataset.batch(batch_size)
    return train_dataset, test_dataset


def train_model(session, train_operation, loss_operation, correct_prediction, iterator_map):
    time1 = time.time()
    train_iterator = iterator_map[train_iterator_key]
    validation_iterator = iterator_map[validation_iterator_key]
    validation_init_op = iterator_map[validation_iterator_init_op_key]
    train_images_with_labels = train_iterator.get_next()
    validation_images_with_labels = validation_iterator.get_next()
    for i in range(1, iterations + 1):
        batch_x, batch_y = session.run(train_images_with_labels)
        batch_x = np.reshape(batch_x, [network.batch_size, network.input_size])
        session.run(train_operation, feed_dict={network.X: batch_x, network.Y: batch_y})

        if i % step_display_interval == 0:
            time2 = time.time()
            print("time: %.4f step: %d" % (time2 - time1, i))
            time1 = time.time()

        if i % acc_display_interval == 0:
            acc_value, loss = calculate_intermediate_accuracy_and_loss(session, correct_prediction, loss_operation, validation_images_with_labels, validation_init_op, constants.number_train_images)
            network.learning_rate = network.update_learning_rate(acc_value, learn_rate=network.learning_rate)
            print("step: %d loss: %.4f accuracy: %.4f" % (i, loss, acc_value))
        if i % save_interval == 0:
            # save the weights and the meta data for the graph
            saver.save(session, constants.fruit_models_dir + 'model.ckpt')
            tf.train.write_graph(session.graph_def, constants.fruit_models_dir, 'graph.pbtxt')


def calculate_intermediate_accuracy_and_loss(session, correct_prediction, loss_operation, test_images_with_labels, test_init_op, total_image_count):
    sess.run(test_init_op)
    loss = 0
    predicted = 0
    count = 0
    while True:
        try:
            test_batch_x, test_batch_y = session.run(test_images_with_labels)
            test_batch_x = np.reshape(test_batch_x, [-1, network.input_size])
            l, p = session.run([loss_operation, correct_prediction], feed_dict={network.X: test_batch_x, network.Y: test_batch_y})
            loss += l
            predicted += np.sum(p)
            count += 1
        except tf.errors.OutOfRangeError:
            break
    return predicted / total_image_count, loss / count


if __name__ == '__main__':

    with tf.Session().as_default() as sess:

        # input tfrecord files
        tfrecords_files = [(constants.data_dir + f) for f in os.listdir(constants.data_dir) if re.match('train', f)]
        train_dataset, validation_dataset = build_datasets(filenames=tfrecords_files, batch_size=network.batch_size)
        train_iterator = train_dataset.make_one_shot_iterator()
        test_iterator = tf.data.Iterator.from_structure(validation_dataset.output_types, validation_dataset.output_shapes)
        test_init_op = test_iterator.make_initializer(validation_dataset)
        iterator_map = {train_iterator_key: train_iterator,
                        validation_iterator_key: test_iterator,
                        validation_iterator_init_op_key: test_init_op}

        train_op, loss, correct_prediction = network.build_model()
        init = tf.global_variables_initializer()
        saver = tf.train.Saver()
        sess.run(init)

        # restore the previously saved value if we wish to continue the training
        if useCkpt:
            ckpt = tf.train.get_checkpoint_state(constants.fruit_models_dir)
            saver.restore(sess, ckpt.model_checkpoint_path)

        train_model(sess, train_op, loss, correct_prediction, iterator_map)

        sess.close()
