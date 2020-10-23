#include <stdio.h>

void Q1();
void Q2();
void Q3();
void Q4();
void Q5();

int main()
{
	Q1();
	Q2();
	Q3();
	Q4();
	Q5();
}

void Q1()
{
	int num = 0;

	printf("1. 정수를 입력하시오 : ");
	scanf_s("%d", &num);

	(num % 5 == 0)?
		printf("%d는<은> 5의 배수입니다.", num)
		: printf("%d는<은> 5의 배수가 아닙니다.", num);

}
void Q2()
{
	int Kor = 0, Math = 0, Eng = 0, total = 0;
	float avg = 0.f;

	puts("\n2. 세 과목의 점수를 입력하시오");
	printf("국어 점수 : ");
	scanf_s("%d", &Kor);
	printf("수학 점수 : ");
	scanf_s("%d", &Math);
	printf("영어 점수 : ");
	scanf_s("%d", &Eng);

	avg = (Kor + Math + Eng) / 3.f;

	(avg >= 60) ? printf("평균 %.2f 합격", avg) : printf("평균 %.2f 불합격", avg);
}
void Q3()
{
	int num1 = 0, num2 = 0;

	printf("\n3. 두 정수를 입력하시오 : ");
	scanf_s("%d %d", &num1, &num2);

	(num1 < num2) ? printf("큰 수 : %d", num2) : printf("큰 수 : %d", num1);
}
void Q4()
{
	int num = 0;

	printf("\n4. 정수를 입력하시오 : ");
	scanf_s("%d", &num);

	(num % 3 == 0 && num % 2 == 0) ? printf("%d는 짝수이며 3의 배수 입니다.", num)
		: printf("조건 실패");
}
void Q5()
{
	int num = 0;

	printf("\n5. 정수를 입력하시오 : ");
	scanf_s("%d", &num);

	(num % 5 == 0 || num % 7 == 0) ? printf("%d는 5의 배수이거나 7의 배수입니다.",num)
		: printf("조건 실패");
}