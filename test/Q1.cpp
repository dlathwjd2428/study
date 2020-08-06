//두 수를 입력받아 큰 수가 짝수이면 출력하시오
#include <stdio.h>

int main()
{
	while (1)
	{
		int a, b = 0;

		printf("\n 두 수를 입력하세요. : ");
		scanf_s("%d %d", &a, &b);

		if (a < b && b % 2 == 0)
		{
			printf("%d", b);
		}
		else if (a > b && a % 2 == 0)
		{
			printf("%d", a);
		}
		else
		{
			if (a == b)
			{
				printf("같은 수 입니다.");
			}
			else
			{
				printf("두 수 중 큰 수가 짝수일 경우만 출력합니다.");
			}
		
		}
	}
}