import os

project_root = os.path.join(os.getcwd(), '../../../')
parent_dir = os.path.join(os.getcwd(), '../')
data_dir = os.path.join(parent_dir, 'data/')
fruit_models_dir = os.path.join(parent_dir, 'fruit_models/')
labels_file = os.path.join(parent_dir, 'utils/labels')

# change this to the path of the folders that hold the images
training_images_dir = os.path.join(project_root, 'Training/')
test_images_dir = os.path.join(project_root, 'Test/')

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
