#include <stdio.h>
#include <conio.h>
#include <windows.h>


enum {
	INPUT_NAME = 1,
	INPUT_NUM,
	NAME,
	PLUS_NUM,
	MEAN,
	GPA,
	EXIT
};

int Menu();


void main()
{
	char name[20] = {NULL};
	int num1 = -1;
	int num2 = -1;
	int num3 = -1;
	float result = -1;

	while (TRUE)
	{
		system("cls");
		switch (Menu())
		{
		case INPUT_NAME:
			printf("학생이름을 입력하세요...");
			scanf_s("%s", name, 20);

			break;

		case INPUT_NUM:
			printf("3과목의 성적을 입력하세요...");
			scanf_s("%d %d %d", &num1, &num2, &num3);

			result = (num1 + num2 + num3) / 3.0f;

			break;

		case NAME:
			if (strlen(name) == 0)
			{
				printf("이름이 없습니다. 이름을 입력해주세요\n");
			}
			else
			{
				printf("학생 이름은 %s입니다.\n", name);
			}			
			system("pause");
			break;

		case PLUS_NUM:
			if (num1 == -1|| num2 ==-2 || num3 == -1)
			{
				printf("성적을 입력해주세요\n");
			}
			else
			{
				printf("성적 : %d %d %d\n", num1, num2, num3);
				printf("합계 : %d\n", num1 + num2 + num3);
			}
			
			system("pause");
			break;

		case MEAN:
			if (result == -1)
			{
				printf("성적을 입력해주세요\n");
			}
			else
			{
				
				printf("\n%s 학생의 평균 : %f\n", name, result);
			}
			
			system("pause");
			break;

		case GPA:
			if (result >= 90)
			{
				printf("A");
			}
			else if (result < 90 && result >= 80)
			{
				printf("B");
			}
			else if (result < 80 && result >= 70)
			{
				printf("C");
			}
			else if (result < 70 && result >= 60)
			{
				printf("D");
			}
			else if (result == -1)
			{
				printf("성적을 입력해주세요.");
			}
			else
			{
				printf("F");
			}
			system("pause");
			break;

		case EXIT:
			exit(0);

			break;

		default: //case말고 나머지들
			puts("잘못 입력하셨습니다. 다시 입력해주세요.");

			Sleep(1000);
		}
	}

}

int Menu()
{
	int choice;
	puts("=================================");
	puts("             M e n u             ");
	puts("=================================");
	puts("        1. 학생이름 입력         ");
	puts("        2. 성적 3과목 입력       ");
	puts("        3. 학생이름 출력         ");
	puts("        4. 합계 출력             ");
	puts("        5. 평균 출력             ");
	puts("        6. 학점 출력             ");
	puts("        7. 종료                  ");
	puts("=================================");

	printf("원하시는 버튼을 입력해주세요. :  ");
	scanf_s("%d", &choice);

	return choice;
}