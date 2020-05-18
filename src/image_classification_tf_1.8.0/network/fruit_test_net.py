import numpy
import tensorflow as tf
import numpy as np
import os
import re

from network_structure import fruit_network as network
from network_structure import utils
from utils import constants


def setup_test_data():
    # create a map to add for each label the number of images that were labeled incorrectly
    mislabeled = {}

    # associate the label number with the actual human readable label name
    with open(constants.labels_file) as f:
        labels_text = f.readlines()
    labels_text = [x.strip() for x in labels_text]
    for label in labels_text:
        mislabeled[label] = 0

    # class 0 is background class so it's labeled as nothing
    labels_text = ["nothing"] + labels_text

    return mislabeled, labels_text


# create a dataset on the tfrecord files
# iterate once over all the images in the dataset to calculate accuracy
def build_dataset(filenames, batch_size):
    test_dataset = tf.data.TFRecordDataset(filenames)
    test_dataset = test_dataset.map(utils.parse_single_example).map(lambda image, label: (utils.build_hsv_grayscale_image(image), label))
    test_dataset = test_dataset.batch(batch_size)
    return test_dataset


def test_model(sess, pred, iterator, total_images, file_name):
    images_left_to_process = total_images
    total_number_of_images = total_images
    images_with_labels = iterator.get_next()
    correct = 0
    while True:
        try:
            batch_x, batch_y = sess.run(images_with_labels)
            batch_x = np.reshape(batch_x, [-1, network.input_size])
            # the results of the classification is an array of 1 and 0, 1 is a correct classification
            results = sess.run(pred, feed_dict={network.X: batch_x, network.Y: batch_y})
            images_left_to_process = images_left_to_process - len(results)
            for i in range(len(results)):
                if not results[i]:
                    mislabeled[labels_text[batch_y[i]]] += 1

            correct = correct + numpy.sum(results)
            print("Predicted %d out of %d; partial accuracy %.4f" % (correct, total_number_of_images - images_left_to_process,
                                                                     correct / (total_number_of_images - images_left_to_process)))
        except tf.errors.OutOfRangeError:
            break
    print("Final accuracy on %s data: %.8f" % (file_name, correct / total_number_of_images))


if __name__ == '__main__':

    with tf.Session() as sess:
        useTrain = False
        if useTrain:
            file_name = 'train'
            total_images = constants.number_train_images
        else:
            file_name = 'test'
            total_images = constants.number_test_images

        mislabeled, labels_text = setup_test_data()
        _, _, prediction = network.build_model()
        init = tf.global_variables_initializer()

        saver = tf.train.Saver()
        sess.run(init)
        tfrecords_files = [(constants.data_dir + f) for f in os.listdir(constants.data_dir) if re.match(file_name, f)]
        dataset = build_dataset(tfrecords_files, network.batch_size)
        iterator = dataset.make_one_shot_iterator()
        ckpt = tf.train.get_checkpoint_state(constants.fruit_models_dir)
        saver.restore(sess, ckpt.model_checkpoint_path)
        test_model(sess, prediction, iterator, total_images, file_name)
        print(mislabeled)

        sess.close()
