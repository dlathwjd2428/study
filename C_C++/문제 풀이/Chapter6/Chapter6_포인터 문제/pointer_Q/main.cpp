#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void Q1(char *Q1_1);
void Q2(int *Q2_1, int *Q2_2);
void Q3(int *Q3_1);

void main()
{
	char Q1_1[20] = {};
	int Q2_1 = 0, Q2_2 = 0;
	int Q3_1 = 0;
	int Q4[8] = {};

	//------------------Q1-----------------
	printf("���ڿ��� �Է��ϼ��� : ");
	scanf("%s", Q1_1);
	Q1(Q1_1);

	printf("%s", Q1_1);

	//------------------Q2-----------------
	printf("\n�� ���� �Է��ϼ��� : ");
	scanf("%d %d", &Q2_1,&Q2_2);

	Q2(&Q2_1,&Q2_2);
	printf("%d���� %d�� ũ��", Q2_1, Q2_2);

	//------------------Q3-----------------
	printf("\n�ϳ��� ���� �Է����ּ���.");
	scanf("%d", &Q3_1);
	printf("1���� %d������ �� ", Q3_1);
	Q3(&Q3_1);
	printf("= %d",Q3_1);

	//------------------Q4-----------------
	printf("\n8���� ���� �Է����ּ��� : ");
	for (int i = 0; i < 8; i++)
	{
		scanf("%d", Q4[i]);		
	}

}

void Q1(char *Q1_1)
{
		if ((*Q1_1) >= 'a' && (*Q1_1) <= 'z')
			(*Q1_1) -= 32;	
}

void Q2(int *Q2_1, int *Q2_2)
{
	int temp;

	if (*Q2_1 > *Q2_2)
	{
		temp = *Q2_1;
		*Q2_1 = *Q2_2;
		*Q2_2 = temp;
	}
}

void Q3(int *Q3_1)
{
	int add = 0;
	for (int i = 1 ;i <= *Q3_1; i++)
	{
		add = add + i;
	}

	*Q3_1 = add;
}

void Q4(int Q4_1[])
{
	int temp = 0;

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (Q4_1[i] < Q4_1[j])
			{
				temp = Q4_1[i];
				Q4_1[i] = Q4_1[j];
				Q4_1[j] = temp;
			}
		}
	}
}




