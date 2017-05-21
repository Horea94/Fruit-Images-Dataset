// Extracts fruits images from videos

// authors: Mihai Oltean & Horea Muresan
// MIT license

// compiled with Visual Studio 2015 Community Edition
// if you get stack overflow ... just increase the stack reserve size from menu Linker ...

#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
using namespace cv;

#define color_distance 5

#define smaller_image_size 100

string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\pomegranate_2017 05 10 17 33 10";

Rect r_box(760, 120, 800, 800); //pomegranate_2017 05 10 17 33 10

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
void remove_background(Mat &image)
{
	int image_height = image.rows;
	int image_width = image.cols;

	char **matrix = new char*[image_height];
	for (int i = 0; i < image_height; i++) {
		matrix[i] = new char[image_width];
		for (int j = 0; j < image_width; j++)
			matrix[i][j] = 0; // 2 - fruit // 1- background
	}
		
	// star	point is every pixel from the border
	for (int i = 0; i < image_width; i++)
		flood_fill(0, i, &image, matrix, color_distance);
	
	// try to remove the motor shaft
	for (int i = 0; i < image_width; i++)
		flood_fill(image_height - 15, i, &image, matrix, color_distance + 2);

	// now I start from the center and fill the object
	flood_fill2(image_width / 2, image_height / 2, matrix);
	
	for (int i = 0; i < image_width; i++)
		for (int j = 0; j < image_height; j++)
			if (matrix[i][j] != 2) {// not fruit
				image.at<Vec3b>(Point(j, i))[0] = 255; // make it WHITE
				image.at<Vec3b>(Point(j, i))[1] = 255;
				image.at<Vec3b>(Point(j, i))[2] = 255;
			}

	for (int i = 0; i < image_height; i++)
		delete[] matrix[i];
	delete[] matrix;
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

	for (int i = 0; i < 3; i++)// skip 3 frames
		input_video >> input_image;

	int frame_index = 0;
	while (1) {
		// take a capture from input stream
		input_video >> input_image;

		if (input_image.empty())
			break;

		smaller_image = input_image(r_box);

		resize(smaller_image, smaller_image, Size(smaller_image_size, smaller_image_size));
		// remove margins
		remove_background(smaller_image);
		// show the results on the screen
		imshow("image", smaller_image);

		// image file name
		string out_filename = input_file_name + "\\" + to_string(frame_index) + ".jpg" ;

		if (!imwrite(out_filename, smaller_image)) {
			printf("Cannot write image!\n");
			break;
		}

		int key = waitKey(1); // key pressed
		if (key == 27) // Escape pressed ?
			break;

		frame_index++;
	}

	input_video.release();
	destroyWindow("image");

	return 0;
}
//---------------------------------------------------------------------