#include<stdio.h>

void main()
{
	char Q1 = 0;
	int Q2 = 0;
	float Q3 = 0.f;
	int Kor = 0, Math = 0, Eng = 0, total=0;
	float average;
	char name[20];
	int age = 0;

	printf("=====1번문제=====\n");
	printf("단일 문자를 입력하시오 : ");

	scanf_s("%c", &Q1);

	printf("정수를 입력하시오 : ");

	scanf_s("%d", &Q2);

	printf("%c + %d = %c\n", Q1, Q2, Q1 + Q2);

	printf("=====2번문제=====\n");
	printf("소수점수를 입력하시오 : ");

	scanf_s("%f", &Q3);
	printf("소수점수 : %0.1f\n", Q3);

	printf("=====3번문제=====\n");
	printf("국어점수를 입력하시오 : ");
	scanf_s("%d", &Kor);

	printf("수학점수를 입력하시오 : ");
	scanf_s("%d", &Math);

	printf("영어점수를 입력하시오 : ");
	scanf_s("%d", &Eng);

	total = Kor + Math + Eng;
	average = total / 3.0f;

	printf("국어점수 : %d \n수학점수 : %d \n영어점수 : %d \n합계점수 : %d 평균점수 : %.2f", Kor, Math, Eng, total, average);

	printf("\n=====4번문제=====\n");
	printf("이름을 입력하시오 : ");
	scanf_s("%s", &name, 20);

	printf("%s님의 나이를 입력하시오 : ", name);
	scanf_s("%d", &age);

	printf("%s님의 나이는 %d세 입니다. ", name, age);






}
