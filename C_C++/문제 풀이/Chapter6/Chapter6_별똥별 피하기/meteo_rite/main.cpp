#include "head.h"

int menu();
void MapDraw(int map[][WIDTH]);
void player_reset(int map[][WIDTH]);
void PlayerMove(int map[][WIDTH]);
int cheak_hit(int map[][WIDTH]);
void wall(int map[][WIDTH]);
void StarCreate(int map[HEIGHT][WIDTH]);
void Star_Update(int map[HEIGHT][WIDTH]);


int player[2];
int score = 0;
int loop = 1;


void main()
{
	int map[HEIGHT][WIDTH] = { 0 };

	while (loop)
	{
		switch (menu())
		{
		case 1:
			wall(map);
			player_reset(map);
			srand((unsigned)time(NULL));

			while (loop)
			{
				Star_Update(map);
				MapDraw(map);
				PlayerMove(map);
				Sleep(30);
			}
			break;

		case 2:
			return;

		}
	}
}

int menu()
{
	int ch = 0;

	printf("=====별똥별 피하기=====\n");
	printf("     1.게임 시작       \n");
	printf("     2.종료            \n");
	scanf("%d", &ch);

	return ch;
}
void player_reset(int map[][WIDTH])
{
	player[X] = WIDTH - 5;
	player[Y] = HEIGHT - 1;
}

void wall(int map[][WIDTH])
{
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
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
				printf("홋");
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

void StarCreate(int map[HEIGHT][WIDTH])
{
	int x = 0;

	for (int i = 0; i < 1; i++)
	{
		x = rand() % 8 + 1;

		map[0][x] = STAR;
	}
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
					for (int i = 1; i < 9; i++)
					{
						map[HEIGHT - 1][i] = 0;
					}
					score++;
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