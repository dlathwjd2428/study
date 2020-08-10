#include<stdio.h>
#include<Windows.h>

void swap(int arr[]);
void Q1(int Arr[]);
void Q2(int Arr[]);
void Q3(int Arr[]);
void Q4(int Arr[]);
int menu();

int main()
{
	int Arr[10] = { 10,17,3,9,37,10,8,9,13,21 };

	Q1(Arr);
	Q2(Arr);
	Q3(Arr);
	Q4(Arr);
}

void Q1(int Arr[])
{
	printf("1������\n");
	for (int i = 0; i < 10; i++)
	{
		printf("%d,", Arr[i]);
	}
}

void Q2(int Arr[])
{
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
}

void Q3(int Arr[])
{
	int even = 0; //¦��
	int odd = 0; //Ȧ��

	printf("\n\n3������\nȦ�� ��° ���� : ");
	for (int i = 1; i < 10; i += 2)
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

}

void Q4(int Arr[])
{
	printf("\n\n4������\nArr : ");
	for (int i = 0; i < 10; i++)
	{
		printf("%d,", Arr[i]);
	}

	swap(Arr);

	while (1)
	{
		switch (menu())
		{
		case 1:
			printf("�������� : ");
			for (int i = 0; i < 10; i++)
			{
				printf("%d, ", Arr[i]);
			}
			break;

		case 2:
			printf("�������� : ");
			for (int i = 9; i >= 0; i--)
			{
				printf("%d, ", Arr[i]);
			}
			break;
		default:
			printf("�߸��Է��Ͽ����ϴ�. �ٽ� �Է����ּ���");
			Sleep(1000);
			break;
		}
	}

}

int menu()
{
	int choose = 0;

	printf("\n\n\n1. �������� ����\n");
	printf("2. �������� ����\n");
	printf("\n============>");

	scanf_s("%d", &choose);

	return choose;
}

void swap(int arr[])
{
	int temp = 0;

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (arr[i] < arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}