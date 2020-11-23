#pragma once
#include "Mecro.h"
#include "MapDraw.h"

class PlayGame : public MapDraw
{
private:
	int **board;
	string P1;
	string P2;

	int turncount;
	int skipcount;
	bool skip;
public:
	void Init();
	void OnPlayGame();
	void OnSkip();

	PlayGame();
	~PlayGame();
};