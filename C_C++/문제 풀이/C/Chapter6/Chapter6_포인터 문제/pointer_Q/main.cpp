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
	printf("1. 문자열을 입력하세요 : ");
	scanf("%s", &Q1_1);
	printf("함수 호출 전 = %s", Q1_1);
	Q1(Q1_1);

	printf("\n함수 호출 후 = %s", Q1_1);

	//------------------Q2-----------------
	printf("\n\n2. 두 수를 입력하세요 : ");
	scanf("%d %d", &Q2_1,&Q2_2);

	Q2(&Q2_1,&Q2_2);
	printf("%d보다 %d이 크다", Q2_1, Q2_2);

	//------------------Q3-----------------
	printf("\n\n3. 정수를 입력하시오 : ");
	scanf("%d", &Q3_1);
	printf("1 ~ %d의 총 합 : ", Q3_1);
	Q3(&Q3_1);
	printf("= %d",Q3_1);

	//------------------Q4-----------------
	printf("\n\n4. 오름차순 정렬\n");
	for (int i = 0; i < 8; i++)
	{
		printf("[%d]번째 정수 입력 : ", i+1);
		scanf("%d", &Q4_1[i]);
	}

	printf("정렬 전 : ");
	for (int i = 0; i < 8; i++)
	{
		printf("%d ", *(Q4_1 + i));
	}

	Q4(Q4_1);
	printf("정렬 후 : ");
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




