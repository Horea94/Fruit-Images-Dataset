import tensorflow as tf
import numpy as np
import time
import os

HEIGHT = 100
WIDTH = 100
CHANNELS = 3

initial_learning_rate = 0.001
final_learning_rate = 0.0001
learning_rate = initial_learning_rate

num_steps = 10000
batch_size = 50
step = 50
input_size = HEIGHT * WIDTH * CHANNELS
num_classes = 61
dropout = 0.8

useCkpt = False
checkpoint_dir = os.getcwd() + '\\models\\'

X = tf.placeholder(tf.float32, [None, input_size], name="X")
Y = tf.placeholder(tf.int64, [batch_size], name="Y")
keep_prob = tf.placeholder(tf.float32)


def _int64_feature(value):
    if not isinstance(value, list):
        value = [value]
    return tf.train.Feature(int64_list=tf.train.Int64List(value=value))


def _bytes_feature(value):
    return tf.train.Feature(bytes_list=tf.train.BytesList(value=[value]))


def read_file(filename):
    file_queue = tf.train.string_input_producer([filename])
    reader = tf.TFRecordReader()
    _, serialized_example = reader.read(file_queue)
    features = tf.parse_single_example(
        serialized_example,
        features={
            'image_raw': tf.FixedLenFeature([], tf.string),
            'label': tf.FixedLenFeature([], tf.int64),
            'height': tf.FixedLenFeature([], tf.int64),
            'width': tf.FixedLenFeature([], tf.int64)
        }
    )
    image = tf.image.decode_jpeg(features['image_raw'], channels=3)
    height = tf.cast(features['height'], tf.int32)
    width = tf.cast(features['width'], tf.int32)
    image = tf.reshape(image, [HEIGHT, WIDTH, 3])
    label = tf.cast(features['label'], tf.int32)
    return image, label


def inputs(filename, batch_size):
    image, label = read_file(filename)
    images, labels = tf.train.shuffle_batch([image, label],
                                            batch_size=batch_size,
                                            capacity=30000 + batch_size,
                                            min_after_dequeue=30000)
    return images, labels


def _variable_with_weight_decay(name, shape, initializer):
    return tf.get_variable(name, shape, initializer=initializer, dtype=tf.float32)


def conv2d(op_name, x, W, b, strides=1):
    x = tf.nn.conv2d(x, W, strides=[1, strides, strides, 1], padding='SAME', name=op_name)
    x = tf.nn.bias_add(x, b)
    return tf.nn.relu(x)


def maxpool2d(op_name, x, k=2):
    return tf.nn.max_pool(x, ksize=[1, k, k, 1], strides=[1, k, k, 1], padding='SAME', name=op_name)


def norml(op_name, x):
    return tf.nn.lrn(x, 4, bias=1.0, alpha=0.001 / 9.0, beta=0.75, name=op_name)


def conv_net(X, weights, biases, dropout):
    X = tf.reshape(X, shape=[-1, HEIGHT, WIDTH, CHANNELS])

    conv1 = conv2d('conv1', X, weights['conv_weight1'], biases['conv_bias1'])
    conv1 = maxpool2d('max_pool1', conv1, k=2)

    conv2 = conv2d('conv2', conv1, weights['conv_weight2'], biases['conv_bias2'])
    conv2 = maxpool2d('max_pool2', conv2, k=2)

    conv3 = conv2d('conv3', conv2, weights['conv_weight3'], biases['conv_bias3'])
    conv3 = maxpool2d('max_pool3', conv3, k=2)

    conv4 = conv2d('conv4', conv3, weights['conv_weight4'], biases['conv_bias4'])
    conv4 = maxpool2d('max_pool4', conv4, k=2)

    fc1 = tf.reshape(conv4, shape=[-1, weights['fcl_weight1'].get_shape().as_list()[0]])
    fc1 = tf.nn.relu(tf.add(tf.matmul(fc1, weights['fcl_weight1']), biases['fcl_bias1']))
    fc1 = tf.nn.dropout(fc1, dropout)

    fc2 = tf.nn.relu(tf.add(tf.matmul(fc1, weights['fcl_weight2']), biases['fcl_bias2']))
    fc2 = tf.nn.dropout(fc2, dropout)

    out = tf.add(tf.matmul(fc2, weights['out_weight']), biases['out_bias'], name='softmax')
    return out


weights = {
    'conv_weight1': _variable_with_weight_decay('conv_weight1', [5, 5, 3, 16], tf.truncated_normal_initializer(stddev=5e-2, dtype=tf.float32)),
    'conv_weight2': _variable_with_weight_decay('conv_weight2', [5, 5, 16, 32], tf.truncated_normal_initializer(stddev=5e-2, dtype=tf.float32)),
    'conv_weight3': _variable_with_weight_decay('conv_weight3', [5, 5, 32, 64], tf.truncated_normal_initializer(stddev=5e-2, dtype=tf.float32)),
    'conv_weight4': _variable_with_weight_decay('conv_weight4', [5, 5, 64, 128], tf.truncated_normal_initializer(stddev=5e-2, dtype=tf.float32)),
    'fcl_weight1': _variable_with_weight_decay('fcl_weight1', [7 * 7 * 128, 1024], tf.truncated_normal_initializer(stddev=5e-2, dtype=tf.float32)),
    'fcl_weight2': _variable_with_weight_decay('fcl_weight2', [1024, 256], tf.truncated_normal_initializer(stddev=5e-2, dtype=tf.float32)),
    'out_weight': _variable_with_weight_decay('out_weight', [256, num_classes], tf.truncated_normal_initializer(stddev=5e-2, dtype=tf.float32)),
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

logits = conv_net(X, weights, biases, keep_prob)
prediction = tf.nn.softmax(logits)

loss_op = tf.reduce_mean(tf.nn.sparse_softmax_cross_entropy_with_logits(logits=logits,
                                                                        labels=Y))
optimizer = tf.train.AdamOptimizer(learning_rate=learning_rate)
train_op = optimizer.minimize(loss=loss_op)

correct_pred = tf.equal(tf.argmax(prediction, 1), Y)
accuracy = tf.reduce_mean(tf.cast(correct_pred, tf.float32))

init = tf.global_variables_initializer()


def train_model():
    global learning_rate
    time1 = time.time()
    for i in range(1, num_steps + 1):
        with tf.Graph().as_default():

            batch_x, batch_y = sess.run([images, labels])
            batch_x = np.reshape(batch_x, [batch_size, input_size])

            sess.run(train_op, feed_dict={X: batch_x, Y: batch_y, keep_prob: dropout})

            if i % step == 0 or i == 1:
                loss, acc = sess.run([loss_op, accuracy], feed_dict={X: batch_x, Y: batch_y, keep_prob: 1})
                learning_rate = update_learning_rate(acc, learn_rate=initial_learning_rate)
                saver.save(sess, checkpoint_dir + 'model.ckpt')
                time2 = time.time()
                print("time: %.4f step: %d loss: %.4f accuracy: %.4f" % (time2 - time1, i, loss, acc))
                time1 = time.time()


def update_learning_rate(acc, learn_rate):
    return learn_rate - acc * learn_rate * 0.9


saver = tf.train.Saver()

with tf.Session() as sess:
    sess.run(init)
    tfrecords_name = 'train-00000-of-00001'
    images, labels = inputs(tfrecords_name, batch_size)
    coord = tf.train.Coordinator()
    threads = tf.train.start_queue_runners(sess=sess, coord=coord)

    if useCkpt:
        ckpt = tf.train.get_checkpoint_state(checkpoint_dir)
        saver.restore(sess, ckpt.model_checkpoint_path)

    train_model()

    coord.request_stop()
    coord.join(threads)
    sess.close()
