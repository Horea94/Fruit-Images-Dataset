### Requirements ###

  Make sure you have the latest version of tensorflow installed. Instalation guide [here](https://www.tensorflow.org/install/).

### Bundle images into tf record files ###

Use the [utils/build_image_data.py](utils/build_image_data.py) script to generate the train-00000-of-00001 and validation-00000-of-00001 tfrecords file 
which are needed for the train and test scripts. 

In the [utils/build_image_data.py](utils/build_image_data.py) file you can modify the path to the dataset, the location where the tfrecords are saved and 
the path to the labels file. The labels file contains the labels(names of folders) from the dataset that you want to include in the tfrecord files, each label must be on a newline.

Alternatively, the build_image_data.py can be run from the command line like this:

    python build_image_data.py [flags]

The available options are:

    --train_directory=path to the folder containing the train images 

    --validation_directory=path to the folder containing the validation images 

    --output_directory=path to where to output the tfrecord files 

    --labels_file=path to the label file

### Train the network ###

Run the [network/fruit_train_net.py](network/fruit_train_net.py) to train the network - currently the network runs for 20000 iterations and saves the 
network state every 50 steps. 
By default, the [network/fruit_train_net.py](network/fruit_train_net.py) and the [network/fruit_test_net.py](network/fruit_test_net.py) scripts expect the tfrecords files(obtained using the build_image_data.py script) to be in a folder called "data", at the same level as the network folder. This can be changed in the utils/constants.py by changing the "data_dir" variable.
This script will generate the fruit_models/ folder where the network parameters and the graph meta data 
are saved.

### Test the network ###

After training the network run the [network/fruit_test_net.py](network/fruit_test_net.py) to test the obtained model.

### Use the trained model ###

The [fruit_detection/detect_fruits.py](fruit_detection/detect_fruits.py) script contains a basic example on how to load the trained model, how to read an image and how to feed it to the network and how to get the output and interpret it.

The script has only a flag:

    --image_path=path to the image to be read and classified

### Customization ###

The [network_structure/network.py](network_structure/network.py) file contains the network definition as well as parameters used for building the network: 

    batch_size #amount of images used in each iteration
    input_size #amount of pixels in the first layer of the network
    num_classes #number of classes on the output layer -> this must match the number of classes that is used to generate the tf record from the build_image_data.py script
    dropout #probability to keep the weights resulted after a train iteration
    initial_learning_rate #start value for the learning rate
    final_learning_rate #lower bound for the learning rate

The [network_structure/utils.py](network_structure/utils.py) file contains a few helper methods. The most important ones are:

| Method name            | Effect |
|------------------------|--------|
| adjust_image_for_train | performs data augmentation on images by altering the hue and saturation and by randomly flipping the image vertically and orizontally; this method converts the image to HSV and adds a new layer with the grayscale version of the input image |
| adjust_image_for_test  | converts the image to HSV and adds the grayscale channel |
