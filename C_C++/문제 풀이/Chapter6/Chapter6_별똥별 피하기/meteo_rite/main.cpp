#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h> 
#include<Windows.h> 
#include<conio.h> 
#include<stdlib.h> 
#include<time.h> 

#define GAMESTART 1 
#define LEVEL 2 
#define EXIT 3 
#define WIDTH 10 
#define HEIGHT 20 
#define Y 0 
#define X 1 
#define NULL 0
#define WALL 1 
#define PLAYER 2 
#define STAR 3 
#define false 0 
#define true 1 

int player[2];
int loop = 1;
int score = 0;

int menu()
{
	int ch;

	printf("=====별똥별 피하기=====\n");
	printf("  1.게임 시작\n");
	printf("  2.난이도 조절\n");
	printf("  3.종료\n");
	scanf("%d", &ch);

	return ch;
}

void Init(int map[][WIDTH])
{
	player[X] = WIDTH - 5;
	player[Y] = HEIGHT - 1;
}

void StarCreate(int map[HEIGHT][WIDTH])
{
	int lv, i, x;

	for (lv = 0; lv < 10; lv++)
	{
		x = rand() % 8 + 1;
		if (map[0][x] == STAR)
		{
			lv--;
		}
		else
		{
 		map[0][x] = STAR;
		}
	}
}

void map_reset(int map[][WIDTH])
{
	int y, x;

	for (y = 0; y < HEIGHT; y++)
	{
		for (x = 0; x < WIDTH; x++)
		{
			map[y][0] = WALL;
			map[y][WIDTH - 1] = WALL;
		}
	}
	StarCreate(map);
}

void MapDraw(int map[][WIDTH])
{
	system("cls");

	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			if (player[Y] == y && player[X] == x)
				printf("옷");
			else if (map[y][x] == WALL)
				printf("│");
			else if (map[y][x] == STAR)
				printf("☆");
			else
				printf("  ");
		}
		printf("\n");
	}
	printf("\n Score : %d\n", score);
}

void Star_Update(int map[HEIGHT][WIDTH])
{
	for (int y = HEIGHT - 1; y >= 0; y--)
	{
		for (int x = 1; x < WIDTH - 1; x++)
		{
			if (map[y][x] == STAR)
			{
				map[y][x] = 0;
				if (y + 1 >= HEIGHT)
				{
					map[HEIGHT - 1][1] = 0;
					map[HEIGHT - 1][2] = 0;
					map[HEIGHT - 1][3] = 0;
					map[HEIGHT - 1][4] = 0;
					map[HEIGHT - 1][5] = 0;
					map[HEIGHT - 1][6] = 0;
					map[HEIGHT - 1][7] = 0;
					map[HEIGHT - 1][8] = 0;

					StarCreate(map);
					return;
				}
				else
				{
					map[y + 1][x] = STAR;
				}
			}
		}
	}
}

int cheak_hit(int map[][WIDTH])
{
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			if (map[y][x] == STAR)
			{
				if (player[Y] == y && player[X] == x)
				{
					return 1;
				}
			}
		}
	}
	return 0;
}

void PlayerMove(int map[][WIDTH])
{
	char ch;

	if (_kbhit())
	{
		ch = _getch();
		if (ch == 'a' || ch == 'A')
		{
			if (map[player[Y]][player[X] - 1] != WALL)
				player[X]--;
		}

		if (ch == 'd' || ch == 'D')
		{
			if (map[player[Y]][player[X] + 1] != WALL)
				player[X]++;
		}
	}
	if (cheak_hit(map) == 1)
	{
		loop = 0;
	}
	else
	{
		score++;
	}

}

void main()
{
	int map[HEIGHT][WIDTH] = { 0 };
	int x;
	while (loop)
	{
		switch (menu())
		{
		case GAMESTART:

			map_reset(map);
			Init(map);
			srand((unsigned)time(NULL));
			while (loop)
			{
				Star_Update(map);
				MapDraw(map);
				PlayerMove(map);
				Sleep(33);
			}
			break;

		case EXIT:
			return;

		}

	}

}