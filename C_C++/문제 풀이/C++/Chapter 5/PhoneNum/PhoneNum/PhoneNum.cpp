#include "PhoneNum.h"

Phone::Phone()
{
	string GetNum;

	printf("��ȭ��ȣ �Է� : ");
	cin >> GetNum;

	PhoneNum = new string[GetNum.length() + 1];
	strcpy(PhoneNum, GetNum.c_str());

}

void Phone::PrintPhoneNum()
{
	cout << "�ϼ��� ��ȣ : ";

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
		cout << "��ȣ�� �߸� �Է��ϼ̽��ϴ�." << endl;
	}
	else
		CheckNum();
}
void Phone::CheckNum()
{
	if (PhoneNum[1] == '1') //�޴���
	{
		PrintPhoneNum();
	}
	else if (PhoneNum[1] == '2') //����
	{
		PrintPhoneNum();
	}
	else if (PhoneNum[1] >= '3' && PhoneNum[1] <= '6') //����
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
	cout << PhoneNum << " �� ���� �Ҵ��� �����մϴ�.\n";
	//delete []PhoneNum;
}