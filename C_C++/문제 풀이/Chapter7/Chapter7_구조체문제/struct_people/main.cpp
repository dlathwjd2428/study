#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct people
{
	char name[20] = { 0 };
	int age = 0;
	float height = 0;
}People;

void ShowPeople(People P);
void SetPeople(People* P);

void main()
{
	People Max_People[5];
	for (int i = 0; i < 5; i++)
	{
		system("cls");
		SetPeople(&Max_People[i]);	
		
	}
	system("cls");
	for (int i = 0; i < 5; i++)
	{
		ShowPeople(Max_People[i]);
	}
}

void SetPeople(People* P)
{
	printf("======%d======\n");
	printf("�̸��Է� : ");
	scanf("%s", P->name);
	printf("�����Է� : ");
	scanf("%d", &P->age);
	printf("Ű�Է� : ");
	scanf("%f", &P->height);
	printf("==============\n");
}


void ShowPeople(People P)
{
	printf("======%d======\n");
	printf("1.�̸� : %s\n", P.name);
	printf("2.���� : %d\n", P.age);
	printf("3.Ű : %.2f\n", P.height);
	printf("==============\n");
}

