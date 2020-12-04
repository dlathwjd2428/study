#pragma once
#include "Mecro.h"
#include "PlayGame.h"

class Menu : public PlayGame
{
public:
	int StartMenu();
	void SetMenu();

	void Re_MapSize();
	void Re_Curser();
	void Re_Stone();
	void Re_Skip();
};