#include "PhoneNum.h"

Phone::Phone()
{
	string GetNum;

	printf("��ȭ��ȣ �Է� : ");
	cin >> GetNum;

	PhoneNum = new string(GetNum);
}

void Phone::PrintPhoneNum()
{
	cout << "�ϼ��� ��ȣ : ";
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
		cout << "��ȣ�� �߸� �Է��ϼ̽��ϴ�." << endl;
	}
	else
		PrintPhoneNum();
}
void Phone::CheckNum()
{
	if (PhoneNum->at(1) == '1') //�޴���
	{
		Checklength(11);
	}
	else if (PhoneNum->at(1) == '2') //����
	{
		Checklength(9);
	}
	else if (PhoneNum->at(1) >= '3' && PhoneNum->at(1) <= '6') //����
	{
		Checklength(10);
	}
	else
	{
		cout << "��ȣ�� �߸� �Է��ϼ̽��ϴ�." << endl;
	}
}

Phone::~Phone()
{
	delete PhoneNum;
}