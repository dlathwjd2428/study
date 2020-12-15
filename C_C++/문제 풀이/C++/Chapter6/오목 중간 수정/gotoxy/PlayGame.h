#pragma once
#include "Mecro.h"
#include "MapDraw.h"

class PlayGame : public MapDraw
{
protected:
	int **board;
	int turncount;
	int skipcount;

private:
	int curser_x;
	int curser_y;
	string P1;
	string P2;


public:
	void Init();
	void OnPlayGame();
	void Move();
	void DrawStone();
	void WinnerCheck();
	void OnSkip();

	PlayGame();
	~PlayGame();
};