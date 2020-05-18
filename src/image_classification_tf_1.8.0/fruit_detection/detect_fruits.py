import tensorflow as tf
from utils import constants

with open(constants.root_dir + '\\utils\\labels') as f:
    labels = f.readlines()
labels = [x.strip() for x in labels]
labels = ["nothing"] + labels

tf.app.flags.DEFINE_string('image_path', 'images\\Lemon2.jpg', 'Path to image')
FLAGS = tf.app.flags.FLAGS


# load image
def read_image(image_path, image_reader):
    filename_queue = tf.train.string_input_producer([image_path])
    _, image_file = image_reader.read(filename_queue)
    local_image = tf.image.decode_jpeg(image_file)
    local_image = tf.image.convert_image_dtype(local_image, tf.float32)
    gray_image = tf.image.rgb_to_grayscale(local_image)
    local_image = tf.image.rgb_to_hsv(local_image)
    shape = tf.shape(local_image)
    local_height = shape[0]
    local_width = shape[1]
    local_depth = shape[2]
    local_image = tf.reshape(local_image, [local_height, local_width, local_depth])
    final_image = tf.concat([local_image, gray_image], 2)
    return final_image, local_height, local_width, local_depth + 1


def predict(sess, X, softmax, images):
    images = sess.run(images)
    # the result of running this method is an array of probabilities, where each index in the array corresponds to a label
    probability = sess.run(softmax, feed_dict={X: images})
    # get the highest probability from the array and that should be the result
    prediction = sess.run(tf.argmax(probability, 1))
    return prediction, probability[0][prediction]


def process_image(sess, X, softmax, image, image_height, image_width, image_depth):
    image_depth = sess.run(image_depth)
    image_height = sess.run(image_height)
    image_width = sess.run(image_width)
    # resize the image to 100 x 100 pixels and shape it to be like an array of one image, since that is the required input for the network
    # for smaller parts of an image and feed those to the network, tensorflow has a method called "extract_image_patches"
    img = tf.image.resize_images(tf.reshape(image, [-1, image_height, image_width, image_depth]), [100, 100])
    img = tf.reshape(img, [-1, 100 * 100 * 4])
    rez, prob = predict(sess, X, softmax, img)
    print('Label index: %d - Label: %s - Probability: %.4f' % (rez, labels[rez[0]], prob))


with tf.Session() as sess:
    image_path = FLAGS.image_path
    image_reader = tf.WholeFileReader()

    # restore the trained model from the saved checkpoint; provide the path to the meta file
    saver = tf.train.import_meta_graph(constants.fruit_models_dir + 'model.ckpt.meta')
    # provide the path to the folder containing the checkpoints
    saver.restore(sess, tf.train.latest_checkpoint(constants.fruit_models_dir))
    graph = tf.get_default_graph()

    # to obtain a tensor from the saved model, we must get it by name, which is why we name the tensors when we create them
    # even if there is only one tensor with a name, in the meta and checkpoint files it is saved as an array, so we have to provide the index of the
    # tensor that we want to get -> thus we call "get_tensor_by_name(tensor_name:0)"

    # obtain the input tensor by name
    X = graph.get_tensor_by_name('X:0')
    # obtain the output layer by name and apply softmax on in in order to obtain an output of probabilities
    softmax = tf.nn.softmax(graph.get_tensor_by_name('out/out:0'))

    image, height, width, depth = read_image(image_path, image_reader)
    coord = tf.train.Coordinator()
    threads = tf.train.start_queue_runners(sess=sess, coord=coord)
    process_image(sess, X, softmax, image, height, width, depth)

    coord.request_stop()
    coord.join(threads)
    sess.close()
