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

	printf("1. ������ �Է��Ͻÿ� : ");
	scanf_s("%d", &num);

	(num % 5 == 0)?
		printf("%d��<��> 5�� ����Դϴ�.", num)
		: printf("%d��<��> 5�� ����� �ƴմϴ�.", num);

}
void Q2()
{
	int Kor = 0, Math = 0, Eng = 0, total = 0;
	float avg = 0.f;

	puts("\n2. �� ������ ������ �Է��Ͻÿ�");
	printf("���� ���� : ");
	scanf_s("%d", &Kor);
	printf("���� ���� : ");
	scanf_s("%d", &Math);
	printf("���� ���� : ");
	scanf_s("%d", &Eng);

	avg = (Kor + Math + Eng) / 3.f;

	(avg >= 60) ? printf("��� %.2f �հ�", avg) : printf("��� %.2f ���հ�", avg);
}
void Q3()
{
	int num1 = 0, num2 = 0;

	printf("\n3. �� ������ �Է��Ͻÿ� : ");
	scanf_s("%d %d", &num1, &num2);

	(num1 < num2) ? printf("ū �� : %d", num2) : printf("ū �� : %d", num1);
}
void Q4()
{
	int num = 0;

	printf("\n4. ������ �Է��Ͻÿ� : ");
	scanf_s("%d", &num);

	(num % 3 == 0 && num % 2 == 0) ? printf("%d�� ¦���̸� 3�� ��� �Դϴ�.", num)
		: printf("���� ����");
}
void Q5()
{
	int num = 0;

	printf("\n5. ������ �Է��Ͻÿ� : ");
	scanf_s("%d", &num);

	(num % 5 == 0 || num % 7 == 0) ? printf("%d�� 5�� ����̰ų� 7�� ����Դϴ�.",num)
		: printf("���� ����");
}