This is a Keras implementation of the convolutional neural network used to classify fruits.

The implementation is written as a Jupyter Notebook, but can be easily converted to a Python script file by copying all the code in a .py file

### Requirements ###

[Keras](https://keras.io/) version: 2.2.5

[TensorFlow](https://www.tensorflow.org/) version: 1.8.0 NOTE: Keras is able to work with different versions of TensorFlow, 
and even different frameworks; Currently the "image_process" method depends on TensorFlow.
he method performs two colorspace changes (rgb -> hsv; rgb -> grayscale) 
and one tensor concatenation (hsv + graycale channel concatenation to obtain an input of shape 100 x 100 x 4).
If you are using a different TensorFlow version please note that there is a slight chance that the method may 
need to be updated due to deprecation
In case you want to use a different backend alltogether, the method should be rewritten.

[Jupyter Notebook](https://jupyter.org/) version: 6.0.1

[Python](https://www.python.org/) version: 3.6.7

### Running ###

Start a command line and navigate to the Fruit-Images-Dataset/src/image_classification_keras/ folder. Start a jupyter notebook using the following command:
  
    jupyter notebook
    
This should open a browser page in which you can view the contents of the Fruit-Images-Dataset/src/image_classification_keras/ folder. If the browser tab is not automatically opened, in the command line where the jupyter notebook was started will be a log containing the URL that can be manually put in a browser. From the brower page, access the Fruits-360 CNN.ipynb file. This will open the file in a new browser tab. There, the file can be edited and run. The contents of the file are split into two cells. The first cell contains utility methods, global parameter definitions and defines the structure of the training/testing process. The second cell contains the network definition and calls the training/testing method from the first cell.

### Output ###

During the training/tsting of the model, logs will be printed to monitor the status of the process. The details of the logs depend on the value of the verbose variable:

    0 - no logs will be printed
    1 - logs will print accuracy and loss after each processed batch of images
    2 - logs will print accuracy and loss after each epoch
    
If you name the model (in this example we named the model "fruit-360 model", as can be seen in the second cell of the notebook), the code will generate several files under the output_files/model_name folders (the folders are automatically created):

    -- a graph showing the evolution of the accuracy and loss during training
    -- the confusion matrix for the model
    -- a classification report file detailing the precision, recall and F1-score per class
