#pragma once
#include "Mecro.h"

class Player
{
private:
	string name;
	bool stone;

public:
	bool WinnerCheck();
	bool StoneCheck();
	void TurnReturn();
	void FindStone();
};