import tensorflow as tf
import math
from . import utils
from utils import constants

batch_size = 50
input_size = utils.HEIGHT * utils.WIDTH * utils.NETWORK_DEPTH
# number of max pool operations used in the network structure;
# used when calculating the input size for the first fully connected layer
# MUST BE UPDATED if the number of max pool operations changes or if the type of max pool changes
number_of_max_pools = 4
new_width = math.ceil(utils.WIDTH/(1 << number_of_max_pools))
new_height = math.ceil(utils.HEIGHT/(1 << number_of_max_pools))
# probability to keep the values after a training iteration
dropout = 0.8

# placeholder for input layer
X = tf.placeholder(tf.float32, [None, input_size], name="X")
# placeholder for actual labels
Y = tf.placeholder(tf.int64, [batch_size], name="Y")

# number of activation maps for each convolutional layer
number_of_act_maps_conv1 = 16
number_of_act_maps_conv2 = 32
number_of_act_maps_conv3 = 64
number_of_act_maps_conv4 = 128

# number of outputs for each fully connected layer
number_of_fcl_outputs1 = 1024
number_of_fcl_outputs2 = 256

initial_learning_rate = 0.001
final_learning_rate = 0.00001
learning_rate = initial_learning_rate


def conv_net(X, weights, biases, dropout):
    X = tf.reshape(X, shape=[-1, utils.HEIGHT, utils.WIDTH, utils.NETWORK_DEPTH])

    conv1 = utils.conv2d('conv1', X, weights['conv_weight1'], biases['conv_bias1'])
    conv1 = utils.maxpool2d('max_pool1', conv1, k=2)

    conv2 = utils.conv2d('conv2', conv1, weights['conv_weight2'], biases['conv_bias2'])
    conv2 = utils.maxpool2d('max_pool2', conv2, k=2)

    conv3 = utils.conv2d('conv3', conv2, weights['conv_weight3'], biases['conv_bias3'])
    conv3 = utils.maxpool2d('max_pool3', conv3, k=2)

    conv4 = utils.conv2d('conv4', conv3, weights['conv_weight4'], biases['conv_bias4'])
    conv4 = utils.maxpool2d('max_pool4', conv4, k=2)

    fc1 = tf.reshape(conv4, shape=[-1, weights['fcl_weight1'].get_shape().as_list()[0]])
    fc1 = tf.nn.relu(tf.add(tf.matmul(fc1, weights['fcl_weight1']), biases['fcl_bias1']))
    fc1 = tf.nn.dropout(fc1, dropout)

    fc2 = tf.nn.relu(tf.add(tf.matmul(fc1, weights['fcl_weight2']), biases['fcl_bias2']))
    fc2 = tf.nn.dropout(fc2, dropout)

    out = tf.add(tf.matmul(fc2, weights['out_weight']), biases['out_bias'], name='softmax')
    return out


weights = {
    'conv_weight1': utils.variable_with_weight_decay('conv_weight1', [5, 5, utils.NETWORK_DEPTH, number_of_act_maps_conv1],
                                                     tf.truncated_normal_initializer(stddev=5e-2, dtype=tf.float32)),
    'conv_weight2': utils.variable_with_weight_decay('conv_weight2', [5, 5, number_of_act_maps_conv1, number_of_act_maps_conv2],
                                                     tf.truncated_normal_initializer(stddev=5e-2, dtype=tf.float32)),
    'conv_weight3': utils.variable_with_weight_decay('conv_weight3', [5, 5, number_of_act_maps_conv2, number_of_act_maps_conv3],
                                                     tf.truncated_normal_initializer(stddev=5e-2, dtype=tf.float32)),
    'conv_weight4': utils.variable_with_weight_decay('conv_weight4', [5, 5, number_of_act_maps_conv3, number_of_act_maps_conv4],
                                                     tf.truncated_normal_initializer(stddev=5e-2, dtype=tf.float32)),
    'fcl_weight1': utils.variable_with_weight_decay('fcl_weight1', [new_width * new_height * number_of_act_maps_conv4, number_of_fcl_outputs1],
                                                    tf.truncated_normal_initializer(stddev=5e-2, dtype=tf.float32)),
    'fcl_weight2': utils.variable_with_weight_decay('fcl_weight2', [number_of_fcl_outputs1, number_of_fcl_outputs2],
                                                    tf.truncated_normal_initializer(stddev=5e-2, dtype=tf.float32)),
    'out_weight': utils.variable_with_weight_decay('out_weight', [number_of_fcl_outputs2, constants.num_classes],
                                                   tf.truncated_normal_initializer(stddev=5e-2, dtype=tf.float32)),
}
biases = {
    'conv_bias1': tf.Variable(tf.zeros([number_of_act_maps_conv1])),
    'conv_bias2': tf.Variable(tf.zeros([number_of_act_maps_conv2])),
    'conv_bias3': tf.Variable(tf.zeros([number_of_act_maps_conv3])),
    'conv_bias4': tf.Variable(tf.zeros([number_of_act_maps_conv4])),
    'fcl_bias1': tf.Variable(tf.zeros([number_of_fcl_outputs1])),
    'fcl_bias2': tf.Variable(tf.zeros([number_of_fcl_outputs2])),
    'out_bias': tf.Variable(tf.zeros([constants.num_classes]))
}
