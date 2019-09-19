This is a Keras implementation of the convolutional neural network used to classify fruits.

The implementation is written as a Jupyter Notebook, but can be easily converted to a Python script file by copying all the code in a .py file

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
