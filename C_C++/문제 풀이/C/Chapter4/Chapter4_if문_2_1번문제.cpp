#include<stdio.h>

int main()
{
	int kor = 0, math = 0, eng = 0, total =0;
	float result = 0.f;
	printf("1번문제\n세 과목의 점수를 입력하시오\n");

	printf("국어 점수 : "); scanf_s("%d", &kor);
	printf("수학 점수 : "); scanf_s("%d", &math);
	printf("영어 점수 : "); scanf_s("%d", &eng);

	total = kor + math + eng;
	result = total / 3.0f;

	printf("\n국어점수 : %d  수학점수 : %d       영어점수 : %d\n", kor, math, eng);
	printf("총합점수 : %d  평균점수 : %.2f    등급 : ", total, result);

	if (result >= 90)
	{
		printf("A");
	}
	else if (result < 90 && result >= 80)
	{
		printf("B");
	}
	else if (result < 80 && result >= 70)
	{
		printf("C");
	}
	else if (result < 70 && result >= 60)
	{
		printf("D");
	}
	else
	{
		printf("F");
	}
	

}