This is a Keras implementation of the convolutional neural network used to classify fruits.

### Requirements ###

[TensorFlow](https://www.tensorflow.org/) version: 2.2

[Jupyter Notebook](https://jupyter.org/) version: 6.0.1

[Python](https://www.python.org/) version: 3.7.6

### Running Python version ###

From the [image_classification](.) folder run:

    python "Fruits-360 CNN.py"

The script uses relative paths to determine the Training/Test image folders and the output folder.
The variables pointing to those folders can be changed in the code, if the script must be run from other places. 
### Running Jupyter version ###

Start a command line and navigate to the [image_classification](.) folder. Start a jupyter notebook using the following command:
  
    jupyter notebook
    
This should open a browser page in which you can view the contents of the Fruit-Images-Dataset/src/image_classification_keras/ folder. 
If the browser tab is not automatically opened, in the command line where the jupyter notebook was started will be a log containing the 
URL that can be manually put in a browser. From the browser page, access the Fruits-360 CNN.ipynb file. This will open the file in a new 
browser tab. There, the file can be edited and run. The contents of the file are split into two cells. The first cell contains utility methods, 
global parameter definitions and defines the structure of the training/testing process. The second cell contains the network definition and 
calls the training/testing method from the first cell.

### Output ###

During the training/teting of the model, logs will be printed to monitor the status of the process. The details of the logs depend on the value of the verbose variable:

    0 - no logs will be printed
    1 - logs will print accuracy and loss after each processed batch of images
    2 - logs will print accuracy and loss after each epoch
    
If you name the model (in this example we named the model "fruit-360 model", as can be seen in the second cell of the notebook), the code will generate several files under the output_files/model_name folders (the folders are automatically created):

    -- a graph showing the evolution of the accuracy and loss during training
    -- the confusion matrix for the model
    -- a classification report file detailing the precision, recall and F1-score per class
