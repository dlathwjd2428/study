#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include <stdlib.h>

int menu();
int game_system();
int system_menu();
void Ingame();

int turn = 10;
int min = 1;
int max = 100;

int main()
{
	srand((unsigned)time(NULL));
	while (1)
	{
		system("cls");
		switch (menu())
		{
		case 1:
			Ingame();
			break;
		case 2:			
			game_system();		
			break;
		case 3:
			return 1;

		default:
			printf("잘못된 수 입니다. 다시 입력해주세요.");
			Sleep(1000);
			break;
		}
	}
	
}

void Ingame()
{
	int answer = rand() % max + min;

	for (int i = 1; i <= turn; i++)
	{
		int numput = 0;
		system("cls");
		printf("범위 : %d ~ %d", min, max);
		printf("\n제한 Turn : %d", turn);

		printf("\n========%d턴========\n", i);
		printf("입력 : ");
		scanf_s("%d", &numput);

		if (numput == answer)
		{
			system("cls");
			printf("정답!! 턴수 : %d\n", i);
		}
		else if (numput < answer)
		{
			printf("UP!!\n");
		}
		else
		{
			printf("Down!!\n");
		}
		system("pause");
	}
}
int game_system()
{
	while (1)
	{
		system("cls");
		switch (system_menu())
		{
		case 1:
			system("cls");
			printf("<현재 : %d> 최소 값 변경 : ",min);
			scanf_s("%d", &min);

			printf("<현재 : %d> 최대 값 변경 : ", max);
			scanf_s("%d", &max);
			break;
		case 2:
			system("cls");
			printf("<현재 : %d> 최대 Turn 값 변경 : ", turn);
			scanf_s("%d", &turn);
			break;
		case 3:
			return 1;

		default:
			printf("잘못된 수 입니다. 다시 입력해주세요.");
			Sleep(1000);
			break;
		}
	}
}
int menu()
{
	int ch = 0;

	puts("===========UpDown==========");
	puts("        1. 게임시작         ");
	puts("        2. 범위설정         ");
	puts("        3. 종료            ");
	printf("입력 : ");
	scanf_s("%d", &ch);

	return ch;
}

int system_menu()
{
	int ch = 0;

	puts("=======게임 설정=======");
	puts(" 1.최대, 최소범위 설정");
	puts(" 2.최대 Turn수 설정");
	puts(" 3.돌아가기");
	printf("입력 : ");

	scanf_s("%d", &ch);

	return ch;

}