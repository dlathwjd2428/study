#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void Q1(char *Q1_1);
void Q2(int *Q2_1, int *Q2_2);
void Q3(int *Q3_1);
void Q4(int *Q4_1);

void main()
{
	char Q1_1[20] = {0};
	int Q2_1 = 0, Q2_2 = 0;
	int Q3_1 = 0;
	int Q4_1[8] = {0};

	//------------------Q1-----------------
	printf("1. ���ڿ��� �Է��ϼ��� : ");
	scanf("%s", &Q1_1);
	printf("�Լ� ȣ�� �� = %s", Q1_1);
	Q1(Q1_1);

	printf("\n�Լ� ȣ�� �� = %s", Q1_1);

	//------------------Q2-----------------
	printf("\n\n2. �� ���� �Է��ϼ��� : ");
	scanf("%d %d", &Q2_1,&Q2_2);

	Q2(&Q2_1,&Q2_2);
	printf("%d���� %d�� ũ��", Q2_1, Q2_2);

	//------------------Q3-----------------
	printf("\n\n3. ������ �Է��Ͻÿ� : ");
	scanf("%d", &Q3_1);
	printf("1 ~ %d�� �� �� : ", Q3_1);
	Q3(&Q3_1);
	printf("= %d",Q3_1);

	//------------------Q4-----------------
	printf("\n\n4. �������� ����\n");
	for (int i = 0; i < 8; i++)
	{
		printf("[%d]��° ���� �Է� : ", i+1);
		scanf("%d", &Q4_1[i]);
	}

	printf("���� �� : ");
	for (int i = 0; i < 8; i++)
	{
		printf("%d ", *(Q4_1 + i));
	}

	Q4(Q4_1);
	printf("���� �� : ");
	for (int i = 0; i < 8; i++)
	{
		printf("%d ", *(Q4_1 + i));
	}

}

void Q1(char *Q1_1)
{
	for(int i =0 ; *(Q1_1+i) != 0 ; i++)
	{
		if (*(Q1_1 + i) >= 'a' && *(Q1_1 + i) <= 'z')
			*(Q1_1 + i) -= 32;
	}		
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

void Q4(int *Q4_1)
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




