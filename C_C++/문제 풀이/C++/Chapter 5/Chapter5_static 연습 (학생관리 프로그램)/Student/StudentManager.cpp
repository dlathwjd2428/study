#include "StudentManager.h"

int StudentManager::m_iStudentCount = 0;

StudentManager::StudentManager()
{
}

void StudentManager::AddStudent()
{
	if (m_iStudentCount <= STUDENT_MAX)
	{	
		m_StudentList[m_iStudentCount].SetStudent(m_iStudentCount);
		m_iStudentCount++;		
	}
	else
		cout << "���̻� �л��� ����� �� �����ϴ�." << endl;
}

void StudentManager::ShowStudentList()
{
	for (int i = 0; i < m_iStudentCount; i++)
		m_StudentList[i].ShowStudent();
}

void StudentManager::FindStudent(string Name)
{
	bool findcheck = false;
	for (int i = 0; i < m_iStudentCount; i++)
	{
		if (m_StudentList[i].GetName() == Name)
		{
			m_StudentList[i].ShowStudent();
			findcheck = true;
		}
	}

	if (findcheck == false)
	{
		cout << "�ش� �л��� �����ϴ�." << endl;
		system("pause");
	}
}

void StudentManager::ShowGradeList(int num)
{
	bool studentcheck = false;

	cout << "����������������" << num << " �г⦡������������" << endl;
	for (int i = 0; i < m_iStudentCount; i++)
	{
		if (m_StudentList[i].GetClass() == num)
		{
			m_StudentList[i].ShowStudent();
			studentcheck = true;
		}	
	}
	cout << "������������������������������������" << endl;
	
	if (studentcheck == false)
	{
		cout << num << "�г� �л��� �����ϴ�." << endl;
	}
}

void StudentManager::DeleteStudent(int menu)
{
	if (menu == 6)
	{
		m_iStudentCount--;
	}
	else if (menu == 7)
	{
		m_iStudentCount = 0;
	}	
}

StudentManager::~StudentManager()
{

}
