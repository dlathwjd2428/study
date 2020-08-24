#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<string.h>
#define MAX 50

typedef struct student
{
	char Name[10];
	int Age;
	int Class;
	int Number;
	char Gender[10];
}Student;
int StudentCount = 0;
void menu()
{
	printf("=====학생관리프로그램 (총 인원 : %d)=====\n", StudentCount);
	printf("	1.학생 등록\n");
	printf("	2.학생 목록(번호순)\n");
	printf("	3.학생 목록(학년순)\n");
	printf("	4.학년 검색\n");
	printf("	5.학생 검색\n");
	printf("	6.마지막 학생 삭제\n");
	printf("	7.학생 전체 삭제\n");
	printf("	8.학생 정보 저장\n");
	printf("	9.학생 정보 불러오기\n"); //불러오기 할 때 중복되게할건지 리셋시키고 불러올건지
	printf("	10.종료\n");
	printf("========================================\n");
	printf("[  입력  ] : ");
}
void SetStudent(Student* St, int* Number)
{
	St->Number = ++(*Number);
	printf("======%d번 학생======\n", St->Number);
	printf("이름 입력: ");
	scanf("%s", St->Name);
	printf("나이 입력: ");
	scanf("%d", &St->Age);
	printf("성별 입력: ");
	scanf("%s", St->Gender);
	printf("학년 입력(1~3) : ");
	scanf("%d", &St->Class);

}
void ShowStudent(Student* St)
{
	printf("==========%s학생 (%d번)=========\n", St->Name, St->Number);
	printf(" 나이 : %d, 성별 : %s, 학년 : %d\n", St->Age, St->Gender, St->Class);
	printf("==============================\n");
}

void ShowClass(Student* Student_List[], int C)
{
	printf("┏──────────%d 학년──────────┓\n", C);
	for (int i = 0; i < StudentCount; i++)
		if (Student_List[i]->Class == C)
			ShowStudent(Student_List[i]);
	printf("┗──────────────────────────┛\n");
}

void main()
{
	int play = 1;
	Student* Student_List[MAX]; // 주소를 50개 만든는거임
	int Select;
	char Sname[10];
	FILE* f = fopen("STUDENTINDEX.txt", "w");

	while (play)
	{
		system("cls");
		menu(); //메뉴출력
		scanf("%d", &Select);

		switch (Select)
		{
		case 1: //학생 등록 
			system("cls");
			if (StudentCount + 1 >= 50)
			{
				printf("학생정원(%d명)이 모두 찼습니다.\n");
				system("pause");
				break;
			}
			Student_List[StudentCount] = (Student*)malloc(sizeof(Student)); //메모리할당을 다따로함
			SetStudent(Student_List[StudentCount], &StudentCount);
			break;

		case 2: //학생목록(번호순) 
			system("cls");
			for (int i = 0; i < StudentCount; i++)
				ShowStudent(Student_List[i]);
			system("Pause");
			break;

		case 3: //학생목록(학년순)
			system("cls");
			ShowClass(Student_List, 1);
			ShowClass(Student_List, 2);
			ShowClass(Student_List, 3);
			system("Pause");
			break;

		case 4: //학년 검색 ok
			system("cls");
			printf("검색할 학년을 입력하세요: ");
			scanf("%d", &Select);
			printf("┏──────────%d 학년───────────┓\n", Select);
			for (int i = 0; i < StudentCount; i++)
			{
				if (Student_List[i]->Class == Select)
					ShowStudent(Student_List[i]);
			}
			printf("┗───────────────────────────┛\n");
			system("Pause");
			break;

		case 5: //학생 검색 strcmp ok

			system("cls");
			printf("검색할 학생을 입력하세요: ");
			scanf("%s", &Sname);
			for (int i = 0; i < StudentCount; i++)
			{
				if (strcmp(Sname, Student_List[i]->Name) == 0)
					ShowStudent(Student_List[i]);
			}
			system("Pause");
			break;

		case 6: // 마지막 학생 삭제 ok
			free(Student_List[StudentCount - 1]);
			StudentCount--;
			break;

		case 7://학생 전체 삭제 ok
			for (int i = 0; i < StudentCount; i++)
				free(Student_List[i]);
			StudentCount = 0;
			break;
		case 8:
			system("cls");
			fprintf(f, "등록된 학생수 : %d\n\n", StudentCount);
			for (int i = 0; i < StudentCount; i++)
				fprintf(f, "%s %d %s %d\n", Student_List[i]->Name, Student_List[i]->Age, Student_List[i]->Gender, Student_List[i]->Class);
			fclose(f);
			printf("저장이 완료되었습니다. \n");
			system("Pause");
			break;
		case 9:
			f = fopen("STUDENTINDEX.txt", "r");
			if (f == NULL)
				printf("가져올 데이터가 없습니다, \n");
			else
			{
				int i = StudentCount;
				while (!feof(f))
				{
					fscanf(f, "%s", Student_List[i]->Name);
					fscanf(f, "%d", &Student_List[i]->Age);
					fscanf(f, "%s", Student_List[i]->Gender);
					fscanf(f, "%d", &Student_List[i]->Class);
					i++;
				}
				StudentCount += i;
				fclose(f);
				printf("불러오기가 완료되었습니다. \n");
				system("Pause");
			}
			break;

		case 10: //종료
			for (int i = 0; i < StudentCount; i++)
			{
				printf("%s학생 동적할당 해제 완료\n", Student_List[i]->Name);
				free(Student_List[i]);
			}
			StudentCount = 0;
			play = 0;
			return;

		}
	}
}
