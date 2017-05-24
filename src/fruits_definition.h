#pragma once


#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>

#include <iostream>

using namespace std;
using namespace cv;

//pomegranate_2017 05 10 17 33 10 ; OK
/*
string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\pomegranate_2017 05 10 17 33 10";
Rect r_box(760, 120, 800, 800);
#define motor_shaft_height 15
#define color_distance 5
*/

//pear_2017 02 28 10 31 28
/*
string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\pear_2017 02 28 10 31 28";
Rect r_box(745, 235, 775, 775);
#define motor_shaft_height 0
#define color_distance 1
*/

//plum1_2017 05 10 17 17 53 ; OK
/*
string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\plum1_2017 05 10 17 17 53";
Rect r_box(870, 230, 500, 500);
#define motor_shaft_height 7
#define color_distance 7
*/

//plum_rotated_1_2017 05 10 17 19 49 ; OK
/*
string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\plum_rotated_1_2017 05 10 17 19 49";
Rect r_box(890, 170, 490, 490);
#define motor_shaft_height 14
#define color_distance 7
*/

//apple1_2017 02 25 13 33 44 ; OK
/*
string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\apple1_2017 02 25 13 33 44";
Rect r_box(850, 330, 680, 680);
#define motor_shaft_height 17
#define color_distance 5
*/

//apple2_2017 02 25 13 34 34 ; OK
/*
string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\apple2_2017 02 25 13 34 34";
Rect r_box(825, 330, 730, 730);
#define motor_shaft_height 19
#define color_distance 11
*/

//apricot_2017 05 10 17 25 54; OK
/*
string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\apricot_2017 05 10 17 25 54";
Rect r_box(938, 250, 370, 370);
#define motor_shaft_height 10
#define color_distance 9
*/

//apricot_rotated_2017 05 10 17 26 17; OK
/*
string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\apricot_rotated_2017 05 10 17 26 17";
Rect r_box(950, 260, 350, 350);
#define motor_shaft_height 10
#define color_distance 9
*/

//braeburn_2017 03 05 08 34 49 ; OK
/*
string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\braeburn_2017 03 05 08 34 49";
Rect r_box(980, 400, 540, 540);
#define motor_shaft_height 18
#define color_distance 9
*/


//braeburn_rotated_2017 03 05 08 35 37 ; OK
/*
string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\braeburn_rotated_2017 03 05 08 35 37";
Rect r_box(985, 300, 520, 520);
#define motor_shaft_height 5
#define color_distance 9
*/

//golden_1_2017 02 28 10 16 25
/*
string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\golden_1_2017 02 28 10 16 25";
Rect r_box(770, 280, 420, 420);
#define motor_shaft_height 16
#define color_distance 8
*/

//golden_1_rotated_2017 02 28 10 17 00
/*
string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\golden_1_rotated_2017 02 28 10 17 00";
Rect r_box(778, 200, 405, 405);
#define motor_shaft_height 5
#define color_distance 8
*/

//golden_2_2017 02 28 10 23 44
/*
string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\golden_2_2017 02 28 10 23 44";
Rect r_box(770, 255, 455, 455);
#define motor_shaft_height 1
#define color_distance 5
*/

//golden_2_rotated_2017 02 28 10 24 36
/*
string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\golden_2_rotated_2017 02 28 10 24 36";
Rect r_box(730, 200, 515, 515);
#define motor_shaft_height 17
#define color_distance 6
*/

//golden_3_2017 03 05 08 31 35
/*
string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\golden_3_2017 03 05 08 31 35";
Rect r_box(1000, 400, 500, 500);
#define motor_shaft_height 19
#define color_distance 6
*/

//golden_3_rotated_2017 03 05 08 32 02
/*
string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\golden_3_rotated_2017 03 05 08 32 02";
Rect r_box(980, 250, 550, 550);
#define motor_shaft_height 8
#define color_distance 5
*/

//granny_smith_2017 03 05 08 36 10
/*
string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\granny_smith_2017 03 05 08 36 10";
Rect r_box(970, 300, 550, 550);
#define motor_shaft_height 7
#define color_distance 4
*/

// granny_smith_rotated_2017 03 05 08 36 39
/*
string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\granny_smith_rotated_2017 03 05 08 36 39";
Rect r_box(960, 290, 580, 580);
#define motor_shaft_height 17
#define color_distance 4
*/

//grapefruit_2017 02 28 10 33 44
/*
string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\grapefruit_2017 02 28 10 33 44";
Rect r_box(610, 200, 690, 690);
#define motor_shaft_height 10
#define color_distance 8
*/

//grapefruit_rotated_2017 02 28 10 34 43
/*
string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\grapefruit_rotated_2017 02 28 10 34 43";
Rect r_box(570, 50, 800, 800);
#define motor_shaft_height 16
#define color_distance 8
*/

//kiwi_2017 02 28 10 25 23
/*
string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\kiwi_2017 02 28 10 25 23";
Rect r_box(830, 340, 380, 380);
#define motor_shaft_height 4
#define color_distance 8
*/

//kiwi_rotated_2017 02 28 10 25 42
/*
string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\kiwi_rotated_2017 02 28 10 25 42";
Rect r_box(780, 290, 390, 390);
#define motor_shaft_height 22
#define color_distance 10
*/

//lemon_2017 02 28 10 35 34
string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\lemon_2017 02 28 10 35 34";
Rect r_box(700, 200, 550, 550);
#define motor_shaft_height 0
#define color_distance 12
