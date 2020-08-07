#include <stdio.h>
#include <Windows.h>

int menu();

void main()
{
	char name[20] = { 0 };
	int Kor = 0, Math = 0, Eng = 0;
	float avg = 0.f;	

	while (1)
	{
		system("cls");
		switch (menu())
		{
		case 1:
			system("cls");
			printf("이름 입력 : ");
			scanf_s("%s", &name, 20);
			break;

		case 2:
			system("cls");
			printf("세 과목의 성적을 입력하시오\n");
			printf("국어 : "); scanf_s("%d", &Kor);
			printf("수학 : "); scanf_s("%d", &Math);
			printf("영어 : "); scanf_s("%d", &Eng);
			break;

		case 3:
			system("cls");
			if (name != 0 && Kor != 0 && Math != 0 && Eng != 0)
			{
				avg = (Kor + Math + Eng) / 3.0f;

				puts("====================");
				printf("%s님의 점수\n",name);
				printf("\n국어 점수 : %d", Kor);
				printf("\n수학 점수 : %d", Math);
				printf("\n영어 점수 : %d ", Eng);
				printf("\n합계 점수 : %d ", Kor + Math + Eng);
				printf("\n평균 점수 : %.2f ", avg);
				puts("====================");
		
			}
			else
			{
				if (name == 0||)
				{
					printf("이름을 입력하세요");
				}
				else
				{
					printf("점수를 입력하세요");
				}
			}

			system("pause");

			break;
			

		default:
			printf("잘못된 수 입니다. 다시 입력해주세요.");
			Sleep(1000);
			break;
		}
	}
}

int menu()
{
	int choose = 0;

	puts("====================");
	puts("    학생성적관리      ");
	puts("====================");
	puts("  1. 학생 이름등록    ");
	puts("  2. 3과목 점수등록   ");
	puts("  3. 점수확인        ");
	puts("  4. 종료           ");
	puts("====================");
	printf("입력 : ");

	scanf_s("%d", &choose);

	return choose;
}
