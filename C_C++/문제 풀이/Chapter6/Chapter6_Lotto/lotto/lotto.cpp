#include<stdio.h>
#include<stdlib.h>
#include<time.h>//�ð� �� ����ϴ� �������
#define LOTTO_NUM 6

void main()
{
	int RNum;
	int Lotto[LOTTO_NUM] = { 0 };
	srand((unsigned)time(NULL));

	while (1)
	{
		system("cls");
		for (int i = 0; i < LOTTO_NUM; i++)
		{
			RNum = (rand() % 45) + 1;
			Lotto[i] = RNum;

			if (i != 0)
			{
				for (int j = 0; j < LOTTO_NUM - 1; j++)
				{
					if (Lotto[i] == Lotto[j])
					{
						i--;
						break;
					}
				}
			}
			
		}
		
		for (int i = 0; i < LOTTO_NUM; i++)
			printf("%d.%d\n",i+1, Lotto[i]);
		//printf("\b ");
		system("pause");
	}
}
