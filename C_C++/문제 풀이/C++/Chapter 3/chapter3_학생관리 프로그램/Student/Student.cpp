#include "Student.h"

Student::Student()
{

}


void Student::SetStudent(int Number)
{
	system("cls");
	m_iNumber = Number;
	cout << m_iNumber << "�� �л� ����" << endl;
	cout << "�̸� : ";
	cin >> m_strName;
	cout << "���� : ";
	cin >> m_iAge;

	while (1)
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

	while (1)
	{
		cout << "����<���� 0, ���� 1> : ";
		cin >> m_iGender;

		if (m_iGender == 0 || m_iClass == 1)
		{
			break;
		}
		else
			cout << "�߸� �Է��ϼ̽��ϴ�.<0.1>" << endl;
		
	}
}

void Student::ShowStudent()
{
	cout << "====" << m_iNumber << "�� �л�====" << endl;
	cout << "�̸� : " << m_strName << endl;
	cout << "���� : " << m_iAge << endl;
	cout << "���� : ";
	if (m_iGender == 0)
		cout << "����" << endl;
	else
		cout << "����" << endl;

	cout << "�г� : " << m_iClass << endl << endl;
}

Student::~Student()
{

}