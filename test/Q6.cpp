#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

enum {
	START = 1,
	GRADE,
	EXIT
};
int Menu();

void main()
{
	srand(time(NULL));

	int result = rand();
	int num;
	int count = 0;

	while (TRUE)
	{
		system("cls");
		switch (Menu())
		{
		case START:
			while (1)
			{
				printf("���ϴ� ���ڸ� �Է��ϼ��� : ");
				scanf_s("%d", &num);

				count++;

				if (result > num)
				{
					puts("up");
				}
				else if (result < num)
				{
					puts("down");
				}
				else
				{
					puts("�����Դϴ�.");
					system("pause");
					break;
				}
			}
			break;

		case GRADE:
			printf("�ְ������� %dȸ �Դϴ�.", count);
			system("pause");

			break;

		case EXIT:
			exit(0);

			break;

		default: 
			puts("�߸� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���.");

			Sleep(1000);
		}
	}
}

int Menu()
{
	int choice;
	puts("== = �� & �ٿ� ���� == =");
	puts("    1. ���ӽ���         ");
	puts("    2. ��������         ");
	puts("    3. ���ӳ�����       ");
	printf("> ");
	scanf_s("%d", &choice);

	return choice;
}

