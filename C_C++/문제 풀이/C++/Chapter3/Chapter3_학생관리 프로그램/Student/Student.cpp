#include "Student.h"

Student::Student()
{

}


void Student::SetStudent(int Number)
{
	int GenderCheck;
	bool loop = true;
	system("cls");
	m_iNumber = ++Number;
	cout << m_iNumber << "�� �л� ����" << endl;
	cout << "�̸� : ";
	cin >> m_strName;
	cout << "���� : ";
	cin >> m_iAge;

	while (loop)
	{
		cout << "�г� : ";
		cin >> m_iClass;
		if (m_iClass < 1 || m_iClass > 3)
		{
			cout << "�߸� �Է��ϼ̽��ϴ�.<1~3>" << endl;
		}
		else
			break;
	}

	while (loop)
	{
		cout << "����<���� 0, ���� 1> : ";
		cin >> GenderCheck;

		m_eGender = (GENDER)GenderCheck;

		switch (m_eGender)
		{
		case MAN:
		case WOMAN:
			loop = false;
			break;
		default:
			cout << "�߸� �Է��ϼ̽��ϴ�.(0,1)" << endl;
			break;
		}		
	}
}

void Student::ShowStudent()
{
	cout << "====" << m_iNumber << "�� �л�====" << endl;
	cout << "�̸� : " << m_strName << endl;
	cout << "���� : " << m_iAge << endl;
	cout << "���� : ";
	if (m_eGender == 0)
		cout << "����" << endl;
	else
		cout << "����" << endl;

	cout << "�г� : " << m_iClass << endl << endl;
}

Student::~Student()
{

}