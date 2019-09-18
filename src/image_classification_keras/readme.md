This is a Keras implementation of the convolutional neural network used to classify fruits.

The implementation is written as a Jupyter Notebook, but can be easily converted to a Python script file by copying all the code in a .py file

Keras version: 2.2.5

TensorFlow version: 1.8.0 # Keras is able to work with different versions of TensorFlow, 
and even different frameworks; Currently the "image_process" method depends on TensorFlow.
If you are using a different TensorFlow version please note that the method may 
need to be updated. The method performs two colorspace changes (rgb -> hsv; rgb -> grayscale) 
and one tensor concatenation (hsv + graycale channel concatenation to obtain an input of shape 100 x 100 x 4). 
In case you want to use a different backend alltogether, the method should be rewritten.

Jupyter Notebook: 6.0.1

Python version: 3.6.7
