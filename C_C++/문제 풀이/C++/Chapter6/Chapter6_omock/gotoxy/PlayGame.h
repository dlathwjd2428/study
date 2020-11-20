#pragma once
#include "Mecro.h"
#include "MapDraw.h"

class PlayGame : public MapDraw
{
private:
	string P1;
	string P2;
public:
	void OnPlayGame();

	PlayGame();
	~PlayGame();
};