#include "PlayGame.h"


PlayGame::PlayGame()
{
	turncount = 1;
	skipcount = 3;
	posX = posY = 0;
	colorOfStone = true;
}

void PlayGame::Init()
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

	system("cls");

	for (int y = 0; y < Height; y++)
	{
		for (int x = 0; x < Width; x++)
		{
			if (board[y][x] == CURSER)
			{
				curser[X] = x;
				curser[Y] = y;
			}
		}
	}
	OnPlayGame();
}

bool PlayGame::moveX(int direction)
{
	if (posX + direction < 0 || posX + direction >= Width)
		return false;
	posX += direction;
	return true;
}

bool PlayGame::moveY(int direction)
{
	if (posY + direction < 0 || posY + direction >= Width)
		return false;
	posY += direction;
	return true;
}

bool PlayGame::checkRange(int x, int y)
{
	return !(x >= Width || x < 0 || y >= Width || y < 0);
}

bool PlayGame::changeBord(int x, int y, bool value)
{
	if (checkRange(x, y))
		board[x][y] = value ? 1 : 2;
	else
		return false;
	return true;
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
	gotoxy(0, 0);
	bool put = false;

	while (1)
	{
		if (getColor())
			cout << "흑돌의 순서입니다.";
		else
			cout << "백돌의 순서입니다.";
		int dir;
		dir = _getch();
		bool state;
		switch (dir)
		{
		case UP:
			state = moveX(-1);
			break;
		case DOWN:
			state = moveX(1);
			break;
		case LEFT:
			state = moveY(-1);
			break;
		case RIGHT:
			state = moveY(1);
			break;
		case 'z':
			put = true;
			break;
		default:
			state = false;
			cout << "올바른 키를 입력해주세요!";
		}
		if (put)
		{
			if (getColor())
				printf("○");
			else
				printf("●");

			put = false;

			changeBord(getX(), getY(), getColor());
			if (WinnerCheck())
			{
				if (getColor())
					cout << "흑돌이 승리하였습니다.";
				else
					cout << "백돌이 승리하였습니다.";
				return;
			}
			reverseColor();
		}
		else
		{
			if (state)
				gotoxy(getY() * 2, getX());
		}
	}
	board[curser[Y]][curser[X]] = CURSER;
}

void PlayGame::DrawStone()
{

	gotoxy(0, Height);
	cout << "Turn : " << turncount << endl;
	cout << "돌 놓기 : z, 무르기 : x, 종료 : ESC" << endl;
	cout << "옵션 : p" << endl;
	cout << "무르기 횟수 : " << skipcount << "           " << P1;
}

bool PlayGame::WinnerCheck()
{
	int state;
	if (colorOfStone)
		state = 1;
	else state = 2;

	for (int i = 0; i < Width; i++)
	{
		for (int j = 0; j < Width; j++)
		{
			int buff = board[i][j];
			if (buff == state && buff != 0)
			{
				int countStone = 1;
				if (checkRange(i + 1, j) && board[i + 1][j] == buff)
				{
					countStone++;
					for (int k = 2; k < 5; k++)
					{
						if (checkRange(i + k, j) && board[i + k][j] == buff)
						{
							countStone++;
						}
						else
						{
							break;
						}
					}
				}

				if (countStone == 5)
					return true;
				else countStone = 1;

				if (checkRange(i, j + 1) && board[i][j + 1] == buff)
				{
					countStone++;

					for (int k = 2; k < 5; k++)
					{
						if (checkRange(i, j + k) && board[i][j + k] == buff)
						{
							countStone++;
						}
						else
						{
							break;
						}
					}
				}
				if (countStone == 5)
					return true;
				else countStone = 1;

				if (checkRange(i + 1, j + 1) && board[i + 1][j + 1] == buff)
				{
					countStone++;
					for (int k = 2; k < 5; k++)
					{
						if (checkRange(i + k, j + k) && board[i + k][j + k] == buff)
						{
							countStone++;
						}
						else
						{
							break;
						}
					}
				}
				if (countStone == 5) return true;
				else countStone = 1;
				if (checkRange(i + 1, j - 1) && board[i + 1][j - 1] == buff)
				{
					countStone++;

					for (int k = 2; k < 5; k++)
					{
						if (checkRange(i + k, j - k) && board[i + k][j - k] == buff)
						{
							countStone++;
						}
						else
						{
							break;
						}
					}
				} if (countStone == 5)
					return true;
			}
		}
	}
	return false;
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