//�� ���� �Է¹޾� ū ���� ¦���̸� ����Ͻÿ�
#include <stdio.h>

int main()
{
	while (1)
	{
		int a, b = 0;

		printf("\n �� ���� �Է��ϼ���. : ");
		scanf_s("%d %d", &a, &b);

		if (a < b && b % 2 == 0)
		{
			printf("%d", b);
		}
		else if (a > b && a % 2 == 0)
		{
			printf("%d", a);
		}
		else
		{
			if (a == b)
			{
				printf("���� �� �Դϴ�.");
			}
			else
			{
				printf("�� �� �� ū ���� ¦���� ��츸 ����մϴ�.");
			}
		
		}
	}
}