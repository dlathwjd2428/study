#include <iostream>
#include <stdlib.h>

#include <string>
using namespace std;

#define MAX 10
#define ZeroMemory RtlZeroMemory
#define RtlZeroMemory(Destination,Length) memset((Destination),0,(Length))

typedef struct member
{
	/*char ID[20];
	char PASSWORD[20];
	char name[20];*/

	string ID;
	string PASSWORD;
	string name;
	int age;
	int phone_num;
	int point;

	member()
	{
		ZeroMemory(&age, (sizeof(*this) - sizeof(std::string) * 3));
	}
}Member;

int menu();
void Sign_UP(Member* mem[], int* num);
void SignUP_ID(Member* mem[], int* num);
void SignUP_PASS(Member* mem[], int* num);

void Sign_In(Member* mem[]);
void Log_Menu(int num);
void Info(Member* Member[], int num);
void Info_ReMenu(Member* Member[], int num);
void Info_Re(Member* Member[], int num, int ch);


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
			Member_List[member_count] = new Member;
			Sign_UP(Member_List, &member_count);
			break;
		case 2:
			Sign_In(Member_List);
			break;
		case 3:
			for (int i = 0; i < member_count; i++)
			{
				delete(Member_List[i]);
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

	system("cls");
	cout << "=====Login=====(ȸ����[" << member_count <<"��])"<<endl;
	cout << "  1.ȸ������" << endl;
	cout << "  2.�α���" << endl;
	cout << "  3.����" << endl;
	cout << "�Է� : ";
	cin >> ch;

	return ch;
}

bool IsEngNum(char ch)
{
	if ((0x61 <= ch && ch <= 0x7A) || (0x41 <= ch && ch <= 0x5A)||(0x30 <= ch && ch <= 0x39))
		return true;
	else
		return false;
}

bool IsNum(char ch)
{
	if ((0x30 <= ch && ch <= 0x39))
		return true;
	else
		return false;
}


void Sign_UP(Member* mem[], int* num)
{
	SignUP_ID(Member_List, &member_count);
	SignUP_PASS(Member_List, &member_count);
	
	system("cls");
	cout << "�г��� �Է� : ";
	cin >> mem[*num]->name;
	cout << "���� �Է� : ";
	cin >> mem[*num]->age;
	cout << "�޴��� ��ȣ �Է� : ";
	cin >> mem[*num]->phone_num;
	cout << "ȸ������ ����!! ���ϸ��� 1000�� ���" << endl;
	mem[*num]->point += 1000;
	++(*num);
	system("pause");
}

void SignUP_ID(Member* mem[], int* num)
{
	system("cls");
	cout << "���̵� �Է�([3���ڡ�] AND [�ѱ�x]) : ";
	cin >> mem[*num]->ID;

	for (int i = 0; i < mem[*num]->ID.length(); i++)
	{
		if (IsEngNum(mem[*num]->ID[i]) == false)
		{
			cout << "id�� ������ �ƴմϴ�." << endl;
			system("pause");
			SignUP_ID(Member_List, &member_count);
		}
	}

	if (mem[*num]->ID.length() < 3)
	{
		cout << "id�� ������ ���� �Դϴ�." << endl;
		system("pause");
		SignUP_ID(Member_List, &member_count);
	}

	for (int i = 0; i < *num - 1; i++)
	{
		if (mem[i]->ID == mem[*num]->ID)
		{
			cout << "������ ���̵� �����մϴ�.";
			system("pause");
			SignUP_ID(Member_List, &member_count);
		}
	}
}

void SignUP_PASS(Member* mem[], int* num)
{
	string WORDPASS;

	system("cls");
	cout << "��й�ȣ �Է�([8���ڡ�]AND[����]AND[���� ����]) : ";
	cin >> mem[*num]->PASSWORD;
	cout << "��й�ȣ Ȯ�� : ";
	cin >> WORDPASS;

	if (mem[*num]->PASSWORD.length() < 8)
	{
		cout << "Password�� �������� ���� �Դϴ�." << endl;
		system("pause");
		SignUP_PASS(Member_List, &member_count);
	}		
	if (mem[*num]->PASSWORD != WORDPASS)
	{
		cout << "��й�ȣ�� ��ġ���� �ʽ��ϴ�." << endl;
		system("pause");
		SignUP_PASS(Member_List, &member_count);
	}		

	for (int i = 0; i < mem[*num]->PASSWORD.length(); i++)
	{
		if (IsEngNum(mem[*num]->PASSWORD[i]) == false)
		{
			cout << "Password�� ������ �ƴմϴ�." << endl;
			system("pause");
			SignUP_PASS(Member_List, &member_count);
		}
	}

	for (int i = 0; i < mem[*num]->PASSWORD.length(); i++)
	{
		if (IsNum(mem[*num]->PASSWORD[i]) == false)
		{
			i++;
			if (i >= mem[*num]->PASSWORD.length() - 1)
			{
				cout << "���ڰ� ���ԵǾ� ���� �ʽ��ϴ�." << endl;
				system("pause");
				SignUP_PASS(Member_List, &member_count);
			}
		}
		else
		{
			break;
		}
	}
}

void Sign_In(Member* mem[])
{
	string ID;
	string PASS;

	while (1)
	{
		system("cls");
		cout << "���̵� �Է� : ";
		cin >> ID;
		cout << "��й�ȣ �Է� : ";
		cin >> PASS;

		for (int i = 0; i < member_count; i++)
		{
			if (mem[i]->ID == ID)
			{
				if (mem[i]->PASSWORD == PASS)
				{
					Log_Menu(i);
				}
				else
				{
					cout << "��й�ȣ�� Ʋ�Ƚ��ϴ�.";
					system("pause");
					Sign_In(Member_List);
				}
			}	
		}
		cout << "�ش� ���̵� �����ϴ�.";
		system("pause");
	}
}

void Log_Menu(int num)
{
	int ch;

	while (1)
	{
		system("cls");
		cout << "========Menu========" << endl;
		cout << "  1.ȸ�� ����" << endl;
		cout << "  2.ȸ�� ���� ����" << endl;
		cout << "  3.�α׾ƿ�" << endl;
		cout << "�Է� : ";
		cin >> ch;

		switch (ch)
		{
		case 1:
			Info(Member_List, num);
			system("pause");
			break;
		case 2:
			Info(Member_List, num);
			Info_ReMenu(Member_List, num);

			break;
		case 3:
			main();
			break;
		default:
			break;
		}
	}
}

void Info(Member* Member[], int num)
{
	system("cls");
	cout << "============ȸ�� ����============" << endl;
	cout << "ID : " << Member[num]->ID << "   �г��� : " << Member[num]->name << endl;
	cout << "���� : " << Member[num]->age << "��   �޴��� ��ȣ : " << Member[num]->phone_num << endl;
	cout << "���ϸ��� : " << Member[num]->point <<"��"<< endl;
}

void Info_ReMenu(Member* Member[], int num)
{
	int ch;
	while (1)
	{
		Info(Member_List, num);
		cout << "===================" << endl;
		cout << "1.�г��� ����" << endl;
		cout << "2.���� ����" << endl;
		cout << "3.�޴��� ��ȣ ����" << endl;
		cout << "4.���ư���" << endl;
		cout << "�Է� : ";

		cin >> ch;

		Info_Re(Member_List, num, ch);
	}	
}

void Info_Re(Member* Member[], int num, int ch)
{
	string save_blank;
	int s_age, s_phonenum;

		switch (ch)
		{
		case 1:
			save_blank = Member[num]->name;
			cout << "���� �г��� : " << Member[num]->name << endl;
			cout << "������ �г��� �Է� : ";
			cin >> Member[num]->name;
			cout << save_blank << "->" << Member[num]->name<<endl;
			system("pause");
			break;
		case 2:
			s_age = Member[num]->age;
			cout << "���� ���� : " << Member[num]->age << endl;
			cout << "������ ���� �Է� : ";
			cin >> Member[num]->age;
			cout << s_age << "->" << Member[num]->age<<endl;
			system("pause");
			break;
		case 3:
			s_phonenum = Member[num]->phone_num;
			cout << "���� �޴��� ��ȣ : " << Member[num]->phone_num << endl;
			cout << "������ �޴��� ��ȣ �Է� : ";
			cin >> Member[num]->phone_num;
			cout << s_phonenum << "->" << Member[num]->phone_num<<endl;
			system("pause");
			break;
		case 4:
			Log_Menu(num);
			break;
		default:
			break;
		}
}