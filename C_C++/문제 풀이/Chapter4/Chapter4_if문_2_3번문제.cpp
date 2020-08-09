#include<stdio.h>

int main()
{
	int dosirak = 0;

	printf("구매할 도시락 갯루를 입력하시오 : ");
	scanf_s("%d", &dosirak);

	if (dosirak <= 10)
	{
		printf("도시락 %d개 가격 : %d", dosirak, dosirak * 2500);
	}
	else
	{
		printf("도시락 %d개 가격 : %d",dosirak,25000 + ((dosirak-10)*2400));
	}
}