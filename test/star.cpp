#include <stdio.h>

int main()
{
	int star = 0;
	int blank = 0;
	printf("��� ���� �Է��Ͻðڽ��ϱ�?");
	scanf_s("%d", &star);

	blank = star;
	for (int i = 0; i < blank; i++)
	{	
		for (int j = 0; j < star; j++)
		{
			printf(" "); 
			
		}
		for (int k = 0; k < blank-star+1 ;k++)
		{
			printf(" *");
		}		
		printf("\n");
		star--;
	}
}