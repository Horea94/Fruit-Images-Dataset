# Fruits-360: A dataset of images containing fruits #

# Version: 2018.01.26.1 #

A high-quality, dataset of images containing fruits. The following fruits are included (as of 2018.01.19): 
Apples - (different varieties: Golden, Golden-Red, Granny Smith, Red, Red Delicious), Apricot, Avocado, Avocado ripe, Banana, Cactus fruit, Carambula, Cherry, Clementine, Cocos, Dates, Granadilla, Grape (Pink, White), Grapefruit (Pink, White), Huckleberry, Kiwi, Kaki, Kumsquats, Lemon, Lime, Litchi, Mandarine, Mango, Maracuja, Nectarine, Orange, Papaya, Passion fruit, Peach, Pear (different varieties, Monster), Pineapple, Plum, Pomegranate, Quince, Raspberry, Salak, Strawberry, Tamarillo, Tangelo.

## Structure ##

Folders [Training](Training) and [Validation](Validation) contain all images with white backgrounds only.

Folder [src](src) contains the C++ code used for extracting the fruits from the background. 

Folder [src](src) contains the C++ code used for extracting the fruits from the background. 

Folder [test-multiple_fruits](test-multiple_fruits) contains images with multiple fruits. Some of them are partially covered by other fruits. This is an excelent test for real-world detection.

## Dataset properties ##

Training set size: 24816 images.

Validation set size: 8345 images.

Number of classes: 52 (fruits).

Image size: 100x100 pixels.

Filename format: image_index_100.jpg (e.g. 32_100.jpg) or r_image_index_100.jpg (e.g. r_32_100.jpg). "r" stands for rotated fruit. "100" comes from image size (100x100 pixels).

Different varieties of the same fruit (apple for instance) are shown having different labels.

## How to cite ##

Horea Muresan, [Mihai Oltean](https://mihaioltean.github.io), Fruit recognition from images using deep learning, Technical Report, Babes-Bolyai University, 2017

## How we created the dataset ##

Fruits were planted in the shaft of a low speed motor (3 rpm) and a short movie of 20 seconds was recorded. 

A Logitech C920 camera was used for filming the fruits. This is one of the best webcams available.

Behind the fruits we placed a white sheet of paper as background. 

However due to the variations in the lighting conditions, the background was not uniform and we wrote a dedicated algorithm which extract the fruit from the background. This algorithm is of flood fill type: 
we start from each edge of the image and we mark all pixels there, then we mark all pixels found in the neighborhood of the already marked pixels for which the distance between colors is less than a prescribed value. We repeat the previous step until no more pixels can be marked.

All marked pixels are considered as being background (which is then filled with white) and the rest of pixels are considered as belonging to the object.

The maximum value for the distance between 2 neighbor pixels is a parameter of the algorithm and is set (by trial and error) for each movie.

## Results ##

We have run [TensorFlow](https://github.com/tensorflow/tensorflow) on these data and the results are presented in the file from [papers](papers) folder.

## History ##

Fruits were filmed at the dates given below:

2017.02.25 - Apple (golden).

2017.02.28 - Apple (red-yellow, red, golden2), Kiwi, Pear, Grapefruit, Lemon, Orange, Strawberry.

2017.03.05 - Apple (golden3, Braeburn, Granny Smith, red2).

2017.03.07 - Apple (red3).

2017.05.10 - Plum, Peach, Peach flat, Apricot, Nectarine, Pomegranate.

2017.05.27 - Avocado, Papaya, Grape, Cherrie.

2017.12.25 - Carambula, Cactus fruit, Granadilla, Kaki, Kumsquats, Passion fruit, Avocado ripe, Quince.

2017.12.28 - Clementine, Cocos, Mango, Lime, Litchi.

2017.12.31 - Apple Red Delicious, Pear Monster, Grape White.

2018.01.14 - Banana, Grapefruit Pink, Mandarine, Pineapple, Tangelo.

2018.01.19 - Huckleberry, Raspberry.

2018.01.26 - Dates, Maracuja, Salak, Tamarillo.