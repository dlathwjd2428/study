#pragma once

#include<iostream>
#include<string>
#include <string.h>
#include<conio.h>
#include<iomanip>
#include<Windows.h>
using namespace std;

#define DRAW_BLACK cout<<"¡Û"
#define DRAW_WHITE cout<<"¡Ü"
#define WHITE 2
#define BLACK 1

#define Y 0
#define X 1
#define CURSER 2
#define BLANK 0

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
