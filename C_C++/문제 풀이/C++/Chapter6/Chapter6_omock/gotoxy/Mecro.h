#pragma once

#include<iostream>
#include<string>
#include <string.h>
#include<conio.h>
#include<iomanip>
#include<Windows.h>
using namespace std;

#define Y 0
#define X 1
#define CURSER 2

#define ESC 27
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77




enum STARTMENU
{
	GAMESTART = 1,
	GAMESETTING,
	EXIT,
};

enum SETMENU
{
	RE_MAPSIZE = 1,
	RE_CURSER,
	RE_STONE,
	RE_SKIP,
	RETURN,
};
