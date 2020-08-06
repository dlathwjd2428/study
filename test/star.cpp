#include <stdio.h>

int main()
{
	int star = 0;

	printf("몇개의 별을 입력하시겠습니까?");
	scanf_s("%d", &star);

	int blank = star;
	for (int i = 0; i < blank; i++)
	{	
		for (int j = 0; j < star; j++)
		{
			printf(" "); 
			
		}
		for (int k = 0; k < blank-star ;k++)
		{
			printf(" *");
		}		
		printf("\n");
		blank == star--;
	}
}