#include<stdio.h>

int main()
{
	int kor = 0, math = 0, eng = 0, total =0;
	float result = 0.f;
	printf("1������\n�� ������ ������ �Է��Ͻÿ�\n");

	printf("���� ���� : "); scanf_s("%d", &kor);
	printf("���� ���� : "); scanf_s("%d", &math);
	printf("���� ���� : "); scanf_s("%d", &eng);

	total = kor + math + eng;
	result = total / 3.0f;

	printf("\n�������� : %d  �������� : %d       �������� : %d\n", kor, math, eng);
	printf("�������� : %d  ������� : %.2f    ��� : ", total, result);

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