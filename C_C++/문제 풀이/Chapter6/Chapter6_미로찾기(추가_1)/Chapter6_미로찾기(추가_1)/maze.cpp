#define _CRT_SECURE_NO_WARNINGS
#include"head.h"

#define WALL 1
#define NULL 0
#define Y 0
#define X 1
#define FLAG 2
#define CHARACTER 2 //캐릭터
#define TRUE 1
#define FALSE 0

#define END 3//게임 끝 
#define E_MAX 1
#define PUSH_BLOCK 5
#define POTAL_MAX 8//포탈 갯수
#define ENTRY_START 10
#define EXIT_START 20

#define Q_MAX 3 //질문 갯수
#define QENTRY_START 30
#define QEXIT_START 40

#define B_MAX 4//버튼 갯수
#define BENTRY_START 50
#define BEXIT_START 60

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80

extern char map[HEIGHT][WIDTH][STAGE];

int character[2];
int push_block[2];
int Entry_Potal[POTAL_MAX][2];
int Exit_Potal[POTAL_MAX][2];

int QEntry_Potal[Q_MAX][2];
int QExit_Potal[Q_MAX][2];

int BEntry_Potal[B_MAX][3];
int BExit_Potal[B_MAX][3];

int End_Potal[E_MAX][2];

int ans = 0;
int gameplay = 1;

/////////////////////////////////////////////////////////  FIND 함수 모음  ////////////////////////////////////////////////////////////////////////////
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
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Init()
{
	int Width = (WIDTH * 2) + 1;
	int Height = HEIGHT + 1;
	char buf[256];
	sprintf(buf, "mode con: lines=%d cols=%d", Height, Width);
	system(buf);

	//for (r = 9; r <= 9; r++)
	//{
	//	x = 0, y = 9;
	//	for (a = 0; a <= 9; a++)
	//	{
	//		for (b = 0; b <= 9; b++)
	//			board[a][b] = map[r][a][b];
	//	}
	//}

	for (r = 9; r <= 9; r++)
	{

	}

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
			else if (map[y][x] == PUSH_BLOCK)
			{
				push_block[map[y][x] - PUSH_BLOCK] = x;
				push_block[map[y][x] - PUSH_BLOCK] = y;
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
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MapDraw()
{
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
			else if (map[y][x] == PUSH_BLOCK)
			{
					printf("□");
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

}

void MoveCheck()
{
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
	}

	int Qindex = Find_QEntry(character[X], character[Y]); // 포탈이동용 인덱스
	if (Qindex != -1)
	{

		switch (Qindex)
		{
		case 0:
			printf("5! 의 값은? : ");
			scanf("%d", &ans);
			if (ans == 120)
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
			scanf("%d", &ans);
			if (ans == 114)
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
			scanf("%d", &ans);
			if (ans == 13)
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



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Move()
{
	char ch;
	ch = _getch();
	system("cls");
	map[character[Y]][character[X]] = NULL;
	switch (ch)
	{
	case LEFT:
		if (map[character[Y]][character[X] - 1] != WALL && Find_BExit(character[X] - 1, character[Y]) == -1)
			character[X]--;
		if (map[character[Y]][character[X]+1] == PUSH_BLOCK)
			push_block[X]--;
		break;
	case RIGHT:
		if (map[character[Y]][character[X] + 1] != WALL && Find_BExit(character[X] + 1, character[Y]) == -1)
			character[X]++;
		if (map[character[Y]][character[X]-1] == PUSH_BLOCK)
			push_block[X]++;
		break;
	case UP:
		if (map[character[Y] - 1][character[X]] != WALL && Find_BExit(character[X], character[Y] - 1) == -1)
			character[Y]--;
		if (map[character[Y]+1][character[X]] == PUSH_BLOCK)
			push_block[Y]--;
		break;
	case DOWN:
		if (map[character[Y] + 1][character[X]] != WALL && Find_BExit(character[X], character[Y] + 1) == -1)
			character[Y]++;
		if (map[character[Y]-1][character[X]] == PUSH_BLOCK)
			push_block[Y]++;
		break;
	}
	MoveCheck();
	map[character[Y]][character[X]] = CHARACTER;

}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void main()
{
	printf("당신은...개미지옥에서.....탈출 가능할까요..?\n");
	printf("============================================\n");
	printf("<<< 게임 설명 >>>\n");
	PUPPLE printf("▣"); ORIGINAL printf(": 버튼입니다-!! \n    밟으면 막혀있던 ");
	PUPPLE printf("▩"); ORIGINAL printf("이 사라져요!!\n");
	GREEN printf("??"); ORIGINAL printf(": 퀴즈타임~!!\n    맞추면");
	GREEN printf("▒"); ORIGINAL printf("로 이동!\n    틀리면 처음부터 ㅠㅠ\n");
	BLUE printf("◎"); ORIGINAL printf(": 순간이동 포탈입니다-!!\n    밟으면");
	YELLOW printf("●");
	ORIGINAL printf("로 이동해요\n");
	printf("============================================\n");

	printf("10초후 게임이 실행됩니다....\n");
	Sleep(1000);
	Init();
	while (gameplay)
	{
		MapDraw();
		Move();
	}
}


