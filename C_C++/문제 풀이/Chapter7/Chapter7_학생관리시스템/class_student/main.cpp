#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#define MAX 50

typedef struct student
{
	char Name[10];
	int Age;
	int Class;
	int Number;
	char Gender[10];
}Student;

int menu();
void SetStudent(Student* St, int* Number);
void ShowStudent(Student* St);
void FineStudent(Student* St);

int StudentCount = 0;


void main()
{
	Student* Student_List[MAX];

	while (1)
	{
		switch (menu())
		{
		case 1:
			if (StudentCount + 1 >= 50)
			{
				printf("학생정원(%d명)이 모두 찼습니다.\n");
				system("pause");
				break;
			}
			Student_List[StudentCount] = (Student*)malloc(sizeof(Student));
			SetStudent(Student_List[StudentCount], &StudentCount);
			break;

		case 2:
			for (int i = 0; i < StudentCount; i++)
				ShowStudent(Student_List[i]);
			system("pause");
			break;

		case 3:
			break;

		case 4:
			break;

		case 5:
			for (int i = 0; i < StudentCount; i++)
				FineStudent(Student_List[i]);
			break;

		case 6:
			StudentCount--;
			break;

		case 7:
			StudentCount = 0;
			break;

		case 8:
			for (int i = 0; i < StudentCount; i++)
			{
				printf("%s학생 동적할당 해제 완료\n", Student_List[i]->Name);
				free(Student_List[i]);
			}
			return;
		}
	}
}

int menu()
{
	int ch = 0;

	system("cls");
	printf("=====학생관리프로그램=====(총 인원 : %d)\n", StudentCount);
	printf("   1.학생 등록\n");
	printf("   2.학생 목록<번호순>\n");
	printf("   3.학생 목록<학년순>\n");
	printf("   4.학년 검색\n");
	printf("   5.학생 검색\n");
	printf("   6.마지막 학생 삭제\n");
	printf("   7.학생 전체 삭제\n");
	printf("   8.종료\n");
	printf("    입력 : ");
	scanf("%d", &ch);

	return ch;
}

void ShowStudent(Student* St)
{
	system("cls");
	printf("======%s학생(%d번)======\n", St->Name, St->Number);
	printf("나이 : %d,  성별 : %s,  학년 : %d\n", St->Age, St->Gender, St->Class);
	printf("======================\n");
}
void SetStudent(Student* St, int* Number)
{
	system("cls");
	St->Number = ++(*Number);
	printf("======%d번 학생======\n", St->Number);
	printf("이름 입력 : ");
	scanf("%s", St->Name);
	printf("나이 입력 : ");
	scanf("%d", &St->Age);
	printf("성별 입력 : ");
	scanf("%s", St->Gender);
	printf("학년 입력 : ");
	scanf("%d", &St->Class);
}

void FineStudent(Student* St)
{
	char fine_name[20] = { 0 };
	printf("검색할 이름 입력 : ");
	scanf("%s", fine_name);
	printf("Name1 == Name2 : %d\n", strcmp(fine_name, ));

}