#include<stdio.h>
#include<conio.h>
#include<Windows.h>
//////////////////////////////////////////////////////
#define col GetStdHandle(STD_OUTPUT_HANDLE) 
#define BLACK SetConsoleTextAttribute( col,0x0000 );
#define DARK_BLUE SetConsoleTextAttribute( col,0x0001 );
#define GREEN SetConsoleTextAttribute( col,0x0002 );
#define BLUE_GREEN SetConsoleTextAttribute( col,0x0003 );
#define BLOOD SetConsoleTextAttribute( col,0x0004 );
#define PUPPLE SetConsoleTextAttribute( col,0x0005 );
#define GOLD SetConsoleTextAttribute( col,0x0006 );			//색상 지정
#define ORIGINAL SetConsoleTextAttribute( col,0x0007 );
#define GRAY SetConsoleTextAttribute( col,0x0008 );
#define BLUE SetConsoleTextAttribute( col,0x0009 );
#define HIGH_GREEN SetConsoleTextAttribute( col,0x000a );
#define SKY_BLUE SetConsoleTextAttribute( col,0x000b );
#define RED SetConsoleTextAttribute( col,0x000c );
#define PLUM SetConsoleTextAttribute( col,0x000d );
#define YELLOW SetConsoleTextAttribute( col,0x000e );
//////////////////////////////////////////////////////

#define WALL 1
#define NULL 0
#define Y 0
#define X 1
#define CHARACTER 2
#define POTAL_MAX 2//포탈 갯수

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define EXIT 10
#define WIDTH 10
#define HEIGHT 10
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