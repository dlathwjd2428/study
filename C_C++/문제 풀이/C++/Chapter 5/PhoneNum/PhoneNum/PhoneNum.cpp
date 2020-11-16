#include "PhoneNum.h"

Phone::Phone()
{
	string GetNum;

	printf("전화번호 입력 : ");
	cin >> GetNum;

	PhoneNum = new string[GetNum.length() + 1];
	strcpy(PhoneNum, GetNum.c_str());

}

void Phone::PrintPhoneNum()
{
	cout << "완성된 번호 : ";

	if (PhoneNum.length() == 10)
	{
		cout << PhoneNum[0] << PhoneNum[1] << PhoneNum[2] << "-"
			<< PhoneNum[3] << PhoneNum[4] << PhoneNum[5] << "-"
			<< PhoneNum[6] << PhoneNum[7] << PhoneNum[8] << PhoneNum[9];
	}
	else if (PhoneNum.length() == 11)
	{
		cout << PhoneNum[0] << PhoneNum[1] << PhoneNum[2] << "-"
			<< PhoneNum[3] << PhoneNum[4] << PhoneNum[5] << PhoneNum[6] << "-"
			<< PhoneNum[7] << PhoneNum[8] << PhoneNum[9] << PhoneNum[10];
	}
}

void Phone::Checklength()
{
	if (PhoneNum.length() < 10 || PhoneNum.length() > 11)
	{
		cout << "번호를 잘못 입력하셨습니다." << endl;
	}
	else
		CheckNum();
}
void Phone::CheckNum()
{
	if (PhoneNum[1] == '1') //휴대폰
	{
		PrintPhoneNum();
	}
	else if (PhoneNum[1] == '2') //서울
	{
		PrintPhoneNum();
	}
	else if (PhoneNum[1] >= '3' && PhoneNum[1] <= '6') //지역
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
	cout << PhoneNum << " 의 동적 할당을 해제합니다.\n";
	//delete []PhoneNum;
}