//Benötigte Header
#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>
using namespace std;
//Variablen (ENGINE)
//Integers
static int player_health;
//Strings
static string player_name;
static string player_race;
static string player_position_map = "map01";
static string player_position = "room01";
static string input;
static string savegame_path = "C:\\users\\public\\MyrtanisCppRecode\\savegame.ini";
static string gameversion = "0.0.1 alpha";
//Bools
static bool north_isfree;
static bool east_isfree;
static bool west_isfree;
static bool south_isfree;

static bool event_finishedCreation;
static bool player_alive;
static bool player_hasItem_key01;
static bool dir_free_north;
static bool dir_free_west;
static bool dir_free_south;
static bool dir_free_east;
static bool event_player_name_valid = false;
static bool event_player_race_valid = false;
static bool global_debugmode = false;

//Umlaute
const unsigned char AE = static_cast<unsigned char>(142);
const unsigned char ae = static_cast<unsigned char>(132);
const unsigned char OE = static_cast<unsigned char>(153);
const unsigned char oe = static_cast<unsigned char>(148);
const unsigned char UE = static_cast<unsigned char>(154);
const unsigned char ue = static_cast<unsigned char>(129);
const unsigned char ss = static_cast<unsigned char>(225);