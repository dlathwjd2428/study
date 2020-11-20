#pragma once
#include "Mecro.h"
#include "MapDraw.h"

class Menu : public MapDraw
{
public:
	int StartMenu();
	void SetMenu();

	void Re_MapSize();
	void Re_Curser();
	void Re_Stone();
	void Re_Skip();
};