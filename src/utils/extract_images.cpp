// Extracts fruits images from videos
// background should be uniform with small fluctuations
// color_distance constant tells how to which extent 2 background pixels can be considered similar; more is better

// authors: Mihai Oltean & Horea Muresan
// MIT license

// compiled with Visual Studio 2017 Community Edition
// requires OpenCV 4
// if you get stack overflow ... just increase the stack reserve size from Linker menu  ...

// How to use: 
// 1. modify the fruits_definition.h file for a new fruit; r_box parameters must be modified for each fruit (see step 3)
// 2. comment SAVE_IMAGES_TO_DISK and uncomment DISPLAY_ONLY
// 3. you must play with r_box parameters until the fruit fits inside the r_box
// 4. uncomment SAVE_IMAGES_TO_DISK an comment DISPLAY_ONLY
// 5. modify the motor_shaft_height and color_distance if needed


#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include "fruits_definition.h"

using namespace std;
using namespace cv;

#define VERSION "2018.12.06.0"

//---------------------------------------------------------------------
struct t_bounding_box { // rectangular bounding box
	Point min, max;
	t_bounding_box(int min_x, int min_y, int max_x, int max_y) {
		min.x = min_x;
		min.y = min_y;
		max.x = max_x;
		max.y = max_y;
	}
	t_bounding_box() {
		min.x = min.y = max.x = max.y = 0;
	}
};
//---------------------------------------------------------------------

#define smaller_image_size 100 // result is stored in 100x100 matrices
#define FRUIT_PIXEL 2
#define BACKGROUND_PIXEL 1
#define NOT_MARKED_PIXEL 0

//---------------------------------------------------------------------
int get_color_distance(Vec3b &color1, Vec3b &color2)
{
	// distance between 2 colors
	int c0 = abs(color1[0] - color2[0]);
	int c1 = abs(color1[1] - color2[1]);
	int c2 = abs(color1[2] - color2[2]);

	int max = c0;
	if (max < c1)
		max = c1;
	if (max < c2)
		max = c2;

	return  max;
}
//---------------------------------------------------------------------
void flood_fill_background(int x, int y, Mat *picture, char** filled_matrix, int color_tolerance, int image_size)
{
	// flood fill starting with position (x,y)
	// only 4 neighbours of the current pixel are considered
	// 2 pixels are connected if their color distance is smaller than color_tolerance value
	// picture matrix is from where the color of pixels are taken
	// the flood result is stored in matrix filled_matrix (1 if flooded, 0 otherwise)
	if (filled_matrix[x][y] == NOT_MARKED_PIXEL) {
		filled_matrix[x][y] = BACKGROUND_PIXEL;

		if (y + 1 < image_size && get_color_distance(picture->at<Vec3b>(Point(y, x)), picture->at<Vec3b>(Point(y + 1, x))) <= color_tolerance)
			flood_fill_background(x, y + 1, picture, filled_matrix, color_tolerance, image_size);

		if (y - 1 >= 0 && get_color_distance(picture->at<Vec3b>(Point(y, x)), picture->at<Vec3b>(Point(y - 1, x))) <= color_tolerance)
			flood_fill_background(x, y - 1, picture, filled_matrix, color_tolerance, image_size);

		if (x + 1 < image_size && get_color_distance(picture->at<Vec3b>(Point(y, x)), picture->at<Vec3b>(Point(y, x + 1))) <= color_tolerance)
			flood_fill_background(x + 1, y, picture, filled_matrix, color_tolerance, image_size);

		if (x - 1 >= 0 && get_color_distance(picture->at<Vec3b>(Point(y, x)), picture->at<Vec3b>(Point(y, x - 1))) <= color_tolerance)
			flood_fill_background(x - 1, y, picture, filled_matrix, color_tolerance, image_size);
	}
}
//---------------------------------------------------------------------
void flood_fill_fruit(int x, int y, char** filled_matrix, int image_size)
// fills an island of pixels having the same value 1
{
	// only 4 neighbours are considered
	if (filled_matrix[x][y] == NOT_MARKED_PIXEL) {
		filled_matrix[x][y] = FRUIT_PIXEL;

		if (y + 1 < image_size && filled_matrix[x][y + 1] == NOT_MARKED_PIXEL)
			flood_fill_fruit(x, y + 1, filled_matrix, image_size);

		if (y - 1 >= 0 && filled_matrix[x][y - 1] == NOT_MARKED_PIXEL)
			flood_fill_fruit(x, y - 1, filled_matrix, image_size);

		if (x + 1 < image_size && filled_matrix[x + 1][y] == NOT_MARKED_PIXEL)
			flood_fill_fruit(x + 1, y, filled_matrix, image_size);

		if (x - 1 >= 0 && filled_matrix[x - 1][y] == NOT_MARKED_PIXEL)
			flood_fill_fruit(x - 1, y, filled_matrix, image_size);
	}
}
//---------------------------------------------------------------------
t_bounding_box compute_fruit_bounding_box(char** matrix, int image_size)
{// compute the bounding box of the fruit
	t_bounding_box bbox;
	// maximal bbox is :
	bbox.min.x = image_size - 1;
	bbox.min.y = image_size - 1;
	bbox.max.x = 0;
	bbox.max.y = 0;

	for (int i = 0; i < image_size; i++)
		for (int j = 0; j < image_size; j++)
			if (matrix[i][j] == FRUIT_PIXEL) {
				if (bbox.min.x > i)
					bbox.min.x = i;
				if (bbox.min.y > j)
					bbox.min.y = j;
				if (bbox.max.x < i)
					bbox.max.x = i;
				if (bbox.max.y < j)
					bbox.max.y = j;
			}
	return bbox;
}
//---------------------------------------------------------------------
bool remove_background(Mat &image)
{
	int image_width = image.cols; //smaller_image_size;
	int image_height = image.rows;  //smaller_image_size;
	// allocate memory
	char **matrix = new char*[image_height];
	for (int i = 0; i < image_height; i++) {
		matrix[i] = new char[image_width];
		for (int j = 0; j < image_width; j++)
			matrix[i][j] = NOT_MARKED_PIXEL; // 2 - fruit // 1- background
	}
		
	// star	point is every pixel from the border
	// top side
	for (int i = 0; i < image_width; i++)
		flood_fill_background(0, i, &image, matrix, color_distance, image_width);

	// left side
	for (int i = 0; i < image_height; i++)
		flood_fill_background(i, 0, &image, matrix, color_distance, image_width);

	// right side
	for (int i = 0; i < image_height; i++)
		flood_fill_background(i, image_width - 1, &image, matrix, color_distance, image_width);

	// try to remove the motor shaft
	for (int i = 0; i < image_width; i++)
		if (i < shaft_left || i > shaft_right)
		flood_fill_background(image_height - motor_shaft_height_original - 1, i, &image, matrix, 1, image_width);

	// now I start from the center and fill the object
	// I did that because we can have multiple islands and only 1 is of interest
	flood_fill_fruit(image_height - motor_shaft_height_original - 30, image_width / 2, matrix, image_width);
	
	// ignore everything that is below shaft
	for (int i = image_height - motor_shaft_height_original; i < image_height; i++)
		for (int j = 0; j < image_width; j++)
			matrix[i][j] = BACKGROUND_PIXEL;

	// find bounding box
	t_bounding_box fruit_bbox(0, 0, image_width - 1, image_height - 1);
	fruit_bbox = compute_fruit_bounding_box(matrix, image_width);
	
	// now apply the mask and make bakground white
	for (int i = 0; i < image_height; i++)
		for (int j = 0; j < image_width; j++)
			if (matrix[i][j] != FRUIT_PIXEL) {// not fruit
				image.at<Vec3b>(Point(j, i))[0] = 255; // make it WHITE
				image.at<Vec3b>(Point(j, i))[1] = 255;
				image.at<Vec3b>(Point(j, i))[2] = 255;
			}
	// fill with WHITE everything below shaft position
	for (int i = image_height - motor_shaft_height_original; i < image_height; i++)
		for (int j = 0; j < image_width; j++){
				image.at<Vec3b>(Point(j, i))[0] = 255; // make it WHITE
				image.at<Vec3b>(Point(j, i))[1] = 255;
				image.at<Vec3b>(Point(j, i))[2] = 255;
			}
			
	// delete memory
	for (int i = 0; i < image_height; i++)
		delete[] matrix[i];
	delete[] matrix;
	
	// keep only the part of the image that contains the fruit
	if ((fruit_bbox.min.x < fruit_bbox.max.x) && (fruit_bbox.min.y < fruit_bbox.max.y)) {
		// clone the fruit only in a temporary matrix
		
		cv::Mat tmp = image(cv::Rect(fruit_bbox.min.y, fruit_bbox.min.x, fruit_bbox.max.y - fruit_bbox.min.y + 1, fruit_bbox.max.x - fruit_bbox.min.x + 1)).clone();
		// make the original image white
		image.setTo(Scalar(255, 255, 255));

		int max_size = fruit_bbox.max.y - fruit_bbox.min.y + 1;
		if (max_size < fruit_bbox.max.x - fruit_bbox.min.x + 1)
			max_size = fruit_bbox.max.x - fruit_bbox.min.x + 1;

		// create a new matrix whose size is exactly as the bounding box of the fruit
		Mat tmp_new = Mat(max_size, max_size, image.type());
		tmp_new.setTo(Scalar(255, 255, 255)); // make everything white, otherwise is grey
		// copy from tmp to tmp_new
		tmp.copyTo(tmp_new(cv::Rect((max_size - (fruit_bbox.max.y - fruit_bbox.min.y + 1)) / 2, (max_size - (fruit_bbox.max.x - fruit_bbox.min.x + 1)) / 2, fruit_bbox.max.y - fruit_bbox.min.y + 1, fruit_bbox.max.x - fruit_bbox.min.x + 1)));
		// replace the original matrix with the smaller image containig the fruit
		image = tmp_new;
		
		return true;
	}
	else
		return false; // image is empty; no fruit detected; change parameters !
}
//---------------------------------------------------------------------
int main(void)
{
	printf("Program version = %s\n", VERSION);
	// open video
	VideoCapture input_video(input_file_name + ".avi");

	if (!input_video.isOpened()){
		printf("Could not open the input video! Press ENTER to terminate.");
		getchar();
		return -1;
	}
	// folder where to save the images
	string folderCreateCommand = "mkdir \"" + input_file_name + "\"";

	system(folderCreateCommand.c_str());

	Mat input_image;

	// create window
	namedWindow("image", 1);
	Mat smaller_image;

	for (int i = 0; i < 6; i++)// skip first 3 frames
		input_video >> input_image;

	int frame_index = frame_start_index;
	while (1) {
		// take a capture from input stream
		input_video >> input_image;

		if (input_image.empty())
			break;
		// extract a submatrix (having corners stored in r_box) from the original matrix
		
		smaller_image = input_image(r_box);

		// compute image file name
		string out_filename = input_file_name + "\\" + to_string(frame_index) + "_" + to_string(smaller_image_size) + ".jpg";

#ifndef DISPLAY_ONLY

		// resize
		//resize(smaller_image, smaller_image, Size(smaller_image_size, smaller_image_size));
		// remove margins
		if (remove_background(smaller_image)) {

			imshow("image", smaller_image);
			// show the results on the screen
			resize(smaller_image, smaller_image, Size(smaller_image_size, smaller_image_size));
			// resize again
//			imshow("image", smaller_image);


#ifdef SAVE_IMAGES_TO_DISK
			if (!imwrite(out_filename, smaller_image)) {
				printf("Cannot write image!\n");
				break;
			}
#endif
			frame_index++;
			if (frame_index >= 328 + frame_start_index) // keep only the first 328 images
				break;
		}
#endif		
#ifdef SAVE_IMAGES_TO_DISK
		if (!imwrite(out_filename, smaller_image)) {
			printf("Cannot write image!\n");
			break;
		}
#else
		// draw shaft
		rectangle(smaller_image, Rect(shaft_left, smaller_image.rows - motor_shaft_height_original, shaft_right - shaft_left, motor_shaft_height_original), Scalar(255, 255, 255));
		imshow("image", smaller_image);

#endif

		int key = waitKey(1); // key pressed
		if (key == 27) // Escape pressed ?
			break;
	}

	input_video.release();
	destroyWindow("image");

	return 0;
}
//---------------------------------------------------------------------