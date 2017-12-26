// Extracts fruits images from videos

// authors: Mihai Oltean & Horea Muresan
// MIT license

// compiled with Visual Studio 2015 Community Edition
// if you get stack overflow ... just increase the stack reserve size from menu Linker ...

// How to use: 
// 1. modify the fruits_definition.h file for a new fruit; r_box parameters must be modified for each fruit (see step 2)
// 2. comment SAVE_IMAGES_TO_DISK and uncomment DISPLAY_ONLY
// 3. you must play with bbox parameters until the fruit fits inside the bbox
// 4. uncomment SAVE_IMAGES_TO_DISK an comment DISPLAY_ONLY
// 5. modify the motor_shaft_height and color_distance if needed

#define SAVE_IMAGES_TO_DISK
//#define DISPLAY_ONLY

#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include "fruits_definition.h"

using namespace std;
using namespace cv;

struct t_bbox {
	Point min, max;
};

#define smaller_image_size 100

//---------------------------------------------------------------------
int get_color_distance(Vec3b &color1, Vec3b &color2)
{
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
void flood_fill(int x, int y, Mat *picture, char** filled_matrix, int color_tolerance)
{
	// only 4 neighbours are considered
	if (!filled_matrix[x][y]) {
		filled_matrix[x][y] = 1;

		if (y + 1 < smaller_image_size && get_color_distance(picture->at<Vec3b>(Point(y, x)), picture->at<Vec3b>(Point(y + 1, x))) <= color_tolerance)
			flood_fill(x, y + 1, picture, filled_matrix, color_tolerance);

		if (y - 1 >= 0 && get_color_distance(picture->at<Vec3b>(Point(y, x)), picture->at<Vec3b>(Point(y - 1, x))) <= color_tolerance)
			flood_fill(x, y - 1, picture, filled_matrix, color_tolerance);

		if (x + 1 < smaller_image_size && get_color_distance(picture->at<Vec3b>(Point(y, x)), picture->at<Vec3b>(Point(y, x + 1))) <= color_tolerance)
			flood_fill(x + 1, y, picture, filled_matrix, color_tolerance);

		if (x - 1 >= 0 && get_color_distance(picture->at<Vec3b>(Point(y, x)), picture->at<Vec3b>(Point(y, x - 1))) <= color_tolerance)
			flood_fill(x - 1, y, picture, filled_matrix, color_tolerance);
	}
}
//---------------------------------------------------------------------
void flood_fill2(int x, int y, char** filled_matrix)
// fills an island of pixels having the same value 1
{
	// only 4 neighbours are considered
	if (filled_matrix[x][y] == 0) {
		filled_matrix[x][y] = 2;

		if (y + 1 < smaller_image_size && !filled_matrix[x][y + 1])
			flood_fill2(x, y + 1, filled_matrix);

		if (y - 1 >= 0 && !filled_matrix[x][y - 1])
			flood_fill2(x, y - 1, filled_matrix);

		if (x + 1 < smaller_image_size && !filled_matrix[x + 1][y])
			flood_fill2(x + 1, y, filled_matrix);

		if (x - 1 >= 0 && !filled_matrix[x - 1][y])
			flood_fill2(x - 1, y, filled_matrix);
	}
}
//---------------------------------------------------------------------
t_bbox compute_bbox(char** matrix)
{
	t_bbox bbox;
	// maximal bbox is :
	bbox.min.x = smaller_image_size;
	bbox.min.y = smaller_image_size;
	bbox.max.x = 0;
	bbox.max.y = 0;

	for (int i = 0; i < smaller_image_size; i++)
		for (int j = 0; j < smaller_image_size; j++)
			if (matrix[i][j] == 2) {
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
	// allocate memory
	char **matrix = new char*[smaller_image_size];
	for (int i = 0; i < smaller_image_size; i++) {
		matrix[i] = new char[smaller_image_size];
		for (int j = 0; j < smaller_image_size; j++)
			matrix[i][j] = 0; // 2 - fruit // 1- background
	}
		
	// star	point is every pixel from the border
	// top side
	for (int i = 0; i < smaller_image_size; i++)
		flood_fill(0, i, &image, matrix, color_distance);

	// left side
	for (int i = 0; i < smaller_image_size; i++)
		flood_fill(i, 0, &image, matrix, color_distance);

	// right side
	for (int i = 0; i < smaller_image_size; i++)
		flood_fill(i, smaller_image_size - 1, &image, matrix, color_distance);

	// try to remove the motor shaft
	for (int i = 0; i < smaller_image_size; i++)
		flood_fill(smaller_image_size - motor_shaft_height - 1, i, &image, matrix, 1);

	// now I start from the center and fill the object
	// I did that because we can have multiple islands and only 1 is of interest
	flood_fill2(smaller_image_size / 2, smaller_image_size / 2, matrix);
	
	// ignore everything that below shaft
	for (int i = smaller_image_size - motor_shaft_height; i < smaller_image_size; i++)
		for (int j = 0; j < smaller_image_size; j++)
			matrix[i][j] = 1;

	// find bounding box
	t_bbox bbox = compute_bbox(matrix);

	// now apply the mask and make bakground white
	for (int i = 0; i < smaller_image_size; i++)
		for (int j = 0; j < smaller_image_size; j++)
			if (matrix[i][j] != 2) {// not fruit
				image.at<Vec3b>(Point(j, i))[0] = 255; // make it WHITE
				image.at<Vec3b>(Point(j, i))[1] = 255;
				image.at<Vec3b>(Point(j, i))[2] = 255;
			}
	// fill with WHITE everything below shaft position
	for (int i = smaller_image_size - motor_shaft_height; i < smaller_image_size; i++)
		for (int j = 0; j < smaller_image_size; j++){
				image.at<Vec3b>(Point(j, i))[0] = 255; // make it WHITE
				image.at<Vec3b>(Point(j, i))[1] = 255;
				image.at<Vec3b>(Point(j, i))[2] = 255;
			}

	// delete memory
	for (int i = 0; i < smaller_image_size; i++)
		delete[] matrix[i];
	delete[] matrix;

	if ((bbox.min.x < bbox.max.x) && (bbox.min.y < bbox.max.y)) {
		// extract the fruit only
		cv::Mat tmp = image(cv::Rect(bbox.min.y, bbox.min.x, bbox.max.y - bbox.min.y + 1, bbox.max.x - bbox.min.x + 1)).clone();
		// make the existing image white
		image.setTo(Scalar(255, 255, 255));

		int max_size = bbox.max.y - bbox.min.y + 1;
		if (max_size < bbox.max.x - bbox.min.x + 1)
			max_size = bbox.max.x - bbox.min.x + 1;

		Mat tmp_new = Mat(max_size, max_size, image.type());
		tmp_new.setTo(Scalar(255, 255, 255)); // make everything white, otherwise is grey
		tmp.copyTo(tmp_new(cv::Rect((max_size - (bbox.max.y - bbox.min.y + 1)) / 2, (max_size - (bbox.max.x - bbox.min.x + 1)) / 2, bbox.max.y - bbox.min.y + 1, bbox.max.x - bbox.min.x + 1)));

		image = tmp_new;
		return true;
	}
	else
		return false; // image is empty; no fruit detected; change parameters !

}
//---------------------------------------------------------------------
int main(void)
{
	// open video
	VideoCapture input_video(input_file_name + ".avi");

	if (!input_video.isOpened())
	{
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

	for (int i = 0; i < 4; i++)// skip 3 frames
		input_video >> input_image;

	int frame_index = 0;
	while (1) {
		// take a capture from input stream
		input_video >> input_image;

		if (input_image.empty())
			break;

		smaller_image = input_image(r_box);

		// image file name
		string out_filename = input_file_name + "\\" + to_string(frame_index) + "_" + to_string(smaller_image_size) + "x" + to_string(smaller_image_size) + ".jpg";

#ifndef DISPLAY_ONLY

		// resize
		resize(smaller_image, smaller_image, Size(100, 100));
		// remove margins
		if (remove_background(smaller_image)) {
			// resize again
			resize(smaller_image, smaller_image, Size(100, 100));
			// show the results on the screen


#ifdef SAVE_IMAGES_TO_DISK
			if (!imwrite(out_filename, smaller_image)) {
				printf("Cannot write image!\n");
				break;
			}
#endif
			frame_index++;
			if (frame_index >= 328) // keep only the first 328 images
				break;
		}
#endif		

		imshow("image", smaller_image);
#ifdef SAVE_IMAGES_TO_DISK
		if (!imwrite(out_filename, smaller_image)) {
			printf("Cannot write image!\n");
			break;
		}
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