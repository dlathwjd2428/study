#include<stdio.h>

int main()
{
	int Arr[10] = { 10,17,3,9,37,10,8,9,13,21 };
	int even = 0; //¦��
	int odd = 0; //Ȧ��

	printf("1������\n");
	for (int i = 0; i < 10; i++)
	{
		printf("%d,", Arr[i]);
	}

	printf("\n\n2������\nInvert_Arr : ");
	for (int i = 9; i >= 0; i--)
	{
		printf("%d,", Arr[i]);
	}
	printf("\nArr : ");
	for (int i = 0; i < 10; i++)
	{
		printf("%d,", Arr[i]);
	}

	printf("\n\n3������\nȦ�� ��° ���� : ");
	for (int i = 1; i < 10; i+=2)
	{
		printf("%d,", Arr[i]);

		odd += Arr[i];
	}
	printf("\nȦ�� ��° ���� : %d", odd);

	printf("\n¦�� ��° ���� : ");
	for (int i = 0; i < 10; i += 2)
	{
		printf("%d,", Arr[i]);

		even += Arr[i];
	}
	printf("\n¦�� ��° ���� : %d", even);

	printf("\n\n4������\nArr : ");
	for (int i = 0; i < 10; i++)
	{
		printf("%d,", Arr[i]);
	}


}