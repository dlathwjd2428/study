#include "head.h"

#define WALL 1
#define NULL 0
#define Y 0
#define X 1
#define CHARACTER 2
#define POTAL_MAX 2//Æ÷Å» °¹¼ö
#define ENTRY_START 10
#define EXIT_START 20
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define WIDTH 10
#define HEIGHT 10
#define ITEM 5 
#define GOAL 100

int item = 0;

int map[HEIGHT][WIDTH] = {
  { 1,	1,	1,	1,	1,	1,	1,	1,	1,	1 },
  { 1,	2,	0,	1,	100,0,	0,	1,	5,	1 },
  { 1,	1,	5,	1,	1,	1,	5,	0,	0,	1 },
  { 1,	5,	0,	1,	0,	11,	1,	0,	1,	1 },
  { 1,	10,	1,	5,	5,	1,	5,	0,	5,	1 },
  { 1,	1,	1,	5,	0,	1,	5,	1,	0,	1 },
  { 1,	20,	0,	1,	0,	1,	0,	5,	0,	1 },
  { 1,	1,	5,	1,	5,	1,	0,	1,	0,	1 },
  { 1,	5,	0,	5,	0,	1,	1,	1,	21,	1 },
  { 1,	1,	1,	1,	1,	1,	1,	1,	1,	1 } };
int character[2];
int Entry_Potal[POTAL_MAX][2];
int Exit_Potal[POTAL_MAX][2];

int Find_Entry(int x, int y)
{
	for (int i = 0; i < POTAL_MAX; i++)
	{
		if (Entry_Potal[i][Y] == y && Entry_Potal[i][X] == x)
			return i;
	}
	return -1;
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
void Init()
{
	int Width = (WIDTH * 2) + 10;
	int Height = HEIGHT + 10;
	char buf[256];
	sprintf_s(buf, "mode con: lines=%d cols=%d", Height, Width);
	system(buf);

	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			if (map[y][x] == CHARACTER)
			{
				character[X] = x;
				character[Y] = y;
			}
			else if (map[y][x] >= ENTRY_START && map[y][x] < ENTRY_START + POTAL_MAX)
			{
				Entry_Potal[map[y][x] - ENTRY_START][X] = x;
				Entry_Potal[map[y][x] - ENTRY_START][Y] = y;
			}
			else if (map[y][x] >= EXIT_START && map[y][x] < EXIT_START + POTAL_MAX)
			{
				Exit_Potal[map[y][x] - EXIT_START][X] = x;
				Exit_Potal[map[y][x] - EXIT_START][Y] = y;
			}
			else if (map[y][x] == GOAL)
			{
				Exit_Potal[map[y][x] - GOAL][X] = x;
				Exit_Potal[map[y][x] - GOAL][Y] = y;
			}
		}
	}
}
void MapDraw()
{
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			if (map[y][x] == WALL)
				printf("¢Ì");
			else if (map[y][x] == CHARACTER)
			{
				HIGH_GREEN
					printf("¿Ê");
				ORIGINAL
			}
			else if (map[y][x] == GOAL)
			{
				PLUM
					printf("¢Â");
				ORIGINAL
			}
			else if (map[y][x] == ITEM)
			{
				SKY_BLUE
					printf("¢Ü");
				ORIGINAL
			}
			else if (Find_Entry(x, y) != -1)
			{
				BLUE
					printf("¡Ý");
				ORIGINAL
			}
			else if (Find_Exit(x, y) != -1)
			{
				YELLOW
					printf("¡Ü");
				ORIGINAL
			}
			else if (map[y][x] == NULL)
				printf("  ");
		}
		printf("\n");
	}

	printf("¸ðÀº À½Ç¥ °¹¼ö : %d", item);
}

void MoveCheck()
{
	if (map[character[Y]][character[X]] == GOAL)
	{
		exit(0);
	}
	int index = Find_Entry(character[X], character[Y]);
	if (index != -1)
	{
		character[X] = Exit_Potal[index][X];
		character[Y] = Exit_Potal[index][Y];
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
		if (map[character[Y]][character[X]] == ITEM)
			item++;		
		break;
	case RIGHT:
		if (map[character[Y]][character[X] + 1] != WALL)
			character[X]++;
		if (map[character[Y]][character[X]] == ITEM)
			item++;
		break;
	case UP:
		if (map[character[Y] - 1][character[X]] != WALL)
			character[Y]--;
		if (map[character[Y]][character[X]] == ITEM)
			item++;
		break;
	case DOWN:
		if (map[character[Y] + 1][character[X]] != WALL)
			character[Y]++;
		if (map[character[Y]][character[X]] == ITEM)
			item++;
		break;
	}
	MoveCheck();
	map[character[Y]][character[X]] = CHARACTER;
}
void main()
{
	Init();
	while (1)
	{
		MapDraw();
		Move();
	}
}