#include "ControlGoStone.h"
//값일 때 // 1, true: 흑돌 // 2, false: 백돌 //
void gotoxy(int x, int y);

ControlGoStone::ControlGoStone()
{
	locationOfX = locationOfY = 0;
	//concave.SetColorOfStone(true); 
	printBord();
	imformation.printInfo();
}
ControlGoStone::~ControlGoStone()
{
}
void ControlGoStone::printBord()
{
	int i, j; printf("┌");
	for (i = 0; i < SIZE - 2; i++)
		printf("-┬");
	printf("-┐\n");
	for (i = 0; i < SIZE - 2; i++)
	{
		printf("├");
		for (j = 0; j < SIZE - 2; j++)
			printf("-┼");
		printf("-┤\n");
	}
	printf("└");
	for (i = 0; i < SIZE - 2; i++)
		printf("-┴");
	printf("-┘");
}

void ControlGoStone::movingStone()
{
	gotoxy(0, 0);
	bool put = false;
	while (1)
	{
		if (concave.getColor())
			imformation.printfMessage("흑돌의 순서입니다.", concave.getY() * 2, concave.getX());
		else imformation.printfMessage("백돌의 순서입니다.", concave.getY() * 2, concave.getX());
		int dir;
		dir = _getch();
		bool state;
		switch (dir)
		{
		case 'w':
			state = concave.moveX(-1);
			break;
		case 's':
			state = concave.moveX(1);
			break;
		case 'a':
			state = concave.moveY(-1);
			break;
		case 'd':
			state = concave.moveY(1);
			break;
		case 'h':
			put = true;
			break;
		default:
			state = false;
			imformation.printfMessage("올바른 키를 입력해주세요!", concave.getY() * 2, concave.getX());
		}
		if (put)
		{
			if
				(concave.getColor()) printf("○");
			else
				printf("●");
			put = false;
			concave.changeBord(concave.getX(), concave.getY(), concave.getColor());
			if (concave.checkWin())
			{
				if (concave.getColor()) imformation.printfMessage("흑돌이 승리하였습니다.", concave.getY() * 2, concave.getX());
				else imformation.printfMessage("백돌이 승리하였습니다.", concave.getY() * 2, concave.getX());
				return;
			}
			concave.reverseColor();
		}
		else
		{
			if (state) gotoxy(concave.getY() * 2, concave.getX());
		}
	}
} //concave Class--------------------------------------------------------------------------------------------------------------
Concave::Concave()
{
	for (int i = 0; i < SIZE; i++) for (int j = 0; j < SIZE; j++) bord[i][j] = 0; posX = posY = 0; colorOfStone = true;
} Concave::~Concave()
{
} bool Concave::moveX(int direction)
{
	if (posX + direction < 0 || posX + direction >= SIZE) return false; posX += direction; return true;
} bool Concave::moveY(int direction)
{
	if (posY + direction < 0 || posY + direction >= SIZE) return false; posY += direction; return true;
} bool Concave::changeBord(int x, int y, bool value)
{
	if (checkRange(x, y)) bord[x][y] = value ? 1 : 2; else return false; return true;
} bool Concave::checkRange(int x, int y)
{
	return !(x >= SIZE || x < 0 || y >= SIZE || y < 0);
} void Concave::printValue()
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++) printf("%2d", bord[i][j]); printf("\n");
	}
} bool Concave::checkWin()
{
	int state; if (colorOfStone) state = 1; else state = 2; for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			int buff = bord[i][j]; if (buff == state && buff != 0)
			{
				int countStone = 1; if (checkRange(i + 1, j) && bord[i + 1][j] == buff)
				{
					countStone++; for (int k = 2; k < 5; k++)
					{
						if (checkRange(i + k, j) && bord[i + k][j] == buff)
						{
							countStone++;
						}
						else
						{
							break;
						}
					}
				} if (countStone == 5) return true; else countStone = 1; if (checkRange(i, j + 1) && bord[i][j + 1] == buff)
				{
					countStone++; for (int k = 2; k < 5; k++)
					{
						if (checkRange(i, j + k) && bord[i][j + k] == buff)
						{
							countStone++;
						}
						else
						{
							break;
						}
					}
				} if (countStone == 5) return true; else countStone = 1; if (checkRange(i + 1, j + 1) && bord[i + 1][j + 1] == buff)
				{
					countStone++; for (int k = 2; k < 5; k++)
					{
						if (checkRange(i + k, j + k) && bord[i + k][j + k] == buff)
						{
							countStone++;
						}
						else
						{
							break;
						}
					}
				} if (countStone == 5) return true; else countStone = 1; if (checkRange(i + 1, j - 1) && bord[i + 1][j - 1] == buff)
				{
					countStone++; for (int k = 2; k < 5; k++)
					{
						if (checkRange(i + k, j - k) && bord[i + k][j - k] == buff)
						{
							countStone++;
						}
						else
						{
							break;
						}
					}
				} if (countStone == 5) return true;
			}
		}
	} return false;
} //InfoClass------------------------------------------------------------------------------------------
void InfoWindow::printInfo()
{
	gotoxy(startLocationX, startLocationY); for (int i = 0; i < 40; i++)
	{
		printf("-");
	} for (int i = 1; i < 14; i++)
	{
		gotoxy(startLocationX, startLocationY + i); printf("|"); for (int i = 0; i < 38; i++)
		{
			printf(" ");
		} printf("|");
	} gotoxy(startLocationX, startLocationY + 14); for (int i = 0; i < 40; i++)
	{
		printf("-");
	} gotoxy(startLocationX + 3, startLocationY + 8); printf("w : 위로 한칸 이동."); gotoxy(startLocationX + 3, startLocationY + 9); printf("a : 왼쪽으로 한칸 이동."); gotoxy(startLocationX + 3, startLocationY + 10); printf("s : 아래로 한칸 이동."); gotoxy(startLocationX + 3, startLocationY + 11); printf("d : 오른쪽으로 한칸 이동."); gotoxy(startLocationX + 3, startLocationY + 12); printf("h : 착수");
} void InfoWindow::printfMessage(const char *msg, int originX, int originY)
{
	gotoxy(startLocationX + 2, startLocationY + 4); for (int i = 0; i < 37; i++) printf(" "); gotoxy(startLocationX + 1, startLocationY + 4); printf("%s", msg); gotoxy(originX, originY);
} void gotoxy(int x, int y)
{
	COORD Pos; Pos.X = x; Pos.Y = y; SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
