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

	printf("=====1������=====\n");
	printf("���� ���ڸ� �Է��Ͻÿ� : ");

	scanf_s("%c", &Q1);

	printf("������ �Է��Ͻÿ� : ");

	scanf_s("%d", &Q2);

	printf("%c + %d = %c\n", Q1, Q2, Q1 + Q2);

	printf("=====2������=====\n");
	printf("�Ҽ������� �Է��Ͻÿ� : ");

	scanf_s("%f", &Q3);
	printf("�Ҽ����� : %0.1f\n", Q3);

	printf("=====3������=====\n");
	printf("���������� �Է��Ͻÿ� : ");
	scanf_s("%d", &Kor);

	printf("���������� �Է��Ͻÿ� : ");
	scanf_s("%d", &Math);

	printf("���������� �Է��Ͻÿ� : ");
	scanf_s("%d", &Eng);

	total = Kor + Math + Eng;
	average = total / 3.0f;

	printf("�������� : %d \n�������� : %d \n�������� : %d \n�հ����� : %d ������� : %.2f", Kor, Math, Eng, total, average);

	printf("\n=====4������=====\n");
	printf("�̸��� �Է��Ͻÿ� : ");
	scanf_s("%s", &name, 20);

	printf("%s���� ���̸� �Է��Ͻÿ� : ", name);
	scanf_s("%d", &age);

	printf("%s���� ���̴� %d�� �Դϴ�. ", name, age);






}
