#include <stdio.h>

int main()
{
	int min = 0;
	int price= 0;

	printf("�¸� �̿�ð��� �Է��Ͻÿ� : ");
	scanf_s("%d", &min);

	if (min <= 30)
	{
		printf("%d��", 3000);
	}
	else
	{
		price = ((min - 30) / 10) * 500;

		if (min % 10 != 0)
		{
			price += 500;
		}

		printf("%d�� ž�¿�� : %d", min, 3000 + price);	
	}
}