#include "StudentManager.h"



StudentManager::StudentManager()
{
}

void StudentManager::AddStudent()
{
	if (m_iStudentCount < STUDENT_MAX)
	{
		m_StudentList[m_iStudentCount].SetStudent(m_iStudentCount + 1);
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

bool StudentManager::FindStudentName(string Name)
{
	for (int i = 0; i < m_iStudentCount; i++)
	{
		if (m_StudentList[i].GetName() == Name)
		{
			m_StudentList[i].ShowStudent();
			return true;
		}
	}
	return false;
}

bool StudentManager::ShowStudentClass(CLASS Class)
{
	bool State = false;
	cout << "������������" << (int)Class << " �г⦡����������" << endl;
	for (int i = 0; i < m_iStudentCount; i++)
	{
		if (m_StudentList[i].GetClass() == Class)
		{
			m_StudentList[i].ShowStudent();
			State = true;
		}
	}
	cout << "������������������������������" << endl;
	return State;
}


void StudentManager::DeleteStudent()
{
	if (m_iStudentCount < 1)
		cout << "������ �л��� �����ϴ�." << endl;
	else
	{
		m_iStudentCount--;
		m_StudentList[m_iStudentCount].ShowStudent();
		cout << "���� �Ϸ�" << endl;
	}
}
void StudentManager::ClearStudent()
{
	m_iStudentCount = 0;
}

StudentManager::~StudentManager()
{
}
