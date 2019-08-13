// Extracts fruits images from videos
// background should be uniform with small fluctuations
// color_distance constant tells how to which extent 2 background pixels can be considered similar; more is better

// authors: Mihai Oltean & Horea Muresan
// MIT license

// compiled with Visual Studio 2019 Community Edition
// requires OpenCV 4
// if you get stack overflow ... just increase the stack reserve size from Linker menu  ...

// How to use: 
// 1. Modify the fruits_definition.h file for a new fruit; r_box parameters must be modified for each fruit (see step 3)
// 2. Comment SAVE_IMAGES_TO_DISK and uncomment DISPLAY_ONLY
// 3. You must play with r_box parameters until the fruit fits inside the r_box. 
//		Also must play with motor_shaft_height_original, shaft_left and shaft_right parameters until motor shaft fits inside the white rectangle.
// 4. Uncomment SAVE_IMAGES_TO_DISK an comment DISPLAY_ONLY
// 5. Modify the color_distance if needed. If color distance is too big the object will not appear. If it is too low the margins of the object are fuzzy.


#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include "fruits_definition.h"

using namespace std;
using namespace cv;

#define VERSION "2019.08.13.0"

#define MAX_IMAGES_TO_EXTRACT 312

//---------------------------------------------------------------------

#define smaller_image_size 100 // result is stored in 100x100 matrices
#define FRUIT_PIXEL 2
#define BACKGROUND_PIXEL 1
#define NOT_MARKED_PIXEL 0

//---------------------------------------------------------------------
int get_color_distance(Vec3b &color1, Vec3b &color2)
{
	// distance between 2 colors
	int c_red = abs(color1[0] - color2[0]);
	int c_green = abs(color1[1] - color2[1]);
	int c_blue = abs(color1[2] - color2[2]);

	int max = c_red;
	if (max < c_green)
		max = c_green;
	if (max < c_blue)
		max = c_blue;

	return  max;
}
//---------------------------------------------------------------------
void flood_fill_background(int row, int col, Mat &picture, char** filled_matrix, int color_tolerance, int image_size, Vec3b &initial_color)
{
	// flood fill starting with position (row, col)
	// only 4 neighbours of the current pixel are considered
	// 2 pixels are connected if their color distance is smaller than color_tolerance value
	// picture matrix is from where the color of pixels are taken
	// the flood result is stored in matrix filled_matrix (1 if flooded, 0 otherwise)
	/*
	for (int i = 0; i < image_size; i++)
		for (int j = 0; j < image_size; j++)
			if (get_color_distance(picture->at<Vec3b>(Point(0, 0)), picture->at<Vec3b>(Point(i, j))) <= color_tolerance) {
				filled_matrix[i][j] = BACKGROUND_PIXEL;
			}
			*/
	
	if (filled_matrix[row][col] == NOT_MARKED_PIXEL) {
		filled_matrix[row][col] = BACKGROUND_PIXEL;

		if (col + 1 < image_size && 
			get_color_distance(picture.at<Vec3b>(row, col), picture.at<Vec3b>(row, col + 1)) <= color_tolerance
			//&& get_color_distance(initial_color, picture->at<Vec3b>(Point(y + 1, x))) <= color_tolerance
			)
			flood_fill_background(row, col + 1, picture, filled_matrix, color_tolerance, image_size, initial_color);

		if (col - 1 >= 0 && get_color_distance(picture.at<Vec3b>(row, col), picture.at<Vec3b>(row, col - 1)) <= color_tolerance
			//&& get_color_distance(initial_color, picture->at<Vec3b>(Point(y - 1, x))) <= color_tolerance
			)
			flood_fill_background(row, col - 1, picture, filled_matrix, color_tolerance, image_size, initial_color);

		if (row + 1 < image_size &&
			get_color_distance(picture.at<Vec3b>(row, col), picture.at<Vec3b>(row + 1, col)) <= color_tolerance
			//&& get_color_distance(initial_color, picture->at<Vec3b>(Point(y, x + 1))) <= color_tolerance
			)
			flood_fill_background(row + 1, col, picture, filled_matrix, color_tolerance, image_size, initial_color);

		if (row - 1 >= 0 &&
			get_color_distance(picture.at<Vec3b>(row, col), picture.at<Vec3b>(row - 1, col)) <= color_tolerance
			//&& get_color_distance(initial_color, picture->at<Vec3b>(Point(y, x - 1))) <= color_tolerance
			)
			flood_fill_background(row - 1, col, picture, filled_matrix, color_tolerance, image_size, initial_color);
	}
	
}
//---------------------------------------------------------------------
void flood_fill_fruit(int row, int col, char** filled_matrix, int image_size)
// fills an island of pixels having the same value 1
{
	// only 4 neighbours are considered
	if (filled_matrix[row][col] == NOT_MARKED_PIXEL) {
		filled_matrix[row][col] = FRUIT_PIXEL;

		if (col + 1 < image_size && filled_matrix[row][col + 1] == NOT_MARKED_PIXEL)
			flood_fill_fruit(row, col + 1, filled_matrix, image_size);

		if (col - 1 >= 0 && filled_matrix[row][col - 1] == NOT_MARKED_PIXEL)
			flood_fill_fruit(row, col - 1, filled_matrix, image_size);

		if (row + 1 < image_size && filled_matrix[row + 1][col] == NOT_MARKED_PIXEL)
			flood_fill_fruit(row + 1, col, filled_matrix, image_size);

		if (row - 1 >= 0 && filled_matrix[row - 1][col] == NOT_MARKED_PIXEL)
			flood_fill_fruit(row - 1, col, filled_matrix, image_size);
	}
}
//---------------------------------------------------------------------
Rect compute_fruit_bounding_box(char** matrix, int image_size)
{// compute the bounding box of the fruit
	Rect bbox;
	// maximal bbox is :
	bbox.x = image_size - 1;
	bbox.y = image_size - 1;
	int right = 0;
	int bottom = 0;

	for (int row = 0; row < image_size; row++)
		for (int col = 0; col < image_size; col++)
			if (matrix[row][col] == FRUIT_PIXEL) {
				if (bbox.x > col)
					bbox.x = col;
				if (bbox.y > row)
					bbox.y = row;
				if (right < col)
					right = col;
				if (bottom < row)
					bottom = row;
			}
	bbox.width = right - bbox.x + 1;
	bbox.height = bottom - bbox.y + 1;
	return bbox;
}
//---------------------------------------------------------------------
bool remove_background(Mat &input_image, Mat &out_image)
{
	int image_width = input_image.cols; //smaller_image_size;
	int image_height = input_image.rows;  //smaller_image_size;
	// allocate memory
	char **matrix = new char*[image_height];
	for (int row = 0; row < image_height; row++) {
		matrix[row] = new char[image_width];
		for (int col = 0; col < image_width; col++)
			matrix[row][col] = NOT_MARKED_PIXEL; // 2 - fruit // 1- background
	}
		
	// star	point is every pixel from the border
	// top side
	for (int col = 0; col < image_width; col++)
		flood_fill_background(0, col, input_image, matrix, color_distance, image_width, input_image.at<Vec3b>(0, col));

	// left side
	for (int row = 0; row < image_height; row++)
		flood_fill_background(row, 0, input_image, matrix, color_distance, image_width, input_image.at<Vec3b>(row, 0));

	// right side
	for (int row = 0; row < image_height; row++)
		flood_fill_background(row, image_width - 1, input_image, matrix, color_distance, image_width, input_image.at<Vec3b>(row, image_width - 1));
	/*
	// try to remove the motor shaft
	for (int col = 0; col < image_width; col++)
		if (col < shaft_left || col > shaft_right)
			flood_fill_background(image_height - motor_shaft_height_original - 1, col, input_image, matrix, 1, image_width,
				input_image.at<Vec3b>(image_height - motor_shaft_height_original - 1, col)
			);
			*/
	// now I start from the center and fill the object
	// I did that because we can have multiple islands and only 1 is of interest
	flood_fill_fruit((image_height - motor_shaft_height_original) / 2, image_width / 2, matrix, image_width);
	
	// ignore everything that is below shaft
	for (int row = image_height - motor_shaft_height_original; row < image_height; row++)
		for (int col = 0; col < image_width; col++)
			matrix[row][col] = BACKGROUND_PIXEL;
			
	// find bounding box
	Rect fruit_bbox;// (0, 0, image_width - 1, image_height - 1);
	fruit_bbox = compute_fruit_bounding_box(matrix, image_width);

	// keep only the part of the image that contains the fruit
	if (fruit_bbox.width > 0 && fruit_bbox.height > 0) {
		// clone the fruit only in a temporary matrix

		//Mat fruit_clone = image(fruit_bbox).clone();
		int max_size = fruit_bbox.height;
		if (max_size < fruit_bbox.width)
			max_size = fruit_bbox.width;
		Mat fruit_clone = Mat(max_size + 5, max_size + 5, input_image.type());
		fruit_clone.setTo(Scalar(255, 255, 255));

		for (int row = 0; row < image_height; row++)
			for (int col = 0; col < image_width; col++)
				if (matrix[row][col] == FRUIT_PIXEL) // fruit
					fruit_clone.at<Vec3b>(row - fruit_bbox.y + (max_size - fruit_bbox.height) / 2, col - fruit_bbox.x + (max_size - fruit_bbox.width) / 2) = input_image.at<Vec3b>(row, col);
				

		// make the out image white
		
		out_image.setTo(Scalar(255, 255, 255));

		// replace the original matrix with the smaller image containig the fruit
		
		out_image = fruit_clone; // new_image;
		
			// delete memory
		for (int row = 0; row < image_height; row++)
			delete[] matrix[row];
		delete[] matrix;

		return true;
	}
	else {
		// delete memory
		for (int row = 0; row < image_height; row++)
			delete[] matrix[row];
		delete[] matrix;

		return false; // image is empty; no fruit detected; change parameters !
	}
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
	namedWindow("out_image", 1);
	Mat out_image;

	for (int i = 0; i < 3; i++)// skip first 3 frames
		input_video >> input_image;

	int frame_index = frame_start_index;
	while (1) {
		// take a capture from input stream
		input_video >> input_image;

		if (input_image.empty())
			break;
		// extract a submatrix (having corners stored in r_box) from the original matrix
		
		Mat smaller_image(r_box.width, r_box.height, input_image.type());
		smaller_image.setTo(Scalar(255, 255, 255));
		for (int row = 0; row < r_box.height; row++)
			for (int col = 0; col < r_box.width; col++)
				if (row + r_box.y < input_image.rows && col + r_box.x < input_image.cols)
					smaller_image.at<Vec3b>(row, col) = input_image.at<Vec3b>(row + r_box.y, col + r_box.x);


		//smaller_image = input_image(r_box);

		// compute image file name
		string out_filename = input_file_name + "\\" + to_string(frame_index) + "_" + to_string(smaller_image_size) + ".jpg";

#ifndef DISPLAY_ONLY

		// resize
		//resize(smaller_image, smaller_image, Size(smaller_image_size, smaller_image_size));
		// remove margins
		if (remove_background(smaller_image, out_image)) {

			imshow("out_image", out_image);
			// show the results on the screen
			resize(out_image, out_image, Size(smaller_image_size, smaller_image_size));
			// resize again
//			imshow("image", smaller_image);


#ifdef SAVE_IMAGES_TO_DISK
			if (!imwrite(out_filename, out_image)) {
				printf("Cannot write image!\n");
				break;
			}
#endif
			frame_index++;
			if (frame_index >= MAX_IMAGES_TO_EXTRACT + frame_start_index) // keep only the first 328 images
				break;
		}
#endif		
#ifdef SAVE_IMAGES_TO_DISK
		if (!imwrite(out_filename, out_image)) {
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
	destroyWindow("out_image");

	return 0;
}
//---------------------------------------------------------------------