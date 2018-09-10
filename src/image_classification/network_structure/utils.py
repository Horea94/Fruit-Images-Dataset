import tensorflow as tf

HEIGHT = 100
WIDTH = 100
# number of channels for an image - jpeg image has RGB channels
CHANNELS = 3
# number of channels for the input layer of the network: HSV + gray scale
NETWORK_DEPTH = 4


# perform data augmentation on images
# add random hue and saturation
# randomly flip the image vertically and horizontally
# converts the image from RGB to HSV and
# adds a 4th channel to the HSV ones that contains the image in gray scale
def adjust_image_for_train(image):
    image = tf.image.convert_image_dtype(image, tf.float32)
    image = tf.image.random_hue(image, 0.02)
    image = tf.image.random_saturation(image, 0.9, 1.2)
    image = tf.image.random_flip_left_right(image)
    image = tf.image.random_flip_up_down(image)

    hsv_image = tf.image.rgb_to_hsv(image)
    gray_image = tf.image.rgb_to_grayscale(image)

    rez = tf.concat([hsv_image, gray_image], 2)
    return rez


# for test just convert the image to HSV and add the gray scale channel
def adjust_image_for_test(image):
    image = tf.image.convert_image_dtype(image, tf.float32)
    gray_image = tf.image.rgb_to_grayscale(image)
    image = tf.image.rgb_to_hsv(image)
    rez = tf.concat([image, gray_image], 2)
    return rez


def _int64_feature(value):
    if not isinstance(value, list):
        value = [value]
    return tf.train.Feature(int64_list=tf.train.Int64List(value=value))


def _bytes_feature(value):
    return tf.train.Feature(bytes_list=tf.train.BytesList(value=[value]))


# read an image tensor from the tfrecord file
def read_file(filenames):
    file_queue = tf.train.string_input_producer(filenames)
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
    image = tf.reshape(image, [HEIGHT, WIDTH, CHANNELS])
    label = tf.cast(features['label'], tf.int32)
    return image, label


def variable_with_weight_decay(name, shape, initializer):
    return tf.get_variable(name, shape, initializer=initializer, dtype=tf.float32)


def conv2d(op_name, x, W, b, strides=1):
    x = tf.nn.conv2d(x, W, strides=[1, strides, strides, 1], padding='SAME', name=op_name)
    x = tf.nn.bias_add(x, b)
    return tf.nn.relu(x)


def maxpool2d(op_name, x, k=2):
    return tf.nn.max_pool(x, ksize=[1, k, k, 1], strides=[1, k, k, 1], padding='SAME', name=op_name)


def norml(op_name, x):
    return tf.nn.lrn(x, 4, bias=1.0, alpha=0.001 / 9.0, beta=0.75, name=op_name)