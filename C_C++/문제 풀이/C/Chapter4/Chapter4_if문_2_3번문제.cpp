#include<stdio.h>

int main()
{
	int dosirak = 0;

	printf("������ ���ö� ���縦 �Է��Ͻÿ� : ");
	scanf_s("%d", &dosirak);

	if (dosirak <= 10)
	{
		printf("���ö� %d�� ���� : %d", dosirak, dosirak * 2500);
	}
	else
	{
		printf("���ö� %d�� ���� : %d",dosirak,25000 + ((dosirak-10)*2400));
	}
}