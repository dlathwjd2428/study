#include<stdio.h>

int main()
{
	int disk =0, price = 0;

	printf("������ ���� ������ �Է��Ͻÿ� : ");
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
	printf("��ũ %d�� ���� : %d��", disk, price);
}