import tensorflow as tf
from . import utils

batch_size = 50
input_size = utils.HEIGHT * utils.WIDTH * utils.NETWORK_DEPTH
# number of classes: 60 fruit classes + 1 resulted due to the build_image_data.py script that leaves the first class as a background class
num_classes = 75
# probability to keep the values after a training iteration
dropout = 0.8

# placeholder for input layer
X = tf.placeholder(tf.float32, [None, input_size], name="X")
# placeholder for actual labels
Y = tf.placeholder(tf.int64, [batch_size], name="Y")

initial_learning_rate = 0.001
final_learning_rate = 0.0001
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
    'conv_weight1': utils._variable_with_weight_decay('conv_weight1', [5, 5, 4, 16], tf.truncated_normal_initializer(stddev=5e-2, dtype=tf.float32)),
    'conv_weight2': utils._variable_with_weight_decay('conv_weight2', [5, 5, 16, 32], tf.truncated_normal_initializer(stddev=5e-2, dtype=tf.float32)),
    'conv_weight3': utils._variable_with_weight_decay('conv_weight3', [5, 5, 32, 64], tf.truncated_normal_initializer(stddev=5e-2, dtype=tf.float32)),
    'conv_weight4': utils._variable_with_weight_decay('conv_weight4', [5, 5, 64, 128], tf.truncated_normal_initializer(stddev=5e-2, dtype=tf.float32)),
    'fcl_weight1': utils._variable_with_weight_decay('fcl_weight1', [7 * 7 * 128, 1024], tf.truncated_normal_initializer(stddev=5e-2, dtype=tf.float32)),
    'fcl_weight2': utils._variable_with_weight_decay('fcl_weight2', [1024, 256], tf.truncated_normal_initializer(stddev=5e-2, dtype=tf.float32)),
    'out_weight': utils._variable_with_weight_decay('out_weight', [256, num_classes], tf.truncated_normal_initializer(stddev=5e-2, dtype=tf.float32)),
}
biases = {
    'conv_bias1': tf.Variable(tf.zeros([16])),
    'conv_bias2': tf.Variable(tf.zeros([32])),
    'conv_bias3': tf.Variable(tf.zeros([64])),
    'conv_bias4': tf.Variable(tf.zeros([128])),
    'fcl_bias1': tf.Variable(tf.zeros([1024])),
    'fcl_bias2': tf.Variable(tf.zeros([256])),
    'out_bias': tf.Variable(tf.zeros([num_classes]))
}
