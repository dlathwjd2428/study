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

int StudentCount = 0;

void main()
{
	Student* Student_List[MAX];
	int ch = 0;

	while (1)
	{
		switch (menu())
		{
		case 1:
			if (StudentCount + 1 >= 50)
			{
				printf("�л�����(%d��)�� ��� á���ϴ�.\n");
				system("pause");
				break;
			}
			Student_List[StudentCount] = (Student*)malloc(sizeof(Student));
			SetStudent(Student_List[StudentCount], &StudentCount);
			break;

		case 2:
			system("cls");
			for (int i = 0; i < StudentCount; i++)
				ShowStudent(Student_List[i]);
			system("pause");
			break;

		case 3:
			system("cls");
			ShowGrade(Student_List, 1);
			ShowGrade(Student_List, 2);
			ShowGrade(Student_List, 3);
			system("Pause");
			break;

		case 4:
			system("cls");
			printf("�˻��� �г��� �Է��ϼ���: ");
			scanf("%d", &ch);
			
			while (1)
			{
				if (ch > 3 || ch < 1)
				{
					printf("1~3�г���� �����մϴ�. �ٽ� �Է����ּ���\n");
					system("Pause");
					ch = 0;
					system("cls");
					printf("�г� �Է� : ");
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

		case 5:
				system("cls");
				FineStudent(Student_List);
				system("Pause");
			break;

		case 6:
			if (StudentCount <= 0)
			{
				printf("������ �����Ͱ� �����ϴ�.");
				system("pause");
			}
			else
			{
				printf("%s �л��� ������ �����Ǿ����ϴ�.", Student_List[StudentCount - 1]->Name);
				free(Student_List[StudentCount - 1]);
				StudentCount--;
				system("pause");
			}			
			break;

		case 7:
			if (StudentCount <= 0)
			{
				printf("������ �����Ͱ� �����ϴ�.\n");
				system("pause");
			}
			else
			{
				for (int i = 0; i < StudentCount; i++)
					free(Student_List[i]);

				StudentCount = 0;

				printf("����� �ʱ�ȭ\n");
				system("pause");
			}		
			break;

		case 8:
			for (int i = 0; i < StudentCount; i++)
			{
				printf("%s�л� �����Ҵ� ���� �Ϸ�\n", Student_List[i]->Name);
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
	printf("=====�л��������α׷�=====(�� �ο� : %d)\n", StudentCount);
	printf("   1.�л� ���\n");
	printf("   2.�л� ���<��ȣ��>\n");
	printf("   3.�л� ���<�г��>\n");
	printf("   4.�г� �˻�\n");
	printf("   5.�л� �˻�\n");
	printf("   6.������ �л� ����\n");
	printf("   7.�л� ��ü ����\n");
	printf("   8.����\n");
	printf("    �Է� : ");
	scanf("%d", &ch);

	return ch;
}

void ShowStudent(Student* St)
{
	printf("======%s�л�(%d��)======\n", St->Name, St->Number);
	printf("���� : %d,  ���� : %s,  �г� : %d\n", St->Age, St->Gender, St->Class);
	printf("======================\n");
}
void SetStudent(Student* St, int* Number)
{
	system("cls");
	St->Number = ++(*Number);
	printf("======%d�� �л�======\n", St->Number);
	printf("�̸� �Է� : ");
	scanf("%s", St->Name);
	printf("���� �Է� : ");
	scanf("%d", &St->Age);
	printf("���� �Է� : ");
	scanf("%s", St->Gender);
	printf("�г� �Է� : ");
	scanf("%d", &St->Class);
	while (1)
	{
		if (St->Class < 1 || St->Class > 3)
		{
			printf("1~3�г���� �����մϴ�. �ٽ� �Է����ּ���\n");
			St->Class = { 0 };
			printf("�г� �Է� : ");
			scanf("%d", &St->Class);
		}
		else
			break;
	}


}

void FineStudent(Student* Student_List[])
{
	char fine_name[20] = { 0 };
	printf("�˻��� �̸� �Է� : ");
	scanf("%s", fine_name);
	for (int i = 0; i < StudentCount; i++)
	{
		if (strcmp(fine_name, Student_List[i]->Name) == 0)
			ShowStudent(Student_List[i]);
	}
}

void ShowGrade(Student* Student_List[], int grade)
{
		printf("����������������������%d �г⦡��������������������\n", grade);
		for (int i = 0; i < StudentCount; i++)
			if (Student_List[i]->Class == grade)
				ShowStudent(Student_List[i]);
		printf("��������������������������������������������������������\n");
}


