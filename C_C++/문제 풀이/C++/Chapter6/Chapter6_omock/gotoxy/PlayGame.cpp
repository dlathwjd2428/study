#include "PlayGame.h"

PlayGame::PlayGame()
{
	string P1, P2;
	system("cls");
	DrawBox(0, 0, Width, Height);
	DrawMidText("�� �̸� ����", Width, Height*0.1);
	DrawMidText("P1 �̸� : ", Width, Height*0.2);
	cin >> P1;
	DrawMidText("P2 �̸� : ", Width, Height*0.3);
	cin >> P2;

	this->P1 = P1;
	this->P2 = P2;
}

void PlayGame :: OnPlayGame()
{

}

PlayGame::~PlayGame()
{
}