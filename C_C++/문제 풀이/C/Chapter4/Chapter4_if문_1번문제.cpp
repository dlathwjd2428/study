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

	printf("1. 정수를 입력하시오 : ");
	scanf_s("%d", &num);

	if (num % 3 == 0)
	{
		printf("%d는 3의 배수입니다.\n", num);
	}
	else
	{
		printf("%d는 3의 배수가 아닙니다.\n", num);
	}

}
void Q2()
{
	int num = 0;

	printf("2. 정수를 입력하시오 : ");
	scanf_s("%d", &num);

	if (num < 0)
	{
		printf("%d의 절대값은 %d입니다.\n", num, num*-1);
	}
	else
	{
		printf("%d의 절대값은 %d입니다.\n", num, num);
	}
}
void Q3()
{
	int num = 0;

	printf("3. 정수를 입력하시오 : ");
	scanf_s("%d", &num);

	if (num % 2 == 0)
	{
		printf("%d은 짝수입니다.\n", num);
	}
	else
	{
		printf("%d은 홀수입니다.\n", num);
	}
}
void Q4()
{
	int num1 = 0, num2 = 0;

	printf("4. 정수 두개를 입력하시오 : ");
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

	printf("\n5. 정수 세개를 입력하시오 : ");
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

	printf("\n6. 정수 두개를 입력하시오 : ");
	scanf_s("%d %d", &num1, &num2);

	if (num1 < num2)
	{
		if (num2 % 2 == 0)
		{
			printf("큰 수가 짝수입니다.");
		}
		else
		{
			printf("큰 수가 홀수입니다.");
		}
	}
	else
	{
		if (num1 % 2 == 0)
		{
			printf("큰 수가 짝수입니다.");
		}
		else
		{
			printf("큰 수가 홀수입니다.");
		}
	}
}

void Q7()
{
	int num1 = 0, num2 = 0;

	printf("\n7. 정수 두개를 입력하시오 : ");
	scanf_s("%d %d", &num1, &num2);

	if ((num1 + num2) % 2 == 1)
	{
		if ((num1 + num2) % 3 == 0)
		{
			printf("홀수이며 3의배수");
		}
	}
	else
	{
		printf("해당사항 없습니다");
	}
}