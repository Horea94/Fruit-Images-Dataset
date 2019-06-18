import os

root_dir = os.getcwd() + '\\..'
data_dir = root_dir + '\\data\\'
fruit_models_dir = root_dir + '\\fruit_models\\'
labels_file = root_dir + '\\utils\\labels'

# change this to the path of the folders that hold the images
training_images_dir = 'D:\\Robots\\Fruit-Images-Dataset\\Training'
test_images_dir = 'D:\\Robots\\Fruit-Images-Dataset\\Test'

# number of classes: number of fruit classes + 1 resulted due to the build_image_data.py script that leaves the first class as a background class
# using the labels file that is also used in the build_image_data.py

number_train_images = 0
number_test_images = 0
with open(labels_file) as f:
    labels = [line.rstrip() for line in f]
    num_classes = len(labels) + 1
    for label in labels:
        number_train_images += len(os.listdir(os.path.join(training_images_dir, label)))
        number_test_images += len(os.listdir(os.path.join(test_images_dir, label)))
