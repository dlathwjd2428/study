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
			printf("�߸��� �� �Դϴ�. �ٽ� �Է����ּ���.");
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
		printf("���� : %d ~ %d", min, max);
		printf("\n���� Turn : %d", turn);

		printf("\n========%d��========\n", i);
		printf("�Է� : ");
		scanf_s("%d", &numput);

		if (numput == answer)
		{
			system("cls");
			printf("����!! �ϼ� : %d\n", i);
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
			printf("<���� : %d> �ּ� �� ���� : ",min);
			scanf_s("%d", &min);

			printf("<���� : %d> �ִ� �� ���� : ", max);
			scanf_s("%d", &max);
			break;
		case 2:
			system("cls");
			printf("<���� : %d> �ִ� Turn �� ���� : ", turn);
			scanf_s("%d", &turn);
			break;
		case 3:
			return 1;

		default:
			printf("�߸��� �� �Դϴ�. �ٽ� �Է����ּ���.");
			Sleep(1000);
			break;
		}
	}
}
int menu()
{
	int ch = 0;

	puts("===========UpDown==========");
	puts("        1. ���ӽ���         ");
	puts("        2. ��������         ");
	puts("        3. ����            ");
	printf("�Է� : ");
	scanf_s("%d", &ch);

	return ch;
}

int system_menu()
{
	int ch = 0;

	puts("=======���� ����=======");
	puts(" 1.�ִ�, �ּҹ��� ����");
	puts(" 2.�ִ� Turn�� ����");
	puts(" 3.���ư���");
	printf("�Է� : ");

	scanf_s("%d", &ch);

	return ch;

}