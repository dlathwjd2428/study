#include "PhoneNum.h"

Phone::Phone()
{
	string GetNum;

	printf("전화번호 입력 : ");
	cin >> GetNum;

	PhoneNum = new string(GetNum);
}

void Phone::PrintPhoneNum()
{
	cout << "완성된 번호 : ";
	if (PhoneNum->length() == 9)
	{
		cout << PhoneNum->at(0) << PhoneNum->at(1) << "-"
			<< PhoneNum->at(2) << PhoneNum->at(3) << PhoneNum->at(4) << "-"
			<< PhoneNum->at(5) << PhoneNum->at(6) << PhoneNum->at(7) << PhoneNum->at(8) << endl;
	}
	else if (PhoneNum->length() == 10)
	{
		cout << PhoneNum->at(0) << PhoneNum->at(1) << PhoneNum->at(2) << "-"
			<< PhoneNum->at(3) << PhoneNum->at(4) << PhoneNum->at(5) << "-"
			<< PhoneNum->at(6) << PhoneNum->at(7) << PhoneNum->at(8) << PhoneNum->at(9)<<endl;
	}
	else if (PhoneNum->length() == 11)
	{
		cout << PhoneNum->at(0) << PhoneNum->at(1) << PhoneNum->at(2) << "-"
			<< PhoneNum->at(3) << PhoneNum->at(4) << PhoneNum->at(5) << PhoneNum->at(6) << "-"
			<< PhoneNum->at(7) << PhoneNum->at(8) << PhoneNum->at(9) << PhoneNum->at(10)<<endl;
	}
}

void Phone::Checklength(int ch)
{
	if (PhoneNum->length() != ch)
	{
		cout << "번호를 잘못 입력하셨습니다." << endl;
	}
	else
		PrintPhoneNum();
}
void Phone::CheckNum()
{
	if (PhoneNum->at(1) == '1') //휴대폰
	{
		Checklength(11);
	}
	else if (PhoneNum->at(1) == '2') //서울
	{
		Checklength(9);
	}
	else if (PhoneNum->at(1) >= '3' && PhoneNum->at(1) <= '6') //지역
	{
		Checklength(10);
	}
	else
	{
		cout << "번호를 잘못 입력하셨습니다." << endl;
	}
}

Phone::~Phone()
{
	delete PhoneNum;
}