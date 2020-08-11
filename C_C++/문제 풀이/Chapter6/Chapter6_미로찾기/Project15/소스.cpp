#include "head.h"

int map[HEIGHT][WIDTH] = {
  { 1,	1,	1,	1,	1,	1,	1,	1,	1,	1 },
  { 1,	2,	0,	1,	0,	0,	0,	1,	0,	1 },
  { 1,	1,	0,	1,	0,	1,	0,	0,	0,	1 },
  { 1,	0,	0,	1,	0,	0,	1,	0,	1,	1 },
  { 1,	0,	1,	0,	0,	1,	0,	0,	0,	1 },
  { 1,	0,	1,	0,	0,	1,	0,	1,	0,	1 },
  { 1,	0,	0,	1,	0,	1,	0,	0,	0,	1 },
  { 1,	1,	0,	1,	0,	1,	0,	1,	0,	1 },
  { 1,	0,	0,	0,	0,	1,	1,	1,	10,	1 },
  { 1,	1,	1,	1,	1,	1,	1,	1,	1,	1 } };
int character[2];
int Exit_Potal[POTAL_MAX][2];

void Init()
{
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			if (map[y][x] == CHARACTER)
			{
				character[X] = x;
				character[Y] = y;
			}
			else if (map[y][x] == EXIT)
			{
				Exit_Potal[map[y][x] - EXIT][X] = x;
				Exit_Potal[map[y][x] - EXIT][Y] = y;
			}
		}
	}
}

int Find_Exit(int x, int y)
{
	for (int i = 0; i < POTAL_MAX; i++)
	{
		if (Exit_Potal[i][Y] == y && Exit_Potal[i][X] == x)
			return i;
	}
	return -1;
}

int MoveCheck()
{
	int index = Find_Exit(character[X], character[Y]);
	if (index != -1)
	{
		exit(0);
	}
	
}

void Move()
{
	char ch;
	ch = _getch();
	system("cls");
	map[character[Y]][character[X]] = NULL;
	switch (ch)
	{
	case LEFT:
		if (map[character[Y]][character[X] - 1] != WALL)
			character[X]--;
		break;
	case RIGHT:
		if (map[character[Y]][character[X] + 1] != WALL)
			character[X]++;
		break;
	case UP:
		if (map[character[Y] - 1][character[X]] != WALL)
			character[Y]--;
		break;
	case DOWN:
		if (map[character[Y] + 1][character[X]] != WALL)
			character[Y]++;
		break;
	}
	MoveCheck();
	map[character[Y]][character[X]] = CHARACTER;
}

void MapDraw()
{
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			if (map[y][x] == WALL)
				printf("▩");
			else if (map[y][x] == CHARACTER)
			{
				PLUM
					printf("옷");
				ORIGINAL
			}
			else if (Find_Exit(x, y) != -1)
			{
				YELLOW
					printf("◈");
				ORIGINAL
			}
			else if (map[y][x] == NULL)
				printf("  ");
		}
		printf("\n");
	}
}

int main()
{
	Init();

	while (1)
	{
		MapDraw();
		Move();
	}
}