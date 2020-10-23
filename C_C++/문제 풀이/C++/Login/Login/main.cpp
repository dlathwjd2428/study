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
			cout << "더이상 회원을 등록할 수 없습니다.";
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

	cout << "=====Login=====(회원수[" << num<<"명])"<<endl;
	cout << "  1.회원가입" << endl;
	cout << "  2.로그인" << endl;
	cout << "  3.종료" << endl;
	cout << "입력 : ";
	cin >> ch;

	return ch;
}

int Sign_UP()
{
	system("cls");
	cout << "아이디 입력([3글자↑] AND [한글x]) : ";
	cin >> ID;
	if (ID.length() < 3)
	{
		cout << "id가 세글자 이하 입니다." << endl;

	}
	cout << "비밀번호 입력([8글자↑]AND[영문]AND[숫자 포함]) : ";
	cin >> PASSWORD;
	cout << "비밀번호 확인 : ";
	cin >> WORDPASS;

	if (PASSWORD.length() < 8)
		cout << "Password가 여덟글자 이하 입니다." << endl;
	if (PASSWORD != WORDPASS)
		cout << "비밀번호가 일치하지 않습니다." << endl;
	//숫자 포함 안된거	
	cout << "닉네임 입력 : ";
	cin >> name;
	cout << "나이 입력 : ";
	cin >> age;
	cout << "휴대폰 번호 입력 : ";
	cin >> phone_num;
	cout << "회원가입 성공!! 마일리지 1000원 등록" << endl;
	system("pause");
}