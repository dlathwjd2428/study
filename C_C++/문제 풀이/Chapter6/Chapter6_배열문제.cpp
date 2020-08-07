#include <stdio.h>

int menu();
void swap(int arr[]);

void main()
{
	int arr[10] = { 0 };
	int total = 0;
	float avg = 0.f;
	int first_num = 0;

	for (int num = 0; num < 10; num++)
	{
		printf("[%d]번째 정수 입력 : ", num+1);
		scanf_s("%d", &arr[num]);

		total = total + arr[num];

		if (first_num < arr[num])
		{
			first_num = arr[num];
		}
	}

	swap(arr);
	
	avg = total / 10.f;

	printf("최대값 = %d 총합 = %d 평균 = %.2f", first_num, total, avg);

	while (1)
	{
		switch (menu())
		{
		case 1:
			for (int i = 0; i < 10; i++)
			{
				printf("%d ", arr[i]);
			}
			break;

		case 2:
			for (int i = 9; i >= 0; i--)
			{
				printf("%d ", arr[i]);
			}
			break;
		default:
			printf("잘못 입력하셨습니다. 다시 입력해주세요.");
			break;
		}
	}
	

	printf("작은 수 부터 정렬합니다.\n");
}

int menu()
{
	int choose =0 ;
	puts("\n======정렬 방식======");
	puts("=====1. 오름차순=====");
	puts("=====2. 내림차순=====");
	scanf_s("%d", &choose);

	return choose;
}

void swap(int arr[])
{
	int temp = 0;

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
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