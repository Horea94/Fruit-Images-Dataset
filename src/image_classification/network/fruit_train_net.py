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
# default amount of iterations after we display the loss and accuracy
display_interval = 250
# use the saved model and continue training
useCkpt = False
# placeholder for probability to keep the network parameters after an iteration
keep_prob = tf.placeholder(tf.float32, name='keep_prob')


# prepare the input tensors for the network
def inputs(filenames, batch_size):
    image, label = utils.read_files(filenames)
    image = utils.adjust_image_for_train(image)
    images, labels = tf.train.shuffle_batch([image, label],
                                            batch_size=batch_size,
                                            capacity=35000 + batch_size,
                                            min_after_dequeue=5000,
                                            allow_smaller_final_batch=True)
    return images, labels


# build the network
logits = network.conv_net(network.X, network.weights, network.biases, keep_prob)
# apply softmax on the final layer
prediction = tf.nn.softmax(logits)

# calculate the loss using the predicted labels vs the expected labels
loss_operation = tf.reduce_mean(tf.nn.sparse_softmax_cross_entropy_with_logits(logits=logits,
                                                                               labels=network.Y))
# use adaptive moment estimation optimizer
optimizer = tf.train.AdamOptimizer(learning_rate=network.learning_rate)
train_op = optimizer.minimize(loss=loss_operation)

# calculate the accuracy for this training step
correct_prediction = tf.equal(tf.argmax(prediction, 1), network.Y)
accuracy = tf.reduce_mean(tf.cast(correct_prediction, tf.float32))

init = tf.global_variables_initializer()


def train_model():
    time1 = time.time()
    for i in range(1, iterations + 1):
        with tf.Graph().as_default():

            batch_x, batch_y = sess.run([images, labels])
            batch_x = np.reshape(batch_x, [network.batch_size, network.input_size])

            sess.run(train_op, feed_dict={network.X: batch_x, network.Y: batch_y, keep_prob: network.dropout})

            if i % display_interval == 0 or i == 1:
                loss, acc = sess.run([loss_operation, accuracy], feed_dict={network.X: batch_x, network.Y: batch_y, keep_prob: 1})
                network.learning_rate = network.update_learning_rate(acc, learn_rate=network.initial_learning_rate)
                # save the weights and the meta data for the graph
                saver.save(sess, constants.fruit_models_dir + 'model.ckpt')
                tf.train.write_graph(sess.graph_def, constants.fruit_models_dir, 'graph.pbtxt')
                time2 = time.time()
                print("time: %.4f step: %d loss: %.4f accuracy: %.4f" % (time2 - time1, i, loss, acc))
                time1 = time.time()


saver = tf.train.Saver()

with tf.Session() as sess:
    sess.run(init)
    # input tfrecord files
    tfrecords_files = [(constants.data_dir + f) for f in os.listdir(constants.data_dir) if re.match('train', f)]
    images, labels = inputs(tfrecords_files, network.batch_size)
    coord = tf.train.Coordinator()
    threads = tf.train.start_queue_runners(sess=sess, coord=coord)

    # restore the previously saved value if we wish to continue the training
    if useCkpt:
        ckpt = tf.train.get_checkpoint_state(constants.fruit_models_dir)
        saver.restore(sess, ckpt.model_checkpoint_path)

    train_model()

    coord.request_stop()
    coord.join(threads)
    sess.close()
