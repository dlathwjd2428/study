#include "PlayGame.h"

PlayGame::PlayGame()
{
	board = new int *[Height];
	for (int i = 0; i < Height; i++)
	{
		board[i] = new int[Width];
		memset(board[i], 0, sizeof(board));
	}
	turncount = 1;
	skipcount = 3;
}

void PlayGame :: Init()
{
	string P1, P2;
	system("cls");
	DrawBox(0, 0, Width, Height);
	DrawMidText("팀 이름 설정", Width, Height*0.1);
	DrawMidText("P1 이름 : ", Width, Height*0.2);
	cin >> P1;
	DrawMidText("P2 이름 : ", Width, Height*0.3);
	cin >> P2;

	this->P1 = P1;
	this->P2 = P2;

	OnPlayGame();
}

void PlayGame::OnPlayGame()
{
	DrawMap(0, 0, Width, Height);
	gotoxy(0, Height);
	cout << "Turn : " << turncount << endl;
	cout << "돌 놓기 : z, 무르기 : x, 종료 : ESC" << endl;
	cout << "옵션 : p" << endl;
	cout << "무르기 횟수 : " << skipcount << "           " << P1;
	system("pause");
}

void PlayGame::OnSkip()
{
	
}

PlayGame::~PlayGame()
{
	for (int i = 0; i < Height; i++)
	{
		delete[]board[i];
	}
	delete[]board;
}