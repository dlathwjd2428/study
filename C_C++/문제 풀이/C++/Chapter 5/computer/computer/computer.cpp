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
	cout << "===== 환 영 합 니 다 =====" << endl;
	cout << "1.컴퓨터 상태" << endl;
	cout << "2.기 능" << endl;
	cout << "3.off" << endl;
	cout << "입력 >>>>";

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
		cout << "잘못 입력하셨습니다." << endl;
		first_menu();
    }	
}

void Computer::print()
{


	system("cls");
	cout << "제 품 명 : " << name << endl;
	cout << "현재 상태 : ";
	if (state == true)
		cout << "On"<<endl;
	else
		cout << "Off"<<endl;

	cout << "그래픽카드 : " << grp << endl;
	cout << "C P U : " << cpu << endl;
	cout << "메 모 리 : " << memory << endl;
	system("pause");
	first_menu();
}


void Computer::sec_menu()
{
	int ch;
	system("cls");
	cout << "1.계 산 기" << endl;
	cout << "2.메 모 장" << endl;
	cout << "3.그 림 판" << endl;
	cout << "4.돌아가기" << endl;
	cout << "선택 >>>>";
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