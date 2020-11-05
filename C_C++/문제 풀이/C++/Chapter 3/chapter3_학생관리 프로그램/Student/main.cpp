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
			system("cls");
			Manager.ShowStudentList();
			system("pause");
			break;
		case 3:
			system("cls");
			Manager.ShowGradeList(1);
			Manager.ShowGradeList(2);
			Manager.ShowGradeList(3);
			system("pause");
			break;
		case 4:
			system("cls");
			cout << "�̸� �Է� : ";
			cin >> CheckName;
			Manager.FindStudent(CheckName);
			system("pause");
			break;
		case 5:
			system("cls");
			cout << "�г� �Է� : ";
			cin >> searchgrade;
			Manager.ShowGradeList(searchgrade);
			system("pause");
			break;
		case 6:
			Manager.DeleteStudent(6);
			break;
		case 7:
			Manager.DeleteStudent(7);
			break;
		case 8:
			exit(0);
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