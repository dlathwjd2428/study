#include "PlayGame.h"

PlayGame::PlayGame()
{
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
	while (1)
	{
		DrawMap(0, 0, Width, Height);
		DrawStone();
		Move();
	}
}

void PlayGame::Move()
{
	char ch;
	ch = _getch();

	system("cls");
	board[curser[Y]][curser[X]] = NULL;
	switch (ch)
	{
	case LEFT:
		if (board[curser[Y]][curser[X] - 1] != 0)
		{
			curser[X]--;
		}
		break;
	case RIGHT:
		if (board[curser[Y]][curser[X] + 1] != Width)
		{
			curser[X]++;
		}
		break;
	case UP:
		if (board[curser[Y] - 1][curser[X]] != 0)
		{
			curser[Y]--;
		}
		break;
	case DOWN:
		if (board[curser[Y] + 1][curser[X]] != Height)
		{
			curser[Y]++;
		}
		break;
	}
	WinnerCheck();
	board[curser[Y]][curser[X]] = CURSER;
}

void PlayGame::DrawStone()
{
	gotoxy(Width*0.5, Height*0.5);

	for (int y = 0; y < Height; y++)
	{
		for (int x = 0; x < Width; x++)
		{
			if (board[y][x] == CURSER)
				cout << "●";
		}
	}
	gotoxy(0, Height);
	cout << "Turn : " << turncount << endl;
	cout << "돌 놓기 : z, 무르기 : x, 종료 : ESC" << endl;
	cout << "옵션 : p" << endl;
	cout << "무르기 횟수 : " << skipcount << "           " << P1;
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