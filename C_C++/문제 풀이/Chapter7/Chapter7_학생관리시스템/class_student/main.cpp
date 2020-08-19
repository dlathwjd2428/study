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
				printf("�л�����(%d��)�� ��� á���ϴ�.\n");
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
	system("cls");
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
}

void FineStudent(Student* St)
{
	char fine_name[20] = { 0 };
	printf("�˻��� �̸� �Է� : ");
	scanf("%s", fine_name);
	printf("Name1 == Name2 : %d\n", strcmp(fine_name, ));

}