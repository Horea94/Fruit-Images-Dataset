# A dataset of images containing fruits #

We introduce a new, high-quality, dataset of images containing fruits.

## Structure ##

Folders [Training](Training) and [Validation](Validation) contain all images with white backgrounds only.

Folder [src](src) contains the C++ code used for extracting the fruits from the background. 

## How we created the dataset ##

Fruits were planted in the shaft of a low speed motor (3 rpm) and a short movie of 20 seconds was recorded. 

A Logitech C920 camera was used for filming the fruits. This is one of the best webcams.

Behind the fruits we placed a white sheet of paper as background. 

However due to the variations in the lighting conditions, the background was not uniform and we wrote a dedicated algorithm which extract the fruit from the background. This algorithm is of flood fill type: 
we start from each edge of the image and we mark all pixels there, then we mark all pixels found in the neighborhood of the already marked pixels for which the distance between colors is less than a prescribed value. We repeat the previous step until no more pixels can be marked.

All marked pixels are considered as being background (which is then filled with white) and the rest of pixels are considered as belonging to the object.

The maximum value for the distance between 2 neighbor pixels is a parameter of the algorithm and is set (by trial and error) for each movie.

## Dataset properties ##

Fruits were scaled to fit a 100x100 pixels image.

The resulted dataset used for training consists of 15506 images of fruits spread across 33 labels. The testing data is made of 5195 images.

Images associated with each fruit are placed in a separate folder.

Different varieties of the same fruit (apple for instance) are shown having different labels.

## Results ##

We have run [TensorFlow](https://github.com/tensorflow/tensorflow) on these data and the results are presented in the file from [papers](papers) folder.

## How to cite ##

Horea Muresan, [Mihai Oltean](https://mihaioltean.github.io), Fruit recognition from images using deep learning, Technical Report, Babes-Bolyai University, 2017

## History ##

Fruits were filmed at the dates given below:

2017.02.25 - Apple (golden).

2017.02.28 - Apple (red-yellow, red, golden2), Kiwi, Pear, Grapefruit, Lemon, Orange, Strawberry, Banana.

2017.03.05 - Apple (golden3, Braeburn, Granny Smith, red2).

2017.03.07 - Apple (red3).

2017.05.10 - Plum, Peach, Peach flat, Apricot, Nectarine, Pomegranate.

2017.05.27 - Avocado, Papaya, Grape, Cherrie.

2017.12.25 - Carambula, Cactus fruit, Granadilla, Kaki, Kumsquats, Passion fruit, Avocado ripe, Quince.