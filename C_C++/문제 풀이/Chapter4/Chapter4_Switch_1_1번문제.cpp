#include <stdio.h>
#include <Windows.h>

int menu();

void main()
{
	char name[20] = { 0 };
	int Kor = 0, Math = 0, Eng = 0;
	float avg = 0.f;	

	while (1)
	{
		system("cls");
		switch (menu())
		{
		case 1:
			system("cls");
			printf("�̸� �Է� : ");
			scanf_s("%s", &name, 20);
			break;

		case 2:
			system("cls");
			printf("�� ������ ������ �Է��Ͻÿ�\n");
			printf("���� : "); scanf_s("%d", &Kor);
			printf("���� : "); scanf_s("%d", &Math);
			printf("���� : "); scanf_s("%d", &Eng);
			break;

		case 3:
			system("cls");
			if (name != 0 && Kor != 0 && Math != 0 && Eng != 0)
			{
				avg = (Kor + Math + Eng) / 3.0f;

				puts("====================");
				printf("%s���� ����\n",name);
				printf("\n���� ���� : %d", Kor);
				printf("\n���� ���� : %d", Math);
				printf("\n���� ���� : %d ", Eng);
				printf("\n�հ� ���� : %d ", Kor + Math + Eng);
				printf("\n��� ���� : %.2f ", avg);
				puts("====================");
		
			}
			else
			{
				if (name == 0||)
				{
					printf("�̸��� �Է��ϼ���");
				}
				else
				{
					printf("������ �Է��ϼ���");
				}
			}

			system("pause");

			break;
			

		default:
			printf("�߸��� �� �Դϴ�. �ٽ� �Է����ּ���.");
			Sleep(1000);
			break;
		}
	}
}

int menu()
{
	int choose = 0;

	puts("====================");
	puts("    �л���������      ");
	puts("====================");
	puts("  1. �л� �̸����    ");
	puts("  2. 3���� �������   ");
	puts("  3. ����Ȯ��        ");
	puts("  4. ����           ");
	puts("====================");
	printf("�Է� : ");

	scanf_s("%d", &choose);

	return choose;
}
