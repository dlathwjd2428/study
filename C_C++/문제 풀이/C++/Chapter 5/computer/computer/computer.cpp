#include "computer.h"

Computer::Computer()
{
	name = "Atents";
	state = true;
	grp = "GTX990";
	cpu = "I7";
	memory = "8G";
}

void Computer:: first_menu()
{
	int ch;
	system("cls");
	cout << "===== ȯ �� �� �� �� =====" << endl;
	cout << "1.��ǻ�� ����" << endl;
	cout << "2.�� ��" << endl;
	cout << "3.off" << endl;
	cout << "�Է� >>>>";

	cin >> ch;

	main_system(ch);
}

void Computer::main_system(int ch)
{
	switch (ch)
	{
	case 1:
		print();
		break;
	case 2:
		sec_menu();
		break;
	case 3:
		break;
		exit(0);
	default:
		cout << "�߸� �Է��ϼ̽��ϴ�." << endl;
		first_menu();
    }	
}

void Computer::print()
{


	system("cls");
	cout << "�� ǰ �� : " << name << endl;
	cout << "���� ���� : ";
	if (state == true)
		cout << "On"<<endl;
	else
		cout << "Off"<<endl;

	cout << "�׷���ī�� : " << grp << endl;
	cout << "C P U : " << cpu << endl;
	cout << "�� �� �� : " << memory << endl;
	system("pause");
	first_menu();
}


void Computer::sec_menu()
{
	int ch;
	system("cls");
	cout << "1.�� �� ��" << endl;
	cout << "2.�� �� ��" << endl;
	cout << "3.�� �� ��" << endl;
	cout << "4.���ư���" << endl;
	cout << "���� >>>>";
	cin >> ch;

	systemcall(ch);
}

void Computer::systemcall(int ch)
{
	switch (ch)
	{
	case 1:
		system("calc");
		system("pause");
		break;
	case 2:
		system("notepad");
		break;
	case 3:
		system("mspaint");
		break;
	case 4:
		first_menu();
	default:
		sec_menu();
	}
	sec_menu();
}

Computer::~Computer()
{
}