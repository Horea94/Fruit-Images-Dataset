import tensorflow as tf


# perform data augmentation on images
# add random hue and saturation
# randomly flip the image vertically and horizontally
# converts the image from RGB to HSV and
# adds a 4th channel to the HSV ones that contains the image in gray scale
def augment_image(image):
    image = tf.image.convert_image_dtype(image, tf.float32)
    image = tf.image.random_hue(image, 0.02)
    image = tf.image.random_saturation(image, 0.9, 1.2)
    image = tf.image.random_flip_left_right(image)
    image = tf.image.random_flip_up_down(image)
    return build_hsv_grayscale_image(image)


# convert the image to HSV and add the gray scale channel
def build_hsv_grayscale_image(image):
    image = tf.image.convert_image_dtype(image, tf.float32)
    gray_image = tf.image.rgb_to_grayscale(image)
    image = tf.image.rgb_to_hsv(image)
    rez = tf.concat([image, gray_image], 2)
    return rez


def parse_single_example(serialized_example):
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
    image = tf.reshape(image, [100, 100, 3])
    label = tf.cast(features['label'], tf.int32)
    return image, label


def conv(input_tensor, name, kernel_width, kernel_height, num_out_activation_maps, stride_horizontal=1, stride_vertical=1, activation_fn=tf.nn.relu):
    prev_layer_output = input_tensor.get_shape()[-1].value
    with tf.variable_scope(name):
        weights = tf.get_variable('weights', [kernel_height, kernel_width, prev_layer_output, num_out_activation_maps], tf.float32,
                                  tf.truncated_normal_initializer(stddev=5e-2, dtype=tf.float32))
        biases = tf.get_variable("bias", [num_out_activation_maps], tf.float32, tf.constant_initializer(0.0))
        conv_layer = tf.nn.conv2d(input_tensor, weights, (1, stride_horizontal, stride_vertical, 1), padding='SAME')
        activation = activation_fn(tf.nn.bias_add(conv_layer, biases), name=name)
        return activation


def fully_connected(input_tensor, name, output_neurons, activation_fn=tf.nn.relu):
    n_in = input_tensor.get_shape()[-1].value
    with tf.variable_scope(name):
        weights = tf.get_variable('weights', [n_in, output_neurons], tf.float32,
                                  initializer=tf.truncated_normal_initializer(stddev=5e-2, dtype=tf.float32))
        biases = tf.get_variable("bias", [output_neurons], tf.float32, tf.constant_initializer(0.0))
        logits = tf.nn.bias_add(tf.matmul(input_tensor, weights), biases, name=name)
        if activation_fn is None:
            return logits
        return activation_fn(logits)


def max_pool(input_tensor, name, kernel_height, kernel_width, stride_horizontal, stride_vertical):
    return tf.nn.max_pool(input_tensor,
                          ksize=[1, kernel_height, kernel_width, 1],
                          strides=[1, stride_horizontal, stride_vertical, 1],
                          padding='VALID',
                          name=name)


def loss(logits, onehot_labels):
    xentropy = tf.nn.softmax_cross_entropy_with_logits(logits=logits, labels=onehot_labels, name='xentropy')
    loss = tf.reduce_mean(xentropy, name='loss')
    return loss


def _int64_feature(value):
    if not isinstance(value, list):
        value = [value]
    return tf.train.Feature(int64_list=tf.train.Int64List(value=value))


def _bytes_feature(value):
    return tf.train.Feature(bytes_list=tf.train.BytesList(value=[value]))
