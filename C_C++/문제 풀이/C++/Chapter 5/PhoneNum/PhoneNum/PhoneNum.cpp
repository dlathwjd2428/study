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

	if (PhoneNum->length() == 10)
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

void Phone::Checklength()
{
	if (PhoneNum->length() < 10 || PhoneNum->length() > 11)
	{
		cout << "번호를 잘못 입력하셨습니다." << endl;
	}
	else
		CheckNum();
}
void Phone::CheckNum()
{
	if (PhoneNum->at(1) == '1') //휴대폰
	{
		PrintPhoneNum();
	}
	else if (PhoneNum->at(1) == '2') //서울
	{
		PrintPhoneNum();
	}
	else if (PhoneNum->at(1) >= '3' && PhoneNum->at(1) <= '6') //지역
	{
		PrintPhoneNum();
	}
	else
	{
		cout << "번호를 잘못 입력하셨습니다." << endl;
	}
}

Phone::~Phone()
{
	cout << *PhoneNum << " 의 동적 할당을 해제합니다.\n";
	delete PhoneNum;
}