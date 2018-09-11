import numpy
import tensorflow as tf
import numpy as np
import os
import re

from network_structure import fruit_network as network
from network_structure import utils
from utils import constants

useTrain = False

checkpoint_dir = os.getcwd() + '\\..\\fruit_models\\'
keep_prob = tf.placeholder(tf.float32)

if useTrain:
    images_left_to_process = constants.number_train_images
    total_number_of_images = constants.number_train_images
    file_name = 'train'
else:
    images_left_to_process = constants.number_test_images
    total_number_of_images = constants.number_test_images
    file_name = 'test'

# create a map to add for each label the number of images that were labeled incorrectly
mislabeled = {}

# associate the label number with the actual human readable label name
with open(constants.root_dir + '\\utils\\labels') as f:
    labels_text = f.readlines()
labels_text = [x.strip() for x in labels_text]
for label in labels_text:
    mislabeled[label] = 0

# class 0 is background class so it's labeled as nothing
labels_text = ["nothing"] + labels_text


def inputs(filename, batch_size):
    image, label = utils.read_file(filename)
    image = utils.adjust_image_for_test(image)
    images, labels = tf.train.batch([image, label],
                                    batch_size=batch_size,
                                    capacity=total_number_of_images,
                                    allow_smaller_final_batch=True)
    return images, labels


def test_model():
    global images_left_to_process
    correct = 0
    while images_left_to_process > 0:
        batch_x, batch_y = sess.run([images, labels])
        batch_x = np.reshape(batch_x, [network.batch_size, network.input_size])
        # the results of the classification is an array of 1 and 0, 1 is a correct classification
        results = sess.run(correct_pred, feed_dict={network.X: batch_x, network.Y: batch_y, keep_prob: 1})
        if images_left_to_process < network.batch_size:
            length = images_left_to_process
        else:
            length = network.batch_size
        images_left_to_process = images_left_to_process - length
        for i in range(length):
            if not results[i]:
                mislabeled[labels_text[batch_y[i]]] += 1

        correct = correct + numpy.sum(results[0:length])
        print("Predicted %d out of %d; partial accuracy %.4f" % (correct, total_number_of_images - images_left_to_process, correct / (total_number_of_images - images_left_to_process)))
    print("Final accuracy on %s data: %.8f" % (file_name, correct / total_number_of_images))


logits = network.conv_net(network.X, network.weights, network.biases, keep_prob)
prediction = tf.nn.softmax(logits)

loss_op = tf.reduce_mean(tf.nn.sparse_softmax_cross_entropy_with_logits(logits=logits,
                                                                        labels=network.Y))
optimizer = tf.train.AdamOptimizer(learning_rate=network.learning_rate)
train_op = optimizer.minimize(loss=loss_op)

correct_pred = tf.equal(tf.argmax(prediction, 1), network.Y)
accuracy = tf.reduce_mean(tf.cast(correct_pred, tf.float32))

init = tf.global_variables_initializer()

saver = tf.train.Saver()

with tf.Session() as sess:
    sess.run(init)
    tfrecords_files = [(constants.data_dir + f) for f in os.listdir(constants.data_dir) if re.match(file_name, f)]
    images, labels = inputs(tfrecords_files, network.batch_size)
    coord = tf.train.Coordinator()
    threads = tf.train.start_queue_runners(sess=sess, coord=coord)

    ckpt = tf.train.get_checkpoint_state(checkpoint_dir)
    saver.restore(sess, ckpt.model_checkpoint_path)

    test_model()
    print(mislabeled)

    coord.request_stop()
    coord.join(threads)
    sess.close()
