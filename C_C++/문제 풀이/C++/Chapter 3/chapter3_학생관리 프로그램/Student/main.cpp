#include"StudentManager.h"

StudentManager Manager;

int menu();

void main()
{
	string CheckName;
	int searchgrade;

	while (1)
	{
		switch (menu())
		{
		case 1:
			Manager.AddStudent();
			break;
		case 2:
			Manager.ShowStudentList();
			break;
		case 3:
			Manager.ShowGradeList(1);
			Manager.ShowGradeList(2);
			Manager.ShowGradeList(3);
			break;
		case 4:
			cout << "�̸� �Է� : ";
			cin >> CheckName;
			Manager.FindStudent(CheckName);
			break;
		case 5:
			cout << "�г� �Է� : ";
			cin >> searchgrade;
			Manager.ShowGradeList(searchgrade);
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
			system("cls");
			for (int i = 0; i < Manager.GetStudentCount(); i++)
			{
				cout << "�Ҵ� ���� �Ϸ�" << endl;
			}
			system("pause");
			exit(0);
			break;
		default:
			cout << "�߸� �Է��ϼ̽��ϴ�.";
			break;
		}
	}	
}

int menu()
{
	int ch = 0;

	system("cls");
	cout<< "=====�л��������α׷�====="<<endl;
	cout << "     1.�л� ���" << endl;
	cout << "     2.�л� ���<��ȣ��>" << endl;
	cout << "     3.�л� ���<�г��>" << endl;
	cout << "     4.�л� �˻�" << endl;
	cout << "     5.�г� �˻�" << endl;
	cout << "     6.������ �л� ����" << endl;
	cout << "     7.�л� ��ü ����" << endl;
	cout << "     8.����" << endl;
	cout << "    <�л� �� : " << Manager.GetStudentCount()<<">" << endl;
	cin >> ch;

	return ch;
}