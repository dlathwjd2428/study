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
		cout << "��ȣ�� �߸� �Է��ϼ̽��ϴ�." << endl;
	}
	else
		CheckNum();
}
void Phone::CheckNum()
{
	if (PhoneNum->at(1) == '1') //�޴���
	{
		PrintPhoneNum();
	}
	else if (PhoneNum->at(1) == '2') //����
	{
		PrintPhoneNum();
	}
	else if (PhoneNum->at(1) >= '3' && PhoneNum->at(1) <= '6') //����
	{
		PrintPhoneNum();
	}
	else
	{
		cout << "��ȣ�� �߸� �Է��ϼ̽��ϴ�." << endl;
	}
}

Phone::~Phone()
{
	cout << *PhoneNum << " �� ���� �Ҵ��� �����մϴ�.\n";
	delete PhoneNum;
}