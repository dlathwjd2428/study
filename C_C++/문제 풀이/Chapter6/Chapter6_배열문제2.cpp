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
	printf("1번문제\n");
	for (int i = 0; i < 10; i++)
	{
		printf("%d,", Arr[i]);
	}
}

void Q2(int Arr[])
{
	printf("\n\n2번문제\nInvert_Arr : ");
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
	int even = 0; //짝수
	int odd = 0; //홀수

	printf("\n\n3번문제\n홀수 번째 원소 : ");
	for (int i = 1; i < 10; i += 2)
	{
		printf("%d,", Arr[i]);

		odd += Arr[i];
	}
	printf("\n홀수 번째 총합 : %d", odd);

	printf("\n짝수 번째 원소 : ");
	for (int i = 0; i < 10; i += 2)
	{
		printf("%d,", Arr[i]);

		even += Arr[i];
	}
	printf("\n짝수 번째 총합 : %d", even);

}

void Q4(int Arr[])
{
	printf("\n\n4번문제\nArr : ");
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
			printf("오름차순 : ");
			for (int i = 0; i < 10; i++)
			{
				printf("%d, ", Arr[i]);
			}
			break;

		case 2:
			printf("내림차순 : ");
			for (int i = 9; i >= 0; i--)
			{
				printf("%d, ", Arr[i]);
			}
			break;
		default:
			printf("잘못입력하였습니다. 다시 입력해주세요");
			Sleep(1000);
			break;
		}
	}

}

int menu()
{
	int choose = 0;

	printf("\n\n\n1. 오름차순 정렬\n");
	printf("2. 내림차순 정렬\n");
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