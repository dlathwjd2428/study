#include <iostream>
#include <stdlib.h>

#include <string>
using namespace std;

#define MAX 10

typedef struct member
{
	char ID[20];
	char PASSWORD[20];
	char name[20];

	/*string ID;
	string PASSWORD;
	string name;*/
	int age;
	int phone_num;
	int point;
}Member;

int menu();
void Sign_UP(Member* mem[], int* num);

Member* Member_List[MAX];

int member_count = 0;
void main()
{
	while (1)
	{
		switch (menu())
		{
		case 1:
			if (member_count + 1 >= 10)
			{
				cout << "���̻� ȸ���� ����� �� �����ϴ�.";
				system("pause");
				break;
			}
			Member_List[member_count] = (Member*)malloc(sizeof(Member));
			Sign_UP(Member_List, &member_count);
			break;
		case 2:
			break;
		case 3:
			for (int i = 0; i < member_count; i++)
			{
				free(Member_List[i]);
			}
			exit(0);
			break;
		default:
			break;
		}
	}	
}

int menu()
{
	int ch;

	cout << "=====Login=====(ȸ����[" << member_count <<"��])"<<endl;
	cout << "  1.ȸ������" << endl;
	cout << "  2.�α���" << endl;
	cout << "  3.����" << endl;
	cout << "�Է� : ";
	cin >> ch;

	return ch;
}

bool IsEnglish(char ch)
{
	if ((0x61 <= ch && ch <= 0x7A) || (0x41 <= ch && ch <= 0x5A))
		return true;
	else
		return false;
}

void Sign_UP(Member* mem[], int* num)
{
	string WORDPASS;

	system("cls");
	cout << "���̵� �Է�([3���ڡ�] AND [�ѱ�x]) : ";
	cin >> mem[*num]->ID;

	/*if (mem->ID.length() < 3)
	{
		cout << "id�� ������ ���� �Դϴ�." << endl;
	}
	*/

	
	cout << "��й�ȣ �Է�([8���ڡ�]AND[����]AND[���� ����]) : ";
	cin >> mem[*num]->PASSWORD;
	cout << "��й�ȣ Ȯ�� : ";
	cin >> WORDPASS;

	/*if (mem[*num]->PASSWORD.length() < 8)
		cout << "Password�� �������� ���� �Դϴ�." << endl;
	if (mem[*num]->PASSWORD != WORDPASS)
		cout << "��й�ȣ�� ��ġ���� �ʽ��ϴ�." << endl;
		*/
	//���� ���� �ȵȰ�	
	cout << "�г��� �Է� : ";
	cin >> mem[*num]->name;
	cout << "���� �Է� : ";
	cin >> mem[*num]->age;
	cout << "�޴��� ��ȣ �Է� : ";
	cin >> mem[*num]->phone_num;
	cout << "ȸ������ ����!! ���ϸ��� 1000�� ���" << endl;
	++(*num);
	system("pause");
}

void Sign_In()
{
	string ID;
	string PASS;

	cout << "���̵� �Է� : ";
	cin >> ID;
	cout << "��й�ȣ �Է� : ";
	cin >> PASS;
}

int Log_Menu()
{
	int ch;

	cout << "========Menu========" << endl;
	cout << "  1.ȸ�� ����" << endl;
	cout << "  2.ȸ�� ���� ����" << endl;
	cout << "  3.�α׾ƿ�" << endl;
	cout << "�Է� : ";
	cin >> ch;

	return ch;
}

void Info(Member* Member)
{
	cout << "============ȸ�� ����============" << endl;
	cout << "ID : " << Member->ID << "   �г��� : " << Member->name << endl;
	cout << "���� : " << Member->age << "��   �޴��� ��ȣ : " << Member->phone_num << endl;
	cout << "���ϸ��� : " << Member->point << endl;
}

int Info_ReMenu(Member* Member)
{
	int ch;

	Info(*Member_List);
	cout << "===================" << endl;
	cout << "1.�г��� ����" << endl;
	cout << "2.���� ����" << endl;
	cout << "3.�޴��� ��ȣ ����" << endl;
	cout << "4.���ư���" << endl;
	cout << "�Է� : ";

	cin >> ch;
	return ch;
}

void Info_Re(Member* Member)
{
	while (1)
	{
		switch (Info_ReMenu(*Member_List))
		{
		case 1:
			cout << "���� �г��� : " << Member->name;
			cout << "������ �г��� �Է� : ";
			cin >> Member->name;
			cout << "->" << Member->name;
			break;
		case 2:
			cout << "���� ���� : " << Member->age;
			cout << "������ ���� �Է� : ";
			cin >> Member->age;
			cout << "->" << Member->name;
			break;
		case 3:
			cout << "���� �޴��� ��ȣ : " << Member->phone_num;
			cout << "������ �޴��� ��ȣ �Է� : ";
			cin >> Member->phone_num;
			cout << "->" << Member->phone_num;
			break;
		case 4:
			Log_Menu();
			break;
		default:
			break;
		}
	}
}