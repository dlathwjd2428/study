#pragma once
#include <Windows.h>
#include <cstdio>
#include <conio.h>
#include <array>
#include <cstdio> 
#include <cstring> 
#include <iostream>
#define SIZE 15 
#define LOCATION 15
using namespace std;
class InfoWindow
{
private:
	int startLocationX;
	int startLocationY;
public:
	InfoWindow()
	{
		startLocationX = 35;
		startLocationY = 0;
	}
	void printInfo();
	void printfMessage(const char *msg, int originX, int originY);
};

class Concave
{
private:
	array<array<int, SIZE>, SIZE> bord;
	int posX;
	int posY;
	bool colorOfStone;
public:
	bool changeBord(int x, int y, bool value);
	bool checkRange(int x, int y);
	Concave();
	~Concave();
	int getX()
	{
		return posX;
	}
	int getY()
	{
		return posY;
	}
	bool moveX(int direction);
	bool moveY(int direction);
	void printValue();
	bool checkWin();
	void reverseColor()
	{
		colorOfStone = !colorOfStone;
	}

	bool getColor()
	{
		return colorOfStone;
	}
};

class ControlGoStone
{
private:
	Concave concave;
	InfoWindow imformation;
	int locationOfX;
	int locationOfY;
public:
	ControlGoStone();
	~ControlGoStone();
	void printBord();
	void movingStone();
};
