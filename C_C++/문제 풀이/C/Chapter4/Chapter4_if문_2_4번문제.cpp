#include<stdio.h>

int main()
{
	int disk =0, price = 0;

	printf("구매할 디스켓 갯수를 입력하시오 : ");
	scanf_s("%d", &disk);

	price = disk * 5000;

	if (disk >= 10 && disk < 100)
	{
		price *= 0.9;
	}
	else if (disk >= 100)
	{
		price *= 0.88;
	}
	printf("디스크 %d개 가격 : %d원", disk, price);
}