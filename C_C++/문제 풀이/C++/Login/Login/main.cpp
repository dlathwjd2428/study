#include <iostream>
#include <string>
using namespace std;

#define MAX 10

typedef struct member
{
	string ID;
	string PASSWORD;
	string name;
	int age;
	int phone_num;
	int point;
}Member;

int menu();
int Sign_UP();

int member_count = 0;
void main()
{
	Member* Member_List[MAX];

	switch (menu())
	{
	case 1:
		if (member_count >= 10)
		{
			cout << "���̻� ȸ���� ����� �� �����ϴ�.";
			system("pause");
		}
		break;
	case 2:
		break;
	case 3:
		free(*Member_List);
		exit(0);
		break;
	default:
		break;
	}
}

int menu()
{
	int ch;
	int num = 0;

	cout << "=====Login=====(ȸ����[" << num<<"��])"<<endl;
	cout << "  1.ȸ������" << endl;
	cout << "  2.�α���" << endl;
	cout << "  3.����" << endl;
	cout << "�Է� : ";
	cin >> ch;

	return ch;
}

int Sign_UP()
{
	system("cls");
	cout << "���̵� �Է�([3���ڡ�] AND [�ѱ�x]) : ";
	cin >> ID;
	if (ID.length() < 3)
	{
		cout << "id�� ������ ���� �Դϴ�." << endl;

	}
	cout << "��й�ȣ �Է�([8���ڡ�]AND[����]AND[���� ����]) : ";
	cin >> PASSWORD;
	cout << "��й�ȣ Ȯ�� : ";
	cin >> WORDPASS;

	if (PASSWORD.length() < 8)
		cout << "Password�� �������� ���� �Դϴ�." << endl;
	if (PASSWORD != WORDPASS)
		cout << "��й�ȣ�� ��ġ���� �ʽ��ϴ�." << endl;
	//���� ���� �ȵȰ�	
	cout << "�г��� �Է� : ";
	cin >> name;
	cout << "���� �Է� : ";
	cin >> age;
	cout << "�޴��� ��ȣ �Է� : ";
	cin >> phone_num;
	cout << "ȸ������ ����!! ���ϸ��� 1000�� ���" << endl;
	system("pause");
}