#include <stdio.h>

int main()
{
	int min = 0;
	int price= 0;

	printf("승마 이용시간을 입력하시오 : ");
	scanf_s("%d", &min);

	if (min <= 30)
	{
		printf("%d원", 3000);
	}
	else
	{
		price = ((min - 30) / 10) * 500;

		if (min % 10 != 0)
		{
			price += 500;
		}

		printf("%d분 탑승요금 : %d", min, 3000 + price);	
	}
}