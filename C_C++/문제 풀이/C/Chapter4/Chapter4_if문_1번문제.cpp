#include <stdio.h>

void Q1();
void Q2();
void Q3();
void Q4();
void Q5();
void Q6();
void Q7();

int main()
{
	Q1();
	Q2();
	Q3();
	Q4();
	Q5();
	Q6();
	Q7();
}

void Q1()
{
	int num = 0;

	printf("1. ������ �Է��Ͻÿ� : ");
	scanf_s("%d", &num);

	if (num % 3 == 0)
	{
		printf("%d�� 3�� ����Դϴ�.\n", num);
	}
	else
	{
		printf("%d�� 3�� ����� �ƴմϴ�.\n", num);
	}

}
void Q2()
{
	int num = 0;

	printf("2. ������ �Է��Ͻÿ� : ");
	scanf_s("%d", &num);

	if (num < 0)
	{
		printf("%d�� ���밪�� %d�Դϴ�.\n", num, num*-1);
	}
	else
	{
		printf("%d�� ���밪�� %d�Դϴ�.\n", num, num);
	}
}
void Q3()
{
	int num = 0;

	printf("3. ������ �Է��Ͻÿ� : ");
	scanf_s("%d", &num);

	if (num % 2 == 0)
	{
		printf("%d�� ¦���Դϴ�.\n", num);
	}
	else
	{
		printf("%d�� Ȧ���Դϴ�.\n", num);
	}
}
void Q4()
{
	int num1 = 0, num2 = 0;

	printf("4. ���� �ΰ��� �Է��Ͻÿ� : ");
	scanf_s("%d %d", &num1, &num2);

	if (num1 < num2)
	{
		printf("Max : %d", num2);
	}
	else
	{
		printf("Max : %d", num1);
	}
}
void Q5()
{
	int num1 = 0, num2 = 0, num3 = 0;

	printf("\n5. ���� ������ �Է��Ͻÿ� : ");
	scanf_s("%d %d %d", &num1, &num2, &num3);

	if (num1 >= num2 && num1 >= num3)
	{
		printf("Max : %d", num1);
	}
	else if (num2 >= num1 && num2 >= num3)
	{
		printf("Max : %d", num2);
	}
	else if (num3 >= num1 && num1 >= num2)
	{
		printf("Max : %d", num3);
	}
}

void Q6()
{
	int num1 = 0, num2 = 0;

	printf("\n6. ���� �ΰ��� �Է��Ͻÿ� : ");
	scanf_s("%d %d", &num1, &num2);

	if (num1 < num2)
	{
		if (num2 % 2 == 0)
		{
			printf("ū ���� ¦���Դϴ�.");
		}
		else
		{
			printf("ū ���� Ȧ���Դϴ�.");
		}
	}
	else
	{
		if (num1 % 2 == 0)
		{
			printf("ū ���� ¦���Դϴ�.");
		}
		else
		{
			printf("ū ���� Ȧ���Դϴ�.");
		}
	}
}

void Q7()
{
	int num1 = 0, num2 = 0;

	printf("\n7. ���� �ΰ��� �Է��Ͻÿ� : ");
	scanf_s("%d %d", &num1, &num2);

	if ((num1 + num2) % 2 == 1)
	{
		if ((num1 + num2) % 3 == 0)
		{
			printf("Ȧ���̸� 3�ǹ��");
		}
	}
	else
	{
		printf("�ش���� �����ϴ�");
	}
}