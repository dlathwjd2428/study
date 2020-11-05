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
	cout << m_iNumber << "번 학생 정보" << endl;
	cout << "이름 : ";
	cin >> m_strName;
	cout << "나이 : ";
	cin >> m_iAge;

	while (loop)
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

	while (loop)
	{
		cout << "성별<남자 0, 여자 1> : ";
		cin >> GenderCheck;

		m_eGender = (GENDER)GenderCheck;

		switch (m_eGender)
		{
		case MAN:
		case WOMAN:
			loop = false;
			break;
		default:
			cout << "잘못 입력하셨습니다.(0,1)" << endl;
			break;
		}		
	}
}

void Student::ShowStudent()
{
	cout << "====" << m_iNumber << "번 학생====" << endl;
	cout << "이름 : " << m_strName << endl;
	cout << "나이 : " << m_iAge << endl;
	cout << "성별 : ";
	if (m_eGender == 0)
		cout << "남자" << endl;
	else
		cout << "여자" << endl;

	cout << "학년 : " << m_iClass << endl << endl;
}

Student::~Student()
{

}