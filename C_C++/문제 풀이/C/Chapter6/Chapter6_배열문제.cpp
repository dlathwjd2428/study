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
		printf("[%d]��° ���� �Է� : ", num+1);
		scanf_s("%d", &arr[num]);

		total = total + arr[num];

		if (first_num < arr[num])
		{
			first_num = arr[num];
		}
	}

	swap(arr);
	
	avg = total / 10.f;

	printf("�ִ밪 = %d ���� = %d ��� = %.2f", first_num, total, avg);

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
			printf("�߸� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���.");
			break;
		}
	}
	

	printf("���� �� ���� �����մϴ�.\n");
}

int menu()
{
	int choose =0 ;
	puts("\n======���� ���======");
	puts("=====1. ��������=====");
	puts("=====2. ��������=====");
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