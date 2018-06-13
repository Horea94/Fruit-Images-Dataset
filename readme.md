# Fruits-360: A dataset of images containing fruits #

# Version: 2018.06.13.0 #

A high-quality, dataset of images containing fruits. The following fruits are included: 
Apples (different varieties: Golden, Golden-Red, Granny Smith, Red, Red Delicious), Apricot, Avocado, Avocado ripe, Banana (Yellow, Red), Cactus fruit, Cantaloupe (2 varieties), Carambula, Cherry (different varieties, Rainier), Clementine, Cocos, Dates, Granadilla, Grape (Pink, White, White2), Grapefruit (Pink, White), Guava, Huckleberry, Kiwi, Kaki, Kumsquats, Lemon (normal, Meyer), Lime, Litchi, Mandarine, Mango, Maracuja, Melon Piel de Sapo, Mulberry, Nectarine, Orange, Papaya, Passion fruit, Peach, Pepino, Pear (different varieties, Abate, Monster, Williams), Physalis (normal, with Husk), Pineapple (normal, Mini), Pitahaya Red, Plum, Pomegranate, Quince, Raspberry, Salak, Strawberry (normal, Wedge), Tamarillo, Tangelo.

## Dataset properties ##

Total number of images: 46937.

Training set size: 35133 images.

Validation set size: 11804 images.

Number of classes: 70 (fruits).

Image size: 100x100 pixels.

Filename format: image_index_100.jpg (e.g. 32_100.jpg) or r_image_index_100.jpg (e.g. r_32_100.jpg) or r2_image_index_100.jpg. "r" stands for rotated fruit. "r2" means that the fruit was rotated around the 3rd axis. "100" comes from image size (100x100 pixels).

Different varieties of the same fruit (apple for instance) are stored as belonging to different classes.

## Repository structure ##

Folders [Training](Training) and [Validation](Validation) contain all images with white backgrounds only.

Folder [test-multiple_fruits](test-multiple_fruits) contains images with multiple fruits. Some of them are partially covered by other fruits. This is an excelent test for real-world detection.

Folder [src/image_classification](src/image_classification) contains the python code for training the neural network. It uses the TensorFlow library.

Folder [src/utils](src/utils) contains the C++ code used for extracting the fruits from the background. 

## Alternate download ##

The dataset can also be downloaded from: https://www.kaggle.com/moltean/fruits

## Neural network code ##

We have implemented a convolutional network for classifying the images. See the [src/image_classification](src/image_classification) folder for more details

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

Fruits were filmed at the dates given below (YYYY.MM.DD):

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

2018.02.05 - Guava, Grape White 2, Lemon Meyer

2018.02.07 - Banana Red, Pepino, Pitahaya Red.

2018.02.08 - Pear Abate, Pear Williams.

2018.05.22 - Lemon rotated, Pomegranate rotated.

2018.05.24 - Cherry Rainier, Cherry 2, Strawberry Wedge.

2018.05.26 - Cantaloupe (2 varieties).

2018.05.31 - Melon Piel de Sapo.

2018.06.05 - Pineapple Mini, Physalis, Physalis with Husk.

2018.06.08 - Mulberry.