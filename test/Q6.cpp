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
				printf("원하는 숫자를 입력하세요 : ");
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
					puts("정답입니다.");
					system("pause");
					break;
				}
			}
			break;

		case GRADE:
			printf("최고점수는 %d회 입니다.", count);
			system("pause");

			break;

		case EXIT:
			exit(0);

			break;

		default: 
			puts("잘못 입력하셨습니다. 다시 입력해주세요.");

			Sleep(1000);
		}
	}
}

int Menu()
{
	int choice;
	puts("== = 업 & 다운 게임 == =");
	puts("    1. 게임시작         ");
	puts("    2. 게임전적         ");
	puts("    3. 게임끝내기       ");
	printf("> ");
	scanf_s("%d", &choice);

	return choice;
}

