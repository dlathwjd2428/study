#include "PlayGame.h"

PlayGame::PlayGame()
{
	board = new int *[Width];
	for (int i = 0; i < Width; i++)
	{
		board[i] = new int[Height];
	}

	for (int i = 0; i < Width; i++)
	{
		memset(board[i], 0, sizeof(int)*Height);
	}

	turncount = 1;
	skipcount = 3;
}

void PlayGame :: Init()
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

	OnPlayGame();
}

void PlayGame::OnPlayGame()
{

	while (1)
	{
		DrawMap(0, 0, Width, Height);
		DrawStone();
		WinnerCheck();
	}
}

void PlayGame::Move()
{
}

void PlayGame::DrawStone()
{
	gotoxy(0, Height);
	cout << "Turn : " << turncount << endl;
	cout << "�� ���� : z, ������ : x, ���� : ESC" << endl;
	cout << "�ɼ� : p" << endl;
	cout << "������ Ƚ�� : " << skipcount << "           " << P1;
}

void PlayGame::WinnerCheck()
{

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