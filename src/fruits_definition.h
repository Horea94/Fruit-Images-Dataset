#pragma once


#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>

#include <iostream>

using namespace std;
using namespace cv;

//limes_rotated_2017 12 29 11 51 55

string input_file_name = "c:\\Mihai\\Dropbox\\fruits\\limes_rotated_2017 12 29 11 51 55";
Rect r_box(720, 190, 725, 725);
#define motor_shaft_height 10
#define color_distance 20

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