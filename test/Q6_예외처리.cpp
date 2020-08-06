#include <stdio.h>
#include <conio.h>
#include <windows.h>


enum {
	INPUT_NAME = 1,
	INPUT_NUM,
	NAME,
	PLUS_NUM,
	MEAN,
	GPA,
	EXIT
};

int Menu();


void main()
{
	char name[20] = {NULL};
	int num1 = -1;
	int num2 = -1;
	int num3 = -1;
	float result = -1;

	while (TRUE)
	{
		system("cls");
		switch (Menu())
		{
		case INPUT_NAME:
			printf("�л��̸��� �Է��ϼ���...");
			scanf_s("%s", name, 20);

			break;

		case INPUT_NUM:
			printf("3������ ������ �Է��ϼ���...");
			scanf_s("%d %d %d", &num1, &num2, &num3);

			result = (num1 + num2 + num3) / 3.0f;

			break;

		case NAME:
			if (strlen(name) == 0)
			{
				printf("�̸��� �����ϴ�. �̸��� �Է����ּ���\n");
			}
			else
			{
				printf("�л� �̸��� %s�Դϴ�.\n", name);
			}			
			system("pause");
			break;

		case PLUS_NUM:
			if (num1 == -1|| num2 ==-2 || num3 == -1)
			{
				printf("������ �Է����ּ���\n");
			}
			else
			{
				printf("���� : %d %d %d\n", num1, num2, num3);
				printf("�հ� : %d\n", num1 + num2 + num3);
			}
			
			system("pause");
			break;

		case MEAN:
			if (result == -1)
			{
				printf("������ �Է����ּ���\n");
			}
			else
			{
				
				printf("\n%s �л��� ��� : %f\n", name, result);
			}
			
			system("pause");
			break;

		case GPA:
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
			else if (result == -1)
			{
				printf("������ �Է����ּ���.");
			}
			else
			{
				printf("F");
			}
			system("pause");
			break;

		case EXIT:
			exit(0);

			break;

		default: //case���� ��������
			puts("�߸� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���.");

			Sleep(1000);
		}
	}

}

int Menu()
{
	int choice;
	puts("=================================");
	puts("             M e n u             ");
	puts("=================================");
	puts("        1. �л��̸� �Է�         ");
	puts("        2. ���� 3���� �Է�       ");
	puts("        3. �л��̸� ���         ");
	puts("        4. �հ� ���             ");
	puts("        5. ��� ���             ");
	puts("        6. ���� ���             ");
	puts("        7. ����                  ");
	puts("=================================");

	printf("���Ͻô� ��ư�� �Է����ּ���. :  ");
	scanf_s("%d", &choice);

	return choice;
}