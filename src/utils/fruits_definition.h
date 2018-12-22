#pragma once


#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>

#include <iostream>

using namespace std;
using namespace cv;

// Rect(int x, int y, int width, int height) - OpenCV definition
// (x, y) is the top corner of the subimage boxing the fruit
// x + width <= image width
// y + height <= image heigth

#define SAVE_IMAGES_TO_DISK
//#define DISPLAY_ONLY

string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\to be processed\\chestnut_rotated2_2018 12 20 15 52 19";
Rect r_box(990, 80, 330, 330);
#define motor_shaft_height_original 40
#define motor_shaft_height_scaled 1
#define color_distance 4
#define shaft_left 160
#define shaft_right 195
#define frame_start_index 0


//string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\to be processed\\chestnut_rotated1_2018 12 20 15 51 06";
//Rect r_box(1010, 70, 330, 330);
//#define motor_shaft_height_original 43
//#define motor_shaft_height_scaled 1
//#define color_distance 4
//#define shaft_left 135
//#define shaft_right 170
//#define frame_start_index 0

//string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\to be processed\\chestnut_2018 12 20 15 47 58";
//Rect r_box(1010, 348, 330, 330);
//#define motor_shaft_height_original 133
//#define motor_shaft_height_scaled 1
//#define color_distance 3
//#define shaft_left 130
//#define shaft_right 210
//#define frame_start_index 0

//string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\to be processed\\mangostan_rotated_2018 12 20 15 55 44";
//Rect r_box(650, 148, 780, 780);
//#define motor_shaft_height_original 225
//#define motor_shaft_height_scaled 1
//#define color_distance 3
//#define shaft_left 375
//#define shaft_right 420
//#define frame_start_index 0

//string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\to be processed\\mangostan_2018 12 20 15 54 20";
//Rect r_box(710, 148, 580, 580);
//#define motor_shaft_height_original 10
//#define motor_shaft_height_scaled 1
//#define color_distance 4
//#define shaft_left 270
//#define shaft_right 310
//#define frame_start_index 0

//string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\to be processed\\banana_lady_finger_rotated2_2018 12 21 11 07 38";
//Rect r_box(610, 10, 700, 700);
//#define motor_shaft_height_original 190
//#define motor_shaft_height_scaled 1
//#define color_distance 4
//#define shaft_left 350
//#define shaft_right 382
//#define frame_start_index 0

//string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\to be processed\\banana_lady_finger_rotated1_2018 12 21 11 07 03";
//Rect r_box(540, 10, 835, 835);
//#define motor_shaft_height_original 275
//#define motor_shaft_height_scaled 1
//#define color_distance 4
//#define shaft_left 420
//#define shaft_right 480
//#define frame_start_index 0


//string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\to be processed\\banana_lady_finger_2018 12 21 11 05 42";
//Rect r_box(540, 10, 895, 895);
//#define motor_shaft_height_original 65
//#define motor_shaft_height_scaled 1
//#define color_distance 4
//#define shaft_left 432
//#define shaft_right 488
//#define frame_start_index 0


//apple4_rotated2_2018 08 19 17 52 19.avi
//string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\to be processed\\apple4_rotated2_2018 08 19 17 52 19";
//Rect r_box(890, 180, 295, 295);
//#define motor_shaft_height_original 15
//#define motor_shaft_height_scaled 1
//#define color_distance 6
//#define shaft_left 138
//#define shaft_right 168
//#define frame_start_index 0

//apple4_rotated1_2018 08 19 17 50 26.avi
//string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\to be processed\\apple4_rotated1_2018 08 19 17 50 26";
//Rect r_box(905, 200, 290, 290);
//#define motor_shaft_height_original 23
//#define motor_shaft_height_scaled 1
//#define color_distance 6
//#define shaft_left 140
//#define shaft_right 165
//#define frame_start_index 0

//apple4_2018 08 19 17 51 25.avi
//string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\to be processed\\apple4_2018 08 19 17 51 25";
//Rect r_box(878, 135, 325, 325);
//#define motor_shaft_height_original 12
//#define motor_shaft_height_scaled 1
//#define color_distance 6
//#define shaft_left 155
//#define shaft_right 180
//#define frame_start_index 0

//grape_white4_rotated_2018 08 19 17 28 34.avi
//string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\to be processed\\grape_white4_rotated_2018 08 19 17 28 34";
//Rect r_box(978, 535, 125, 125);
//#define motor_shaft_height_original 12
//#define motor_shaft_height_scaled 1
//#define color_distance 4
//#define shaft_left 39
//#define shaft_right 89
//#define frame_start_index 0

//grape_white4_2018 08 19 17 27 43.avi
//string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\to be processed\\grape_white4_2018 08 19 17 27 43";
//Rect r_box(975, 530, 130, 130);
//#define motor_shaft_height_original 14
//#define motor_shaft_height_scaled 1
//#define color_distance 6
//#define shaft_left 41
//#define shaft_right 91
//#define frame_start_index 0

//grape_white3_rotated_2018 08 19 17 46 06.avi
//string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\to be processed\\grape_white3_rotated_2018 08 19 17 46 06";
//Rect r_box(1020, 570, 90, 90);
//#define motor_shaft_height_original 3
//#define motor_shaft_height_scaled 1
//#define color_distance 6
//#define shaft_left 23
//#define shaft_right 76
//#define frame_start_index 0

// grape_white3_2018 08 19 17 46 51.avi
//string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\to be processed\\grape_white3_2018 08 19 17 46 51";
//Rect r_box(1018, 570, 100, 100);
//#define motor_shaft_height_original 12
//#define motor_shaft_height_scaled 1
//#define color_distance 6
//#define shaft_left 25
//#define shaft_right 76
//#define frame_start_index 0

//peach2_rotated2_2018 08 19 17 14 41.avi
//string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\to be processed\\peach2_rotated2_2018 08 19 17 14 41";
//Rect r_box(825, 170, 330, 330);
//#define motor_shaft_height_original 23
//#define motor_shaft_height_scaled 1
//#define color_distance 4
//#define shaft_left 160
//#define shaft_right 190
//#define frame_start_index 0

//peach2_rotated1_2018 08 19 17 13 56.avi
//string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\to be processed\\peach2_rotated1_2018 08 19 17 13 56";
//Rect r_box(815, 150, 350, 350);
//#define motor_shaft_height_original 52
//#define motor_shaft_height_scaled 1
//#define color_distance 4
//#define shaft_left 168
//#define shaft_right 195
//#define frame_start_index 0

//peach2_2018 08 19 17 13 23.avi
//string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\to be processed\\peach2_2018 08 19 17 13 23";
//Rect r_box(830, 138, 310, 310);
//#define motor_shaft_height_original 2
//#define motor_shaft_height_scaled 1
//#define color_distance 4
//#define shaft_left 155
//#define shaft_right 180
//#define frame_start_index 0

////cherry2_rotated2_2018 05 24 11 37 40.avi
//string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\cherry2_rotated2_2018 05 24 11 37 40";
//Rect r_box(650, 140, 300, 300);
//#define motor_shaft_height_original 4
//#define motor_shaft_height_scaled 1
//#define color_distance 4
//#define shaft_left 105
//#define shaft_right 175
//#define frame_start_index 0

//cherry2_rotated_2018 05 24 11 36 15.avi
//string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\cherry2_rotated_2018 05 24 11 36 15";
//Rect r_box(640, 190, 320, 320);
//#define motor_shaft_height_original 70
//#define motor_shaft_height_scaled 1
//#define color_distance 4
//#define shaft_left 110
//#define shaft_right 195
//#define frame_start_index 0


//// grape_blue2_rotated_2018 08 19 17 27 10.avi
//string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\to be processed\\grape_blue2_rotated_2018 08 19 17 27 10";
//Rect r_box(980, 530, 120, 120);
//#define motor_shaft_height_original 4
//#define motor_shaft_height_scaled 1
//#define color_distance 8
//#define shaft_left 35
//#define shaft_right 84
//#define frame_start_index 328


// grape_blue2_2018 08 19 17 26 37.avi
//string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\to be processed\\grape_blue2_2018 08 19 17 26 37";
//Rect r_box(980, 530, 120, 120);
//#define motor_shaft_height_original 5
//#define motor_shaft_height_scaled 1
//#define color_distance 8
//#define shaft_left 35
//#define shaft_right 84
//#define frame_start_index 328

//// grape_blue1_rotated_2018 08 19 17 29 52
//string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\to be processed\\grape_blue1_rotated_2018 08 19 17 29 52";
//Rect r_box(985, 550, 110, 110);
//#define motor_shaft_height_original 14
//#define motor_shaft_height_scaled 1
//#define color_distance 4
//#define shaft_left 30
//#define shaft_right 83

// grape_blue1_2018 08 19 17 29 13.avi
//string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\to be processed\\grape_blue1_2018 08 19 17 29 13";
//Rect r_box(990, 550, 100, 100);
//#define motor_shaft_height_original 5
//#define motor_shaft_height_scaled 1
//#define color_distance 8
//#define shaft_left 30
//#define shaft_right 75

//// redcurrant_rotated_2018 06 08 12 57 50.avi
//string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\to be processed\\redcurrant_rotated_2018 06 08 12 57 50";
//Rect r_box(785, 390, 115, 115);
//#define motor_shaft_height_original 9
//#define motor_shaft_height_scaled 1
//#define color_distance 10
//#define shaft_left 10
//#define shaft_right 110

// redcurrant_2018 06 08 12 56 59.avi
/*
string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\to be processed\\redcurrant_2018 06 08 12 56 59";
Rect r_box(785, 390, 115, 115);
#define motor_shaft_height_original 9
#define motor_shaft_height_scaled 1
#define color_distance 10
#define shaft_left 10
#define shaft_right 110
*/

//cucumber_2018 08 19 18 01 46.avi // not extracted correctly
/*
string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\to be processed\\cucumber_2018 08 19 18 01 46";
Rect r_box(835, 100, 420, 680);
#define motor_shaft_height_original 6
#define motor_shaft_height_scaled 1
#define color_distance 1
#define shaft_left 195
#define shaft_right 255
*/

// nut_rotated2_2018 06 16 11 55 09.avi
/*
string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\nut_rotated2_2018 06 16 11 55 09";
Rect r_box(935, 600, 165, 165);
#define motor_shaft_height_original 19
#define motor_shaft_height_scaled 1
#define color_distance 10
#define shaft_left 65
#define shaft_right 105
*/

//nut_rotated_2018 06 16 11 54 24.avi
//string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\nut_rotated_2018 06 16 11 54 24";
//Rect r_box(945, 600, 150, 150);
//#define motor_shaft_height_original 5
//#define motor_shaft_height_scaled 1
//#define color_distance 10
//#define shaft_left 55
//#define shaft_right 91

//nut_2018 06 16 11 53 06.avi
//string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\nut_2018 06 16 11 53 06";
//Rect r_box(945, 600, 150, 150);
//#define motor_shaft_height_original 4
//#define motor_shaft_height_scaled 1
//#define color_distance 10
//#define shaft_left 55
//#define shaft_right 90

////banana_lady_finger_2018 06 16 11 42 10.avi
//string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\banana_lady_finger_2018 06 16 11 42 10";
//Rect r_box(800, 200, 530, 530);
//#define motor_shaft_height_original 15
//#define motor_shaft_height_scaled 1
//#define color_distance 2
//#define shaft_left 208
//#define shaft_right 224

//cherry_wax_maroon_rotated_2018 06 17 14 01 06
//string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\cherry_wax_maroon_rotated_2018 06 17 14 01 06";
//Rect r_box(1123, 638, 108, 108);
//#define motor_shaft_height 11
//#define color_distance 5
//#define shaft_left 35
//#define shaft_right 72

////cherry_was_maroon_2018 06 17 14 00 33.avi
//string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\cherry_was_maroon_2018 06 17 14 00 33";
//Rect r_box(1125, 638, 100, 100);
//#define motor_shaft_height 4
//#define color_distance 5
//#define shaft_left 35
//#define shaft_right 72

////cherry_wax_red_rotated_2018 06 17 14 05 47.avi
//string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\cherry_wax_red_rotated_2018 06 17 14 05 47";
//Rect r_box(1118, 630, 115, 115);
//#define motor_shaft_height 10
//#define color_distance 5
//#define shaft_left 38
//#define shaft_right 78

////cherry_wax_red_2018 06 17 14 03 38.avi
//string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\cherry_wax_red_2018 06 17 14 03 38";
//Rect r_box(1120, 630, 110, 110);
//#define motor_shaft_height 5
//#define color_distance 5
//#define shaft_left 38
//#define shaft_right 75

////cherry_wax_yellow_rotated_2018 06 17 13 59 12.avi
//string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\cherry_wax_yellow_rotated_2018 06 17 13 59 12";
//Rect r_box(1125, 640, 105, 105);
//#define motor_shaft_height 10
//#define color_distance 8

////cherry_wax_yellow_2018 06 17 13 58 42.avi
//string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\cherry_wax_yellow_2018 06 17 13 58 42";
//Rect r_box(1125, 640, 100, 100);
//#define motor_shaft_height 5
//#define color_distance 13

////rambutan_rotated_2018 06 05 09 56 17.avi
//string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\rambutan_rotated_2018 06 05 09 56 17";
//Rect r_box(700, 300, 780, 780);
//#define motor_shaft_height 18
//#define color_distance 20


////rambutan_2018 06 05 09 55 23.avi
//string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\rambutan_2018 06 05 09 55 23";
//Rect r_box(700, 400, 680, 680);
//#define motor_shaft_height 12
//#define color_distance 15

////physalis_with_husk_rotated_2018 06 05 09 50 34.avi
//string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\physalis_with_husk_rotated_2018 06 05 09 50 34";
//Rect r_box(500, 10, 800, 800);
//#define motor_shaft_height 27
//#define color_distance 10

////physalis_with_husk_2018 06 05 09 48 48.avi
//string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\physalis_with_husk_2018 06 05 09 48 48";
//Rect r_box(650, 10, 600, 600);
//#define motor_shaft_height 2
//#define color_distance 10


////physalis_rotated_2018 06 05 09 47 14.avi
//string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\physalis_rotated_2018 06 05 09 47 14";
//Rect r_box(790, 300, 260, 260);
//#define motor_shaft_height 2
//#define color_distance 8

////physalis_2018 06 05 09 45 49.avi
//string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\physalis_2018 06 05 09 45 49";
//Rect r_box(790, 300, 260, 260);
//#define motor_shaft_height 3
//#define color_distance 8


////mulberry_rotated_2018 06 08 13 27 59.avi
//string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\mulberry_rotated_2018 06 08 13 27 59";
//Rect r_box(705, 280, 265, 265);
//#define motor_shaft_height 15
//#define color_distance 0

////mulberry_2018 06 08 13 27 30.avi
//string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\mulberry_2018 06 08 13 27 30";
//Rect r_box(730, 250, 250, 250);
//#define motor_shaft_height 1
//#define color_distance 10


////strawberry-wedge_rotated2_2018 05 24 13 49 41.avi
//string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\strawberry-wedge_rotated2_2018 05 24 13 49 41";
//Rect r_box(730, 190, 620, 620);
//#define motor_shaft_height 12
//#define color_distance 20

////strawberry-wedge_rotated_2018 05 24 13 49 13.avi
//string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\strawberry-wedge_rotated_2018 05 24 13 49 13";
//Rect r_box(750, 190, 580, 580);
//#define motor_shaft_height 2
//#define color_distance 17

//////strawberry-wedge_2018 05 24 13 48 40.avi
//string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\strawberry-wedge_2018 05 24 13 48 40";
//Rect r_box(710, 210, 670, 670);
//#define motor_shaft_height 12
//#define color_distance 17


////pineapple_mini_2018 06 05 10 24 26.avi
//string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\pineapple_mini_2018 06 05 10 24 26";
//Rect r_box(550, 200, 710, 710);
//#define motor_shaft_height 3
//#define color_distance 20

////pineapple_mini_rotated_2018 06 05 10 26 45.avi
//string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\pineapple_mini_rotated_2018 06 05 10 26 45";
//Rect r_box(150, 120, 960, 960);
//#define motor_shaft_height 30
//#define color_distance 12

////pineapple_mini_2018 06 05 09 59 18.avi
//string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\pineapple_mini_2018 06 05 09 59 18";
//Rect r_box(500, 120, 960, 960);
//#define motor_shaft_height 4
//#define color_distance 12

////melon_piel_de_sapo_rotated2_2018 05 31 09 28 23.avi
//string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\melon_piel_de_sapo_rotated2_2018 05 31 09 28 23";
//Rect r_box(600, 0, 1020, 1020);
//#define motor_shaft_height 16
//#define color_distance 22

////melon_piel_de_sapo_2018 05 31 09 35 00.avi
//string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\melon_piel_de_sapo_2018 05 31 09 35 00";
//Rect r_box(680, 250, 750, 750);
//#define motor_shaft_height 7
//#define color_distance 14

////melon_piel_de_sapo_rotated_2018 05 31 09 17 53.avi
//string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\melon_piel_de_sapo_rotated_2018 05 31 09 17 53";
//Rect r_box(580, 10, 1050, 1050);
//#define motor_shaft_height 32
//#define color_distance 14

////cantaloupe2_rotated_2018 05 26 10 32 38.avi
//string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\cantaloupe2_rotated_2018 05 26 10 32 38";
//Rect r_box(970, 85, 855, 855);
//#define motor_shaft_height 21
//#define color_distance 11

////cantaloupe2_2018 05 26 10 17 32.avi
//string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\cantaloupe2_2018 05 26 10 17 32";
//Rect r_box(1100, 280, 770, 770);
//#define motor_shaft_height 2
//#define color_distance 11

////cantaloupe_rotated_2018 05 26 10 04 18.avi
//string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\cantaloupe_rotated_2018 05 26 10 04 18";
//Rect r_box(1150, 110, 700, 700);
//#define motor_shaft_height 7
//#define color_distance 15

////cantaloupe_2018 05 26 09 56 21.avi
//string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\cantaloupe_2018 05 26 09 56 21";
//Rect r_box(1130, 110, 730, 730);
//#define motor_shaft_height 10
//#define color_distance 15

////cherry_rainier_rotated2_2018 05 24 12 27 10.avi
//string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\cherry_rainier_rotated2_2018 05 24 12 27 10";
//Rect r_box(1010, 410, 340, 340);
//#define motor_shaft_height 4
//#define color_distance 7

////cherry_rainier_rotated_2018 05 24 12 26 38.avi
//string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\cherry_rainier_rotated_2018 05 24 12 26 38";
//Rect r_box(995, 400, 360, 360);
//#define motor_shaft_height 5
//#define color_distance 8

////cherry_rainier_2018 05 24 12 29 07.avi
//string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\cherry_rainier_2018 05 24 12 29 07";
//Rect r_box(990, 400, 380, 380);
//#define motor_shaft_height 10
//#define color_distance 8

////cherry2_2018 05 24 11 37 09.avi
//string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\cherry2_2018 05 24 11 37 09";
//Rect r_box(635, 150, 320, 320);
//#define motor_shaft_height 9
//#define color_distance 7


//cherry2_rotated_2018 05 24 11 36 15.avi
//string input_file_name = "c:\\Mihai\\Dropbox\\cherry2_rotated_2018 05 24 11 36 15";
//Rect r_box(640, 190, 320, 320);
//#define motor_shaft_height 21
//#define color_distance 9

////cantaloupe_2018 05 24 11 48 18
//string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\cantaloupe_2018 05 24 11 48 18";
//Rect r_box(890, 350, 730, 730);
//#define motor_shaft_height 15
//#define color_distance 9

////pomegranate_rotated_2018 05 22 18 07 35.avi
//string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\pomegranate_rotated_2018 05 22 18 07 35";
//Rect r_box(920, 190, 560, 560);
//#define motor_shaft_height 23
//#define color_distance 12

////lemon_rotated_2018 05 22 17 33 25.avi
//string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\lemon_rotated_2018 05 22 17 33 25";
//Rect r_box(960, 95, 540, 540);
//#define motor_shaft_height 28
//#define color_distance 16


//pear_williams_rotated_2018 02 07 14 33 35.avi
//string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\pear_williams_rotated_2018 02 07 14 33 35";
//Rect r_box(730, 190, 780, 780);
//#define motor_shaft_height 22
//#define color_distance 12

////pear_williams_2018 02 07 14 31 03
//string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\pear_williams_2018 02 07 14 31 03";
//Rect r_box(560, 190, 750, 750);
//#define motor_shaft_height 1
//#define color_distance 9

//pear_abate_rotated_2018 02 07 14 35 57
//string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\pear_abate_rotated_2018 02 07 14 35 57";
//Rect r_box(760, 30, 1050, 1050);
//#define motor_shaft_height 19
//#define color_distance 15

////pear_abate_2018 02 07 14 34 45.avi
//string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\pear_abate_2018 02 07 14 34 45";
//Rect r_box(950, 195, 780, 780);
//#define motor_shaft_height 2
//#define color_distance 15

////banana_red_rotated_2018 02 07 15 50 22.avi
//string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\banana_red_rotated_2018 02 07 15 50 22";
//Rect r_box(750, 200, 840, 840);
//#define motor_shaft_height 37
//#define color_distance 15

//banana_red_2018 02 07 14 40 22.avi
//string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\banana_red_2018 02 07 14 40 22";
//Rect r_box(780, 180, 900, 900);
//#define motor_shaft_height 23
//#define color_distance 14


//pitahaya_red_rotated_2018 02 07 14 44 20.avi
//string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\pitahaya_red_rotated_2018 02 07 14 44 20";
//Rect r_box(910, 400, 650, 650);
//#define motor_shaft_height 25
//#define color_distance 13

////pitahaya_2018 02 07 14 43 40.avi
//string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\pitahaya_2018 02 07 14 43 40";
//Rect r_box(940, 400, 570, 570);
//#define motor_shaft_height 1
//#define color_distance 13


////pepino_rotated_2018 02 07 14 47 21.avi
//string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\pepino_rotated_2018 02 07 14 47 21";
//Rect r_box(940, 380, 590, 590);
//#define motor_shaft_height 21
//#define color_distance 8


//pepino_2018 02 07 14 45 39.avi
//string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\pepino_2018 02 07 14 45 39";
//Rect r_box(990, 280, 550, 550);
//#define motor_shaft_height 2
//#define color_distance 7

//grape_white2_rotated_2018 02 05 12 56 47
//string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\grape_white2_rotated_2018 02 05 12 56 47";
//Rect r_box(1092, 500, 210, 210);
//#define motor_shaft_height 9
//#define color_distance 7

//grape_white2_2018 02 05 12 57 12.avi
//string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\grape_white2_2018 02 05 12 57 12";
//Rect r_box(1095, 500, 200, 200);
//#define motor_shaft_height 6
//#define color_distance 7

//lemon_meyer_2018 02 05 12 58 07.avi
//string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\lemon_meyer_2018 02 05 12 58 07";
//Rect r_box(920, 130, 570, 570);
//#define motor_shaft_height 1
//#define color_distance 15

//lemon_meyer_rotated_2018 02 05 12 58 44.avi
//string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\lemon_meyer_rotated_2018 02 05 12 58 44";
//Rect r_box(920, 140, 590, 590);
//#define motor_shaft_height 14
//#define color_distance 15

//guava_rotated_2018 02 05 13 02 23.avi
//string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\guava_rotated_2018 02 05 13 02 23";
//Rect r_box(870, 40, 760, 760);
//#define motor_shaft_height 14
//#define color_distance 15


//guava_2018 02 05 13 01 24.avi
//string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\guava_2018 02 05 13 01 24";
//Rect r_box(930, 40, 670, 670);
//#define motor_shaft_height 2
//#define color_distance 15

//pomelo_2018 01 26 15 00 58.avi
//string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\pomelo_2018 01 26 15 00 58";
//Rect r_box(1000, 300, 720, 720);
//#define motor_shaft_height 23
//#define color_distance 9

//tamarillo_rotated_2018 01 26 14 54 07.avi
//string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\tamarillo_rotated_2018 01 26 14 54 07";
//Rect r_box(570, 10, 560, 560);
//#define motor_shaft_height 18
//#define color_distance 5

//tamarillo_2018 01 26 14 56 17.avi
//string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\tamarillo_2018 01 26 14 56 17";
//Rect r_box(650, 30, 590, 590);
//#define motor_shaft_height 2
//#define color_distance 10

//maracuja_rotated_2018 01 26 14 49 36
//string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\maracuja_rotated_2018 01 26 14 49 36";
//Rect r_box(500, 90, 990, 990);
//#define motor_shaft_height 9
//#define color_distance 10

//maracuja_2018 01 26 14 47 21
//string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\maracuja_2018 01 26 14 47 21";
//Rect r_box(500, 220, 860, 860);
//#define motor_shaft_height 5
//#define color_distance 8

//dates_rotated_2018 01 26 14 40 58
//string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\dates_rotated_2018 01 26 14 40 58";
//Rect r_box(600, 195, 440, 440);
//#define motor_shaft_height 1
//#define color_distance 20

//dates_rotated_2018 01 26 14 40 58
//string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\dates_rotated_2018 01 26 14 40 58";
//Rect r_box(600, 195, 440, 440);
//#define motor_shaft_height 1
//#define color_distance 20

//dates_2018 01 26 14 26 25.avi
//string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\dates_2018 01 26 14 26 25";
//Rect r_box(800, 98, 540, 540);
//#define motor_shaft_height 40
//#define color_distance 20


//salak_rotated_2018 01 26 14 40 03.avi
/*
string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\salak_rotated_2018 01 26 14 40 03";
Rect r_box(500, 98, 580, 580);
#define motor_shaft_height 1
#define color_distance 15
*/

//salak_2018 01 26 14 23 35.avi
/*
string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\salak_2018 01 26 14 23 35";
Rect r_box(860, 10, 680, 680);
#define motor_shaft_height 43
#define color_distance 15
*/

//cranberry_rotated_2018 01 19 10 43 08
/*
string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\cranberry_rotated_2018 01 19 10 43 08";
Rect r_box(600, 200, 220, 220);
#define motor_shaft_height 2
#define color_distance 12
*/

//cranberry_2018 01 19 10 42 43

//string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\cranberry_2018 01 19 10 42 43";
//Rect r_box(590, 200, 240, 240);
//#define motor_shaft_height 9
//#define color_distance 12

//raspberry_rotated_2018 01 19 10 39 35

//string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\raspberry_rotated_2018 01 19 10 39 35";
//Rect r_box(490, 100, 440, 440);
//#define motor_shaft_height 26
//#define color_distance 20

//raspberry_2018 01 19 10 32 53

//string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\raspberry_2018 01 19 10 32 53";
//Rect r_box(520, 50, 370, 370);
//#define motor_shaft_height 0
//#define color_distance 20

//grapefruit_pink_rotated_2018 01 14 11 08 13
/*
string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\grapefruit_pink_rotated_2018 01 14 11 08 13";
Rect r_box(630, 100, 710, 710);
#define motor_shaft_height 6
#define color_distance 15
*/

//grapefruit_pink_2018 01 14 11 06 04.avi
/*
string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\grapefruit_pink_2018 01 14 11 06 04";
Rect r_box(770, 100, 830, 830);
#define motor_shaft_height 20
#define color_distance 15
*/

//tangelo_rotated_2018 01 14 11 18 39
/*
string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\tangelo_rotated_2018 01 14 11 18 39";
Rect r_box(600, 150, 750, 750);
#define motor_shaft_height 18
#define color_distance 20
*/

//tangelo_2018 01 14 11 17 07
/*
string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\tangelo_2018 01 14 11 17 07";
Rect r_box(650, 180, 690, 690);
#define motor_shaft_height 1
#define color_distance 15
*/
//mandarine_rotated_2018 01 14 11 19 53
/*
string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\mandarine_rotated_2018 01 14 11 19 53";
Rect r_box(650, 200, 670, 670);
#define motor_shaft_height 2
#define color_distance 25
*/
//mandarine_2018 01 14 11 19 19
/*
string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\mandarine_2018 01 14 11 19 19";
Rect r_box(650, 300, 660, 660);
#define motor_shaft_height 18
#define color_distance 25
*/
//banana_rotated_2018 01 14 12 16 03
/*
string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\banana_rotated_2018 01 14 12 16 03";
Rect r_box(970, 100, 950, 950);
#define motor_shaft_height 32
#define color_distance 13
*/

//banana_2018 01 14 12 00 48
/*
string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\banana_2018 01 14 12 00 48";
Rect r_box(970, 100, 950, 950);
#define motor_shaft_height 32
#define color_distance 13
*/

//pineapple_rotated_2018 01 14 11 44 51
/*
string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\pineapple_rotated_2018 01 14 11 44 51";
Rect r_box(1050, 220, 750, 750);
#define motor_shaft_height 20
#define color_distance 6
*/
//pineapple_2018 01 14 11 46 09.avi
/*
string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\pineapple_2018 01 14 11 46 09";
Rect r_box(1100, 120, 650, 650);
#define motor_shaft_height 1
#define color_distance 5
*/

//apple_red_delicios_rotated_2017 12 30 13 23 09
/*
string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\apple_red_delicios_rotated_2017 12 30 13 23 09";
Rect r_box(430, 10, 700, 700);
#define motor_shaft_height 14
#define color_distance 15
*/

//apple_red_delicios_2017 12 30 13 21 29
/*
string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\apple_red_delicios_2017 12 30 13 21 29";
Rect r_box(430, 50, 700, 700);
#define motor_shaft_height 12
#define color_distance 15
*/

//pear_monster_rotated_2017 12 30 13 25 33.avi
/*
string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\pear_monster_rotated_2017 12 30 13 25 33";
Rect r_box(650, 90, 900, 900);
#define motor_shaft_height 25
#define color_distance 10
*/

//pear_monster_2017 12 30 13 24 34
/*
string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\pear_monster_2017 12 30 13 24 34";
Rect r_box(770, 90, 700, 700);
#define motor_shaft_height 1
#define color_distance 10
*/

//grape_white_rotated_2017 12 30 13 28 18.avi
/*
string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\grape_white_rotated_2017 12 30 13 28 18";
Rect r_box(800, 290, 420, 420);
#define motor_shaft_height 11
#define color_distance 10
*/

//grape_white_2017 12 30 13 27 27.avi
/*
string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\grape_white_2017 12 30 13 27 27";
Rect r_box(835, 290, 370, 370);
#define motor_shaft_height 1
#define color_distance 10
*/


//limes_rotated_2017 12 29 11 51 55
/*
string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\limes_rotated_2017 12 29 11 51 55";
Rect r_box(720, 190, 725, 725);
#define motor_shaft_height 10
#define color_distance 20
*/
//limes_2017 12 29 11 51 20.avi
/*
string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\limes_2017 12 29 11 51 20";
Rect r_box(780, 160, 620, 620);
#define motor_shaft_height 1
#define color_distance 20
// bounding box = [53, 52, 52] (mm)
*/

//clementine_rotated_2017 12 25 15 41 44
/*
string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\clementine_rotated_2017 12 25 15 41 44";
Rect r_box(810, 280, 450, 450);
#define motor_shaft_height 5
#define color_distance 15
*/

//clementine_2017 12 29 11 37 44
/*
string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\clementine_2017 12 29 11 37 44";
Rect r_box(850, 280, 400, 400);
#define motor_shaft_height 4
#define color_distance 20
// bounding box = [38, 47, 47] (mm)
*/

//litchi_rotated_2017 12 29 11 47 44
/*
string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\litchi_rotated_2017 12 29 11 47 44";
Rect r_box(840, 250, 470, 470);
#define motor_shaft_height 15
#define color_distance 20
*/

//litchi_2017 12 29 11 47 07.avi
/*
string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\litchi_2017 12 29 11 47 07";
Rect r_box(870, 250, 420, 420);
#define motor_shaft_height 5
#define color_distance 20
*/
// bounding box = [37, 29, 29] (mm)


//mango_rotated_2017 12 29 11 54 26
/*
string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\mango_rotated_2017 12 29 11 54 26";
Rect r_box(610, 150, 760, 760);
#define motor_shaft_height 12
#define color_distance 20
*/

//mango_2017 12 29 11 57 02.avi
/*
string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\mango_2017 12 29 11 57 02";
Rect r_box(660, 150, 730, 730);
#define motor_shaft_height 4
#define color_distance 20
// bounding box = [107, 95, 85] (mm)
*/

//cocos_rotated_2017 12 29 12 11 06.avi
/*
string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\cocos_rotated_2017 12 29 12 11 06";
Rect r_box(790, 150, 700, 700);
#define motor_shaft_height 6
#define color_distance 30
*/
//cocos_2017 12 29 12 10 00.avi
/*
string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\cocos_2017 12 29 12 10 00";
Rect r_box(820, 150, 650, 650);
#define motor_shaft_height 2
#define color_distance 15
*/

//quince_rotated_2017 12 25 15 25 27
/*
string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\quince_rotated_2017 12 25 15 25 27";
Rect r_box(650, 150, 870, 870);
#define motor_shaft_height 13
#define color_distance 5
*/
//quince_2017 12 25 15 24 39.avi; OK
/*
string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\quince_2017 12 25 15 24 39";
Rect r_box(630, 150, 790, 790);
#define motor_shaft_height 1
#define color_distance 13
*/

//avocado_ripe_rotated_2017 12 25 15 23 37; OK
/*
string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\avocado_ripe_rotated_2017 12 25 15 23 37";
Rect r_box(630, 260, 820, 820);
#define motor_shaft_height 12
#define color_distance 13
*/
//avocado_ripe_2017 12 25 15 22 10 // OK
/*
string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\avocado_ripe_2017 12 25 15 22 10";
Rect r_box(720, 210, 770, 770);
#define motor_shaft_height 1
#define color_distance 13
*/
//pasion_fruit_rotated_2017 12 25 15 19 07 //OK
/*
string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\pasion_fruit_rotated_2017 12 25 15 19 07";
Rect r_box(790, 520, 480, 480);
#define motor_shaft_height 17
#define color_distance 5
*/
//pasion_fruit_2017 12 25 15 18 26.avi // OK
/*
string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\pasion_fruit_2017 12 25 15 18 26";
Rect r_box(790, 640, 420, 420);
#define motor_shaft_height 1
#define color_distance 10
*/
//kiwano_2017 12 25 15 16 44.avi // NOT OK
/*
string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\kiwano_2017 12 25 15 16 44";
Rect r_box(540, 175, 720, 720);
#define motor_shaft_height 8
#define color_distance 7
*/
//kumquats_rotated_2017 12 25 15 12 30 // OK
/*
string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\kumquats_rotated_2017 12 25 15 12 30";
Rect r_box(790, 448, 270, 270);
#define motor_shaft_height 7
#define color_distance 10
*/
//kumquats_2017 12 25 15 11 42 // OK
/*
string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\kumquats_2017 12 25 15 11 42";
Rect r_box(790, 448, 265, 265);
#define motor_shaft_height 2
#define color_distance 7
*/

//kaki_rotated_2017 12 25 15 09 57 // OK
/*
string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\kaki_rotated_2017 12 25 15 09 57";
Rect r_box(540, 255, 770, 770);
#define motor_shaft_height 8
#define color_distance 7
*/
//kaki_2017 12 25 15 09 10.avi // OK
/*
string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\kaki_2017 12 25 15 09 10";
Rect r_box(500, 55, 710, 710);
#define motor_shaft_height 1
#define color_distance 9
*/
//granadilla_rotated_2017 12 25 15 04 33 // OK
/*
string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\granadilla_rotated_2017 12 25 15 04 33";
Rect r_box(473, 40, 1040, 1040);
#define motor_shaft_height 34
#define color_distance 9
*/
//granadilla_2017 12 25 15 04 03 // OK
/*
string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\granadilla_2017 12 25 15 04 03";
Rect r_box(473, 40, 1040, 1040);
#define motor_shaft_height 24
#define color_distance 8
*/
//cactus_fruit_rotated_2017 12 25 14 57 27 // OK (does not fit in the picture) ... must recapture with wider 
/*
string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\cactus_fruit_rotated_2017 12 25 14 57 27";
Rect r_box(673, 40, 1040, 1040);
#define motor_shaft_height 23
#define color_distance 5
*/
//cactus_fruit_2017 12 25 14 56 38 // OK

/*
string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\cactus_fruit_2017 12 25 14 56 38";
Rect r_box(770, 135, 800, 800);
#define motor_shaft_height 1
#define color_distance 12
*/

//carambula_rotated_2017 12 25 14 54 15.avi ; OK
/*
string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\carambula_rotated_2017 12 25 14 54 15";
Rect r_box(570, 35, 930, 930);
#define motor_shaft_height 22
#define color_distance 10
*/
//carambula 2017 12 25 13 25 28 ; OK
/*
string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\carambula 2017 12 25 13 25 28";
Rect r_box(430, 35, 870, 870);
#define motor_shaft_height 4
#define color_distance 7
*/
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
/*
string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\papaya_rotated_2017 05 27 13 03 49";
Rect r_box(890, 230, 745, 745);
#define motor_shaft_height 23
#define color_distance 8
*/


//pear_long_2017 02 28 10 31 28
/*
string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\pear_long_2017 02 28 10 31 28";
Rect r_box(745, 200, 805, 805);
#define motor_shaft_height 0
#define color_distance 3
*/