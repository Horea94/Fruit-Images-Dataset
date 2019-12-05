import tensorflow as tf
import numpy as np
from . import utils
from utils import constants

HEIGHT = 100
WIDTH = 100
# number of channels for an image - jpeg image has RGB channels
CHANNELS = 3
# number of channels for the input layer of the network: HSV + gray scale
NETWORK_DEPTH = 4

batch_size = 60
input_size = HEIGHT * WIDTH * NETWORK_DEPTH
# probability to keep the values after a training iteration
dropout = 0.8

# placeholder for input layer
X = tf.placeholder(tf.float32, [None, input_size], name="X")
# placeholder for actual labels
Y = tf.placeholder(tf.int64, [None], name="Y")

initial_learning_rate = 0.001
final_learning_rate = 0.00001
learning_rate = initial_learning_rate


def conv_net(input_layer):
    # number of activation maps for each convolutional layer
    number_of_act_maps_conv1 = 16
    number_of_act_maps_conv2 = 32
    number_of_act_maps_conv3 = 64
    number_of_act_maps_conv4 = 128

    # number of outputs for each fully connected layer
    number_of_fcl_outputs1 = 1024
    number_of_fcl_outputs2 = 256

    input_layer = tf.reshape(input_layer, shape=[-1, HEIGHT, WIDTH, NETWORK_DEPTH])

    conv1 = utils.conv(input_layer, 'conv1', kernel_width=5, kernel_height=5, num_out_activation_maps=number_of_act_maps_conv1)
    conv1 = utils.max_pool(conv1, 'max_pool1', kernel_height=2, kernel_width=2, stride_horizontal=2, stride_vertical=2)

    conv2 = utils.conv(conv1, 'conv2', kernel_width=5, kernel_height=5, num_out_activation_maps=number_of_act_maps_conv2)
    conv2 = utils.max_pool(conv2, 'max_pool2', kernel_height=2, kernel_width=2, stride_horizontal=2, stride_vertical=2)

    conv3 = utils.conv(conv2, 'conv3', kernel_width=5, kernel_height=5, num_out_activation_maps=number_of_act_maps_conv3)
    conv3 = utils.max_pool(conv3, 'max_pool3', kernel_height=2, kernel_width=2, stride_horizontal=2, stride_vertical=2)

    conv4 = utils.conv(conv3, 'conv4', kernel_width=5, kernel_height=5, num_out_activation_maps=number_of_act_maps_conv4)
    conv4 = utils.max_pool(conv4, 'max_pool4', kernel_height=2, kernel_width=2, stride_horizontal=2, stride_vertical=2)

    flattened_shape = np.prod([s.value for s in conv4.get_shape()[1:]])
    net = tf.reshape(conv4, [-1, flattened_shape], name="flatten")

    fcl1 = utils.fully_connected(net, 'fcl1', number_of_fcl_outputs1)
    fcl1 = tf.nn.dropout(fcl1, dropout)

    fcl2 = utils.fully_connected(fcl1, 'fcl2', number_of_fcl_outputs2)
    fcl2 = tf.nn.dropout(fcl2, dropout)

    out = utils.fully_connected(fcl2, 'out', constants.num_classes, activation_fn=None)

    return out


def update_learning_rate(acc, learn_rate):
    return max(learn_rate - acc * learn_rate * 0.9, final_learning_rate)


def build_model():
    # build the network
    logits = conv_net(input_layer=X)
    # apply softmax on the final layer
    prediction = tf.nn.softmax(logits)

    # calculate the loss using the predicted labels vs the expected labels
    loss = tf.reduce_mean(tf.nn.sparse_softmax_cross_entropy_with_logits(logits=logits, labels=Y))
    # use adaptive moment estimation optimizer
    optimizer = tf.train.AdamOptimizer(learning_rate=learning_rate)
    train_op = optimizer.minimize(loss=loss)

    # calculate the accuracy for this training step
    correct_prediction = tf.equal(tf.argmax(prediction, 1), Y)

    return train_op, loss, correct_prediction
