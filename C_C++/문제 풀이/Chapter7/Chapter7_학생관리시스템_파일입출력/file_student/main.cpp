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
	printf("=====�л��������α׷� (�� �ο� : %d)=====\n", StudentCount);
	printf("	1.�л� ���\n");
	printf("	2.�л� ���(��ȣ��)\n");
	printf("	3.�л� ���(�г��)\n");
	printf("	4.�г� �˻�\n");
	printf("	5.�л� �˻�\n");
	printf("	6.������ �л� ����\n");
	printf("	7.�л� ��ü ����\n");
	printf("	8.�л� ���� ����\n");
	printf("	9.�л� ���� �ҷ�����\n"); //�ҷ����� �� �� �ߺ��ǰ��Ұ��� ���½�Ű�� �ҷ��ð���
	printf("	10.����\n");
	printf("========================================\n");
	printf("[  �Է�  ] : ");
}
void SetStudent(Student* St, int* Number)
{
	St->Number = ++(*Number);
	printf("======%d�� �л�======\n", St->Number);
	printf("�̸� �Է�: ");
	scanf("%s", St->Name);
	printf("���� �Է�: ");
	scanf("%d", &St->Age);
	printf("���� �Է�: ");
	scanf("%s", St->Gender);
	printf("�г� �Է�(1~3) : ");
	scanf("%d", &St->Class);

}
void ShowStudent(Student* St)
{
	printf("==========%s�л� (%d��)=========\n", St->Name, St->Number);
	printf(" ���� : %d, ���� : %s, �г� : %d\n", St->Age, St->Gender, St->Class);
	printf("==============================\n");
}

void ShowClass(Student* Student_List[], int C)
{
	printf("����������������������%d �г⦡��������������������\n", C);
	for (int i = 0; i < StudentCount; i++)
		if (Student_List[i]->Class == C)
			ShowStudent(Student_List[i]);
	printf("��������������������������������������������������������\n");
}

void main()
{
	int play = 1;
	Student* Student_List[MAX]; // �ּҸ� 50�� ����°���
	int Select;
	char Sname[10];
	FILE* f = fopen("STUDENTINDEX.txt", "w");

	while (play)
	{
		system("cls");
		menu(); //�޴����
		scanf("%d", &Select);

		switch (Select)
		{
		case 1: //�л� ��� 
			system("cls");
			if (StudentCount + 1 >= 50)
			{
				printf("�л�����(%d��)�� ��� á���ϴ�.\n");
				system("pause");
				break;
			}
			Student_List[StudentCount] = (Student*)malloc(sizeof(Student)); //�޸��Ҵ��� �ٵ�����
			SetStudent(Student_List[StudentCount], &StudentCount);
			break;

		case 2: //�л����(��ȣ��) 
			system("cls");
			for (int i = 0; i < StudentCount; i++)
				ShowStudent(Student_List[i]);
			system("Pause");
			break;

		case 3: //�л����(�г��)
			system("cls");
			ShowClass(Student_List, 1);
			ShowClass(Student_List, 2);
			ShowClass(Student_List, 3);
			system("Pause");
			break;

		case 4: //�г� �˻� ok
			system("cls");
			printf("�˻��� �г��� �Է��ϼ���: ");
			scanf("%d", &Select);
			printf("����������������������%d �г⦡����������������������\n", Select);
			for (int i = 0; i < StudentCount; i++)
			{
				if (Student_List[i]->Class == Select)
					ShowStudent(Student_List[i]);
			}
			printf("����������������������������������������������������������\n");
			system("Pause");
			break;

		case 5: //�л� �˻� strcmp ok

			system("cls");
			printf("�˻��� �л��� �Է��ϼ���: ");
			scanf("%s", &Sname);
			for (int i = 0; i < StudentCount; i++)
			{
				if (strcmp(Sname, Student_List[i]->Name) == 0)
					ShowStudent(Student_List[i]);
			}
			system("Pause");
			break;

		case 6: // ������ �л� ���� ok
			free(Student_List[StudentCount - 1]);
			StudentCount--;
			break;

		case 7://�л� ��ü ���� ok
			for (int i = 0; i < StudentCount; i++)
				free(Student_List[i]);
			StudentCount = 0;
			break;
		case 8:
			system("cls");
			fprintf(f, "��ϵ� �л��� : %d\n\n", StudentCount);
			for (int i = 0; i < StudentCount; i++)
				fprintf(f, "%s %d %s %d\n", Student_List[i]->Name, Student_List[i]->Age, Student_List[i]->Gender, Student_List[i]->Class);
			fclose(f);
			printf("������ �Ϸ�Ǿ����ϴ�. \n");
			system("Pause");
			break;
		case 9:
			f = fopen("STUDENTINDEX.txt", "r");
			if (f == NULL)
				printf("������ �����Ͱ� �����ϴ�, \n");
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
				printf("�ҷ����Ⱑ �Ϸ�Ǿ����ϴ�. \n");
				system("Pause");
			}
			break;

		case 10: //����
			for (int i = 0; i < StudentCount; i++)
			{
				printf("%s�л� �����Ҵ� ���� �Ϸ�\n", Student_List[i]->Name);
				free(Student_List[i]);
			}
			StudentCount = 0;
			play = 0;
			return;

		}
	}
}
