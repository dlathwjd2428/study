#include "Student.h"

Student::Student()
{

}


void Student::SetStudent(int Number)
{
	system("cls");
	m_iNumber = Number;
	cout << m_iNumber << "번 학생 정보" << endl;
	cout << "이름 : ";
	cin >> m_strName;
	cout << "나이 : ";
	cin >> m_iAge;

	while (1)
	{
		cout << "학년 : ";
		cin >> m_iClass;
		if (m_iClass < 1 || m_iClass > 3)
		{
			cout << "잘못 입력하셨습니다.<1~3>" << endl;
		}
		else
			break;
	}

	while (1)
	{
		cout << "성별<남자 0, 여자 1> : ";
		cin >> m_iGender;

		if (m_iGender == 0 || m_iClass == 1)
		{
			break;
		}
		else
			cout << "잘못 입력하셨습니다.<0.1>" << endl;
		
	}
}

void Student::ShowStudent()
{
	cout << "====" << m_iNumber << "번 학생====" << endl;
	cout << "이름 : " << m_strName << endl;
	cout << "나이 : " << m_iAge << endl;
	cout << "성별 : ";
	if (m_iGender == 0)
		cout << "남자" << endl;
	else
		cout << "여자" << endl;

	cout << "학년 : " << m_iClass << endl << endl;
}

Student::~Student()
{

}