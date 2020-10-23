#include<stdio.h>
#include<stdlib.h>
#include<time.h>//시간 값 사용하는 헤더파일
#define LOTTO_NUM 6

void main()
{
	int Lotto[LOTTO_NUM] = { 0 };

		//system("cls");
	while (1)
	{
		system("cls");
			srand(time(NULL));  
			for (int i = 0; i <= LOTTO_NUM; i++)
			{                                     
				Lotto[i] = ((rand() % 45) + 1); 

				for (int j = 0; j < i; j++)
				{
					if (Lotto[i] == Lotto[j])
					{
						i--;
					}
				}
			}

		for (int i = 0; i < LOTTO_NUM; i++)
			printf("%d.%d\n", i + 1, Lotto[i]);
		//printf("\b ");
		system("pause");
	}
		

		
}
		
		