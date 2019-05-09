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
with open(labels_file) as f:
    labels = f.readlines()
    num_classes = len(labels) + 1
number_train_images = 53177
number_test_images = 17845
