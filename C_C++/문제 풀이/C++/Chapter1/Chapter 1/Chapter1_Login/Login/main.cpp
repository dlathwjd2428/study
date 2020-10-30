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
				cout << "더이상 회원을 등록할 수 없습니다.";
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
	cout << "=====Login=====(회원수[" << member_count <<"명])"<<endl;
	cout << "  1.회원가입" << endl;
	cout << "  2.로그인" << endl;
	cout << "  3.종료" << endl;
	cout << "입력 : ";
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
	cout << "닉네임 입력 : ";
	cin >> mem[*num]->name;
	cout << "나이 입력 : ";
	cin >> mem[*num]->age;
	cout << "휴대폰 번호 입력 : ";
	cin >> mem[*num]->phone_num;
	cout << "회원가입 성공!! 마일리지 1000원 등록" << endl;
	mem[*num]->point += 1000;
	++(*num);
	system("pause");
}

void SignUP_ID(Member* mem[], int* num)
{
	system("cls");
	cout << "아이디 입력([3글자↑] AND [한글x]) : ";
	cin >> mem[*num]->ID;

	for (int i = 0; i < mem[*num]->ID.length(); i++)
	{
		if (IsEngNum(mem[*num]->ID[i]) == false)
		{
			cout << "id가 영문이 아닙니다." << endl;
			system("pause");
			SignUP_ID(Member_List, &member_count);
		}
	}

	if (mem[*num]->ID.length() < 3)
	{
		cout << "id가 세글자 이하 입니다." << endl;
		system("pause");
		SignUP_ID(Member_List, &member_count);
	}

	for (int i = 0; i < *num - 1; i++)
	{
		if (mem[i]->ID == mem[*num]->ID)
		{
			cout << "동일한 아이디가 존재합니다.";
			system("pause");
			SignUP_ID(Member_List, &member_count);
		}
	}
}

void SignUP_PASS(Member* mem[], int* num)
{
	string WORDPASS;

	system("cls");
	cout << "비밀번호 입력([8글자↑]AND[영문]AND[숫자 포함]) : ";
	cin >> mem[*num]->PASSWORD;
	cout << "비밀번호 확인 : ";
	cin >> WORDPASS;

	if (mem[*num]->PASSWORD.length() < 8)
	{
		cout << "Password가 여덟글자 이하 입니다." << endl;
		system("pause");
		SignUP_PASS(Member_List, &member_count);
	}		
	if (mem[*num]->PASSWORD != WORDPASS)
	{
		cout << "비밀번호가 일치하지 않습니다." << endl;
		system("pause");
		SignUP_PASS(Member_List, &member_count);
	}		

	for (int i = 0; i < mem[*num]->PASSWORD.length(); i++)
	{
		if (IsEngNum(mem[*num]->PASSWORD[i]) == false)
		{
			cout << "Password가 영문이 아닙니다." << endl;
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
				cout << "숫자가 포함되어 있지 않습니다." << endl;
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
		cout << "아이디 입력 : ";
		cin >> ID;
		cout << "비밀번호 입력 : ";
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
					cout << "비밀번호가 틀렸습니다.";
					system("pause");
					Sign_In(Member_List);
				}
			}	
		}
		cout << "해당 아이디가 없습니다.";
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
		cout << "  1.회원 정보" << endl;
		cout << "  2.회원 정보 변경" << endl;
		cout << "  3.로그아웃" << endl;
		cout << "입력 : ";
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
	cout << "============회원 정보============" << endl;
	cout << "ID : " << Member[num]->ID << "   닉네임 : " << Member[num]->name << endl;
	cout << "나이 : " << Member[num]->age << "살   휴대폰 번호 : " << Member[num]->phone_num << endl;
	cout << "마일리지 : " << Member[num]->point <<"원"<< endl;
}

void Info_ReMenu(Member* Member[], int num)
{
	int ch;
	while (1)
	{
		Info(Member_List, num);
		cout << "===================" << endl;
		cout << "1.닉네임 변경" << endl;
		cout << "2.나이 변경" << endl;
		cout << "3.휴대폰 번호 변경" << endl;
		cout << "4.돌아가기" << endl;
		cout << "입력 : ";

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
			cout << "현재 닉네임 : " << Member[num]->name << endl;
			cout << "변경할 닉네임 입력 : ";
			cin >> Member[num]->name;
			cout << save_blank << "->" << Member[num]->name<<endl;
			system("pause");
			break;
		case 2:
			s_age = Member[num]->age;
			cout << "현재 나이 : " << Member[num]->age << endl;
			cout << "변경할 나이 입력 : ";
			cin >> Member[num]->age;
			cout << s_age << "->" << Member[num]->age<<endl;
			system("pause");
			break;
		case 3:
			s_phonenum = Member[num]->phone_num;
			cout << "현재 휴대폰 번호 : " << Member[num]->phone_num << endl;
			cout << "변경할 휴대폰 번호 입력 : ";
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