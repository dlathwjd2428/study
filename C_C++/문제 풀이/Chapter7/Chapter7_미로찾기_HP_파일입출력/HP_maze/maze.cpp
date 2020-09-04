#pragma warning(disable:4996)
#include "head.h"
#include "GameSet.h"

int** map;

int character[2];
int Entry_Potal[POTAL_MAX][2];
int Exit_Potal[POTAL_MAX][2];

int QEntry_Potal[Q_MAX][2];
int QExit_Potal[Q_MAX][2];

int BEntry_Potal[B_MAX][3];
int BExit_Potal[B_MAX][3];

int End_Potal[E_MAX][2];

int menu();
void Init();
int reset_map();
int save_rmap();
void save_wmap(int a, int b);
void Move();
void MoveCheck();
void MapDraw();
int Find_Entry(int x, int y);
int Find_Exit(int x, int y);
int Find_QEntry(int x, int y);
int Find_QExit(int x, int y);
int Find_BEntry(int x, int y);
int Find_BExit(int x, int y);
int Find_End(int x, int y);

int answer = 0;
int gameplay = 1;
int player_HP = 100; 
int PlayerPoint = 0;
int a = 0, b = 0;

int main()
{
	switch (menu())
	{
	case 1:
		reset_map();
		Init();
		break;

	case 2:
		save_rmap();
		break;
	}

	Init();
	while (gameplay)
	{
		MapDraw();
		Move();
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int menu()
{
	int ch = 0;
	printf("당신은...개미지옥에서.....탈출 가능할까요..?\n");
	printf("============================================\n");
	printf("<<< 게임 설명 >>>\n");
	PUPPLE
		printf("▣");
	ORIGINAL
		printf(": 버튼입니다-!! \n    밟으면 막혀있던 ");
	PUPPLE
		printf("▩");
	ORIGINAL
		printf("이 사라져요!!\n");
	GREEN
		printf("??");
	ORIGINAL
		printf(": 퀴즈타임~!!\n    맞추면");
	GREEN
		printf("▒");
	ORIGINAL
		printf("로 이동!\n    틀리면 처음부터 ㅠㅠ\n");
	BLUE
		printf("◎");
	ORIGINAL
		printf(": 순간이동 포탈입니다-!!\n    밟으면");
	YELLOW
		printf("●");
	ORIGINAL
		printf("로 이동해요\n");
	printf("============================================\n\n");
	printf("1. 처음부터 하기           2.이어서 계속하기\n\n");
	printf("입력 > ");


	scanf("%d", &ch);

	return ch;
}
void Init()
{
	system("cls");
	
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			if (map[y][x] == CHARACTER)
			{
				character[X] = x;
				character[Y] = y;
			}
			else if (map[y][x] == END)
			{
				End_Potal[map[y][x] - END][X] = x;
				End_Potal[map[y][x] - END][Y] = y;
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
			else if (map[y][x] >= QENTRY_START && map[y][x] < QENTRY_START + Q_MAX)
			{
				QEntry_Potal[map[y][x] - QENTRY_START][X] = x;
				QEntry_Potal[map[y][x] - QENTRY_START][Y] = y;
			}
			else if (map[y][x] >= QEXIT_START && map[y][x] < QEXIT_START + Q_MAX)
			{
				QExit_Potal[map[y][x] - QEXIT_START][X] = x;
				QExit_Potal[map[y][x] - QEXIT_START][Y] = y;
			}
			else if (map[y][x] >= BENTRY_START && map[y][x] < BENTRY_START + B_MAX)
			{
				BEntry_Potal[map[y][x] - BENTRY_START][X] = x;
				BEntry_Potal[map[y][x] - BENTRY_START][Y] = y;
				BEntry_Potal[map[y][x] - BENTRY_START][FLAG] = TRUE;
			}
			else if (map[y][x] >= BEXIT_START && map[y][x] < BEXIT_START + B_MAX)
			{
				BExit_Potal[map[y][x] - BEXIT_START][X] = x;
				BExit_Potal[map[y][x] - BEXIT_START][Y] = y;
				BExit_Potal[map[y][x] - BEXIT_START][FLAG] = TRUE;
			}
		}
	}
}
////////////////////////////////////////////////////////////  FILE 함수 모음  ////////////////////////////////////////////////////////////
int reset_map()
{
	FILE* maze_file = fopen("clear_maze.txt", "r");

	if (maze_file == NULL)
		printf("가져올 데이터가 없습니다, \n");
	else
	{
		map = (int **)malloc(sizeof(int *) * WIDTH);

		for (int i = 0; i < WIDTH; i++)
		{
			map[i] = (int *)malloc(sizeof(int *) * HEIGHT);
			if (map[i] == NULL)
			{
				printf("%d번째 maze 동적할당실패!\n");
				return -1;
			}
		}
 
		fscanf(maze_file, "%d", &player_HP);
		for (int i = 0; i < WIDTH; i++)
		{
			for (int j = 0; j < HEIGHT; j++)
			{
				fscanf(maze_file, "%d ", &map[i][j]);
			}
		}
	}

	fclose(maze_file);
}
int save_rmap()
{
	FILE* file_save = fopen("maze.txt", "r");

	if (file_save == NULL)
		printf("가져올 데이터가 없습니다, \n");
	else
	{
		map = (int **)malloc(sizeof(int *) * WIDTH);

		for (int i = 0; i < WIDTH; i++)
		{
			map[i] = (int *)malloc(sizeof(int *) * HEIGHT);
			if (map[i] == NULL)
			{
				printf("%d번째 maze 동적할당실패!\n");
				return -1;
			}
		}

		fscanf(file_save, "%d", &player_HP);

		for (int i = 0; i < WIDTH; i++)
		{
			for (int j = 0; j < HEIGHT; j++)
			{
				fscanf(file_save, "%d ", &map[i][j]);
			}
		}


	}
	fclose(file_save);
}
void save_wmap(int a, int b)
{
	FILE* file_save = fopen("maze.txt", "w");

	fprintf(file_save, "%d ", player_HP);

	for (int i = 0; i < WIDTH; i++)
	{
		for (int j = 0; j < HEIGHT; j++)
		{
			if (map[a][b] == TRUE)
			{
				fprintf(file_save, "%d ", 2);
			}
			else
			{
				fprintf(file_save, "%d ", map[i][j]);
			}

		}
		fprintf(file_save, "\n");
	}
	fclose(file_save);
}
////////////////////////////////////////////////////////////  MOVE 함수 모음  ////////////////////////////////////////////////////////////

void Move()
{
	char ch;
	ch = _getch();
	system("cls");
	map[character[Y]][character[X]] = NULL;
	switch (ch)
	{
	case ESC :
		printf("게임이 종료되었습니다");
		exit(0);
		free(map);
		break;

	case 's': //save
		if (map[character[Y]][character[X]] = CHARACTER)
		{
			a = character[Y];
			b = character[X];
		}
		save_wmap(a, b);
		system("cls");
		printf("저장되었습니다.\n");
		system("pause");

		break;
	case LEFT:
		if (map[character[Y]][character[X] - 1] != WALL && Find_BExit(character[X] - 1, character[Y]) == -1)
		{
			character[X]--;
			player_HP--;
		}
		break;
	case RIGHT:
		if (map[character[Y]][character[X] + 1] != WALL && Find_BExit(character[X] + 1, character[Y]) == -1)
		{
			character[X]++;
			player_HP--;
		}
		break;
	case UP:
		if (map[character[Y] - 1][character[X]] != WALL && Find_BExit(character[X], character[Y] - 1) == -1)
		{
			character[Y]--;
			player_HP--;
		}
		break;
	case DOWN:
		if (map[character[Y] + 1][character[X]] != WALL && Find_BExit(character[X], character[Y] + 1) == -1)
		{
			character[Y]++;
			player_HP--;
		}
		break;
	}
	MoveCheck();
	map[character[Y]][character[X]] = CHARACTER;
}
void MoveCheck()
{
	if (player_HP <= 0)
	{
		gameplay = 0;
		printf("GAME OVER");
		system("pause");
	}
	int index = Find_Entry(character[X], character[Y]); // 포탈이동용 인덱스
	if (index != -1)
	{
		character[X] = Exit_Potal[index][X];
		character[Y] = Exit_Potal[index][Y];
	}

	int Eindex = Find_End(character[X] - 1, character[Y]);
	if (Eindex != -1)
	{
		gameplay = 0;
		printf("★★★★경★★★★축★★★★\n");
		printf("★개미 지옥에서 탈출 완료!!★\n");
		system("pause");
	}

	int Qindex = Find_QEntry(character[X], character[Y]); // 포탈이동용 인덱스
	if (Qindex != -1)
	{
		switch (Qindex)
		{
		case 0:
			printf("5! 의 값은? : ");
			scanf("%d", &answer);
			if (answer == 120)
			{
				character[X] = QExit_Potal[Qindex][X];
				character[Y] = QExit_Potal[Qindex][Y];
				break;
			}
			else // 틀리면 처음부터 다시 
			{
				character[X] = 1;
				character[Y] = 1;
				break;
			}
			break;
		case 1:
			printf("41+15*9/2+5.5? : ");
			scanf("%d", &answer);
			if (answer == 114)
			{
				character[X] = QExit_Potal[Qindex][X];
				character[Y] = QExit_Potal[Qindex][Y];
				break;
			}
			else // 틀리면 처음부터 다시 
			{
				character[X] = 1;
				character[Y] = 1;
				break;
			}
			break;
		case 2:
			printf(" 1+2*7-2 의 값은? : ");
			scanf("%d", &answer);
			if (answer == 13)
			{
				character[X] = QExit_Potal[Qindex][X];
				character[Y] = QExit_Potal[Qindex][Y];
				break;
			}
			else // 틀리면 처음부터 다시 
			{
				character[X] = 1;
				character[Y] = 1;
				break;
			}
			break;
		}
	}

	int Bindex = Find_BEntry(character[X], character[Y]);
	if (Bindex != -1)
	{
		BEntry_Potal[Bindex][FLAG] = FALSE;
		BExit_Potal[Bindex][FLAG] = FALSE;
	}
}
void MapDraw()
{
	system("cls");
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			if (map[y][x] == WALL)
				printf("▩");
			else if (map[y][x] == END)
			{
				GOLD
					printf("♬");
				ORIGINAL
			}
			else if (map[y][x] == CHARACTER)
			{
				RED
					printf("★");
				ORIGINAL
			}
			else if (Find_Entry(x, y) != -1)
			{
				BLUE
					printf("◎");
				ORIGINAL
			}
			else if (Find_Exit(x, y) != -1)
			{
				YELLOW
					printf("●");
				ORIGINAL
			}
			else if (Find_QEntry(x, y) != -1)
			{
				GREEN
					printf("??");
				ORIGINAL
			}
			else if (Find_QExit(x, y) != -1)
			{
				GREEN
					printf("▒");

				ORIGINAL

			}
			else if (Find_BEntry(x, y) != -1)
			{
				PUPPLE
					printf("▣");
				ORIGINAL
			}
			else if (Find_BExit(x, y) != -1)
			{
				PUPPLE
					printf("▩");
				ORIGINAL
			}
			else
				printf("  ");
		}
		printf("\n");
	}
	printf("HP : %d", player_HP);
	printf("\n\n저장 : S, 종료 : ESC");
	printf("\n저장하지 않고 종료 할 경우 리셋됩니다.");
}

////////////////////////////////////////////////////////////  FIND 함수 모음  ////////////////////////////////////////////////////////////
int Find_Entry(int x, int y) // 입구 찾는 것 
{
	for (int i = 0; i < POTAL_MAX; i++)
	{
		if (Entry_Potal[i][Y] == y && Entry_Potal[i][X] == x)
			return i;
	}
	return -1;
}
int Find_Exit(int x, int y) // 출구 찾는 것
{
	for (int i = 0; i < POTAL_MAX; i++)
	{
		if (Exit_Potal[i][Y] == y && Exit_Potal[i][X] == x)
			return i;
	}
	return -1;
}
int Find_QEntry(int x, int y)
{
	for (int i = 0; i < Q_MAX; i++)
	{
		if ((QEntry_Potal[i][Y] == y) && (QEntry_Potal[i][X]) == x)
			return i;
	}
	return -1;
}
int Find_QExit(int x, int y)
{
	for (int i = 0; i < Q_MAX; i++)
	{
		if (QExit_Potal[i][Y] == y && QExit_Potal[i][X] == x)
			return i;
	}
	return -1;
}
int Find_BEntry(int x, int y)
{
	for (int i = 0; i < B_MAX; i++)
	{
		if ((BEntry_Potal[i][Y] == y) && (BEntry_Potal[i][X]) == x && (BEntry_Potal[i][FLAG]) == TRUE)
			return i;
	}
	return -1;
}
int Find_BExit(int x, int y)
{
	for (int i = 0; i < B_MAX; i++)
	{
		if (BExit_Potal[i][Y] == y && BExit_Potal[i][X] == x && BExit_Potal[i][FLAG] == TRUE)
			return i;
	}
	return -1;
}
int Find_End(int x, int y)
{
	for (int i = 0; i < E_MAX; i++)
	{
		if (End_Potal[i][Y] == y && End_Potal[i][Y] == x)
			return i;
	}
	return -1;
}