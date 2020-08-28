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
void FineStudent(Student* Student_List[]);
void ShowGrade(Student* Student_List[], int grade);
void file_w(Student* Student_List[]);
void file_r(Student* Student_List[]);

int StudentCount = 0;

void main()
{
	Student* Student_List[MAX];
	int ch = 0;


	while (1)
	{
		switch (menu())
		{
		case 1: //학생 등록
			if (StudentCount + 1 >= 50)
			{
				printf("학생정원(%d명)이 모두 찼습니다.\n");
				system("pause");
				break;
			}
			Student_List[StudentCount] = (Student*)malloc(sizeof(Student));
			SetStudent(Student_List[StudentCount], &StudentCount);
			break;

		case 2: //학생목록(번호순)
			system("cls");
			for (int i = 0; i < StudentCount; i++)
				ShowStudent(Student_List[i]);
			system("pause");
			break;

		case 3: //학생목록(학년순)
			system("cls");
			ShowGrade(Student_List, 1);
			ShowGrade(Student_List, 2);
			ShowGrade(Student_List, 3);
			system("Pause");
			break;

		case 4: //학년 검색
			system("cls");
			printf("검색할 학년을 입력하세요: ");
			scanf("%d", &ch);

			while (1)
			{
				if (ch > 3 || ch < 1)
				{
					printf("1~3학년까지 존재합니다. 다시 입력해주세요\n");
					system("Pause");
					ch = 0;
					system("cls");
					printf("학년 입력 : ");
					scanf("%d", &ch);
				}
				else
				{
					ShowGrade(Student_List, ch);
					break;
				}
			}


			system("Pause");

			break;

		case 5: //학생 검색
			system("cls");
			FineStudent(Student_List);
			system("Pause");
			break;

		case 6: //마지막 학생 삭제
			if (StudentCount <= 0)
			{
				printf("삭제할 데이터가 없습니다.");
				system("pause");
			}
			else
			{
				printf("%s 학생의 정보가 삭제되었습니다.", Student_List[StudentCount - 1]->Name);
				free(Student_List[StudentCount - 1]);
				StudentCount--;
				system("pause");
			}
			break;

		case 7: //학생 전체 삭제
			if (StudentCount <= 0)
			{
				printf("삭제할 데이터가 없습니다.\n");
				system("pause");
			}
			else
			{
				for (int i = 0; i < StudentCount; i++)
					free(Student_List[i]);

				StudentCount = 0;

				printf("생기부 초기화\n");
				system("pause");
			}
			break;

		case 8: //학생정보 저장
			system("cls");
			file_w(Student_List);
			break;

		case 9: //학생정보 불러오기			
			file_r(Student_List);
			break;

		case 10: //종료
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
	printf("   8.학생정보 저장\n");
	printf("   9.학생정보 불러오기\n");
	printf("   10.종료\n");
	printf("    입력 : ");
	scanf("%d", &ch);

	return ch;
}

void file_w(Student* Student_List[])
{

	FILE* fw = fopen("StudentFile.txt", "w");

	fprintf(fw, "%d\n", StudentCount);
	for (int i = 0; i < StudentCount; i++)
		fprintf(fw, "%s %d %s %d\n", Student_List[i]->Name, Student_List[i]->Age, Student_List[i]->Gender, Student_List[i]->Class);
	fclose(fw);

	printf("저장이 완료되었습니다. \n");
	system("Pause");
}

void file_r(Student* Student_List[])
{
	FILE* fr = fopen("StudentFile.txt", "r");

	if (fr == NULL)
		printf("가져올 데이터가 없습니다, \n");
	else
	{
		fscanf(fr, "%d", &StudentCount);
		int i = StudentCount;
		while (!feof(fr))
		{
			Student_List[StudentCount] = (Student*)malloc(sizeof(Student));

			fscanf(fr, "%s", Student_List[i]->Name);
			fscanf(fr, "%d", &Student_List[i]->Age);
			fscanf(fr, "%s", Student_List[i]->Gender);
			fscanf(fr, "%d", &Student_List[i]->Class);
			i++;
		}
		StudentCount += i;
		fclose(fr);
		printf("불러오기가 완료되었습니다. \n");
		system("Pause");
	}
}

void ShowStudent(Student* St)
{
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
	while (1)
	{
		if (St->Class < 1 || St->Class > 3)
		{
			printf("1~3학년까지 존재합니다. 다시 입력해주세요\n");
			St->Class = { 0 };
			printf("학년 입력 : ");
			scanf("%d", &St->Class);
		}
		else
			break;
	}


}

void FineStudent(Student* Student_List[])
{
	char fine_name[20] = { 0 };
	printf("검색할 이름 입력 : ");
	scanf("%s", fine_name);
	for (int i = 0; i < StudentCount; i++)
	{
		if (strcmp(fine_name, Student_List[i]->Name) == 0)
		{
			ShowStudent(Student_List[i]);
		}
		else
		{
			printf("해당 학생이 없습니다.");
			system("pause");
		}

	}
}

void ShowGrade(Student* Student_List[], int grade)
{
	printf("┏──────────%d 학년──────────┓\n", grade);
	for (int i = 0; i < StudentCount; i++)
		if (Student_List[i]->Class == grade)
			ShowStudent(Student_List[i]);
	printf("┗──────────────────────────┛\n");
}


