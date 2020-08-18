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
	printf("이름입력 : ");
	scanf("%s", P->name);
	printf("나이입력 : ");
	scanf("%d", &P->age);
	printf("키입력 : ");
	scanf("%f", &P->height);
	printf("==============\n");
}


void ShowPeople(People P)
{
	printf("======%d======\n");
	printf("1.이름 : %s\n", P.name);
	printf("2.나이 : %d\n", P.age);
	printf("3.키 : %.2f\n", P.height);
	printf("==============\n");
}

