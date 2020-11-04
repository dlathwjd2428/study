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
			cout << "이름 입력 : ";
			cin >> CheckName;
			Manager.FindStudent(CheckName);
			break;
		case 5:
			cout << "학년 입력 : ";
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
				cout << "할당 해제 완료" << endl;
			}
			system("pause");
			exit(0);
			break;
		default:
			cout << "잘못 입력하셨습니다.";
			break;
		}
	}	
}

int menu()
{
	int ch = 0;

	system("cls");
	cout<< "=====학생관리프로그램====="<<endl;
	cout << "     1.학생 등록" << endl;
	cout << "     2.학생 목록<번호순>" << endl;
	cout << "     3.학생 목록<학년순>" << endl;
	cout << "     4.학생 검색" << endl;
	cout << "     5.학년 검색" << endl;
	cout << "     6.마지막 학생 삭제" << endl;
	cout << "     7.학생 전체 삭제" << endl;
	cout << "     8.종료" << endl;
	cout << "    <학생 수 : " << Manager.GetStudentCount()<<">" << endl;
	cin >> ch;

	return ch;
}