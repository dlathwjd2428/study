#pragma once
#include "Mecro.h"
#include "MapDraw.h"

class PlayGame : public MapDraw
{
protected:
	int turncount;
	int skipcount;
	int colorOfStone;

private:
	int curser[2];
	string P1;
	string P2;
	int posX;
	int posY;

public:
	void Init();
	int getX()
	{
		return posX;
	} int getY()
	{
		return posY;
	}
	bool moveX(int direction);
	bool moveY(int direction);
	void OnPlayGame();
	void Move();
	void DrawStone();
	bool WinnerCheck();
	bool getColor()
	{
		return colorOfStone;
	}
	void reverseColor()
	{
		colorOfStone = !colorOfStone;
	}
	void OnSkip();
	bool checkRange(int x, int y);
	bool changeBord(int x, int y, bool value);

	PlayGame();
	~PlayGame();
};