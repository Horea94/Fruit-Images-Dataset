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
/*
string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\lemon_2017 02 28 10 35 34";
Rect r_box(700, 200, 550, 550);
#define motor_shaft_height 0
#define color_distance 12
*/

//nectarine_2017 05 10 17 28 05
/*
string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\nectarine_2017 05 10 17 28 05";
Rect r_box(870, 200, 510, 510);
#define motor_shaft_height 15
#define color_distance 8
*/

//nectarine_rotated_2017 05 10 17 28 36
/*
string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\nectarine_rotated_2017 05 10 17 28 36";
Rect r_box(890, 160, 480, 480);
#define motor_shaft_height 10
#define color_distance 8
*/

//orange_2017 02 28 12 22 11
/*
string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\orange_2017 02 28 12 22 11";
Rect r_box(730, 320, 510, 510);
#define motor_shaft_height 8
#define color_distance 10
*/

// orange_rotated_2017 02 28 12 22 32
/*
string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\orange_rotated_2017 02 28 12 22 32";
Rect r_box(710, 120, 570, 570);
#define motor_shaft_height 12
#define color_distance 10
*/

//peach_2017 05 10 17 26 53
/*
string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\peach_2017 05 10 17 26 53";
Rect r_box(860, 200, 530, 530);
#define motor_shaft_height 18
#define color_distance 7
*/

//peach_rotated_2017 05 10 17 27 23
/*
string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\peach_rotated_2017 05 10 17 27 23";
Rect r_box(860, 160, 530, 530);
#define motor_shaft_height 9
#define color_distance 9
*/

//peach_flat_1_2017 05 10 17 21 56
/*
string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\peach_flat_1_2017 05 10 17 21 56";
Rect r_box(880, 160, 490, 490);
#define motor_shaft_height 8
#define color_distance 5
*/

//peach_flat_rotated_1_2017 05 10 17 22 20
/*
string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\peach_flat_rotated_1_2017 05 10 17 22 20";
Rect r_box(910, 170, 440, 440);
#define motor_shaft_height 2
#define color_distance 4
*/

//pear_long_2017 02 28 10 31 28
/*
string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\pear_long_2017 02 28 10 31 28";
Rect r_box(745, 235, 775, 775);
#define motor_shaft_height 0
#define color_distance 2
*/

//pear_2017 05 10 17 30 47
/*
string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\pear_2017 05 10 17 30 47";
Rect r_box(895, 145, 545, 545);
#define motor_shaft_height 0
#define color_distance 7
*/

//pear_rotated_2017 05 10 17 31 1_5
/*
string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\pear_rotated_2017 05 10 17 31 1_5";
Rect r_box(795, 145, 705, 705);
#define motor_shaft_height 26
#define color_distance 7
*/

//strawberry_2017 02 28 12 23 23
/*
string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\strawberry_2017 02 28 12 23 23";
Rect r_box(795, 275, 405, 405);
#define motor_shaft_height 2
#define color_distance 8
*/

//strawberry_rotated_2017 02 28 12 23 50
/*
string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\strawberry_rotated_2017 02 28 12 23 50";
Rect r_box(765, 275, 455, 455);
#define motor_shaft_height 24
#define color_distance 8
*/

//apple_red_1_2017 02 28 10 19 28
/*
string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\apple_red_1_2017 02 28 10 19 28";
Rect r_box(705, 105, 555, 555);
#define motor_shaft_height 13
#define color_distance 12
*/

//apple_red_1_rotated_2017 02 28 10 20 53
/*
string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\apple_red_1_rotated_2017 02 28 10 20 53";
Rect r_box(735, 275, 505, 505);
#define motor_shaft_height 13
#define color_distance 12
*/

//apple_red_2_2017 03 05 08 29 40
/*
string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\apple_red_2_2017 03 05 08 29 40";
Rect r_box(955, 395, 585, 585);
#define motor_shaft_height 22
#define color_distance 7
*/

//apple_red_2_rotated_2017 03 05 08 31 09
/*
string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\apple_red_2_rotated_2017 03 05 08 31 09";
Rect r_box(1000, 295, 495, 495);
#define motor_shaft_height 7
#define color_distance 5
*/

//apple_red_3_2017 03 07 12 08 25
/*
string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\apple_red_3_2017 03 07 12 08 25";
Rect r_box(720, 325, 605, 605);
#define motor_shaft_height 3
#define color_distance 4
*/

// apple_red_3_rotated_2017 03 07 12 10 37
/*
string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\apple_red_3_rotated_2017 03 07 12 10 37";
Rect r_box(650, 325, 745, 745);
#define motor_shaft_height 20
#define color_distance 3
*/

//apple_red_yellow_2017 02 28 10 18 13
/*
string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\apple_red_yellow_2017 02 28 10 18 13";
Rect r_box(790, 255, 380, 380);
#define motor_shaft_height 1
#define color_distance 8
*/

//apple_red_yellow_rotated_2017 02 28 10 18 35
/*
string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\apple_red_yellow_rotated_2017 02 28 10 18 35";
Rect r_box(785, 225, 390, 390);
#define motor_shaft_height 2
#define color_distance 8
*/

//avocado_2017 05 27 13 00 25
/*
string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\avocado_2017 05 27 13 00 25";
Rect r_box(685, 445, 600, 600);
#define motor_shaft_height 0
#define color_distance 10
*/

//avocado_rotated_2017 05 27 13 00 47
/*
string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\avocado_rotated_2017 05 27 13 00 47";
Rect r_box(615, 375, 700, 700);
#define motor_shaft_height 6
#define color_distance 10
*/

//cherrie_2017 05 27 13 05 29
/*
string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\cherrie_2017 05 27 13 05 29";
Rect r_box(1160, 495, 170, 170);
#define motor_shaft_height 8
#define color_distance 4
*/

//cherrie_rotated_2017 05 27 13 21 37
/*
string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\cherrie_rotated_2017 05 27 13 21 37";
Rect r_box(1160, 495, 170, 170);
#define motor_shaft_height 6
#define color_distance 5
*/

//grape_2017 05 27 13 04 18
/*
string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\grape_2017 05 27 13 04 18";
Rect r_box(1160, 495, 205, 205);
#define motor_shaft_height 1
#define color_distance 5
*/

//grape_rotated_2017 05 27 13 04 47
/*
string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\grape_rotated_2017 05 27 13 04 47";
Rect r_box(1140, 495, 215, 215);
#define motor_shaft_height 16
#define color_distance 8
*/

//papaya_2017 05 27 13 03 22
/*
string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\papaya_2017 05 27 13 03 22";
Rect r_box(890, 230, 745, 745);
#define motor_shaft_height 5
#define color_distance 8
*/

//papaya_rotated_2017 05 27 13 03 49
string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\papaya_rotated_2017 05 27 13 03 49";
Rect r_box(890, 230, 745, 745);
#define motor_shaft_height 23
#define color_distance 8