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
		cout << "더이상 학생을 등록할 수 없습니다." << endl;
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
	cout << "┌─────" << (int)Class << " 학년─────┐" << endl;
	for (int i = 0; i < m_iStudentCount; i++)
	{
		if (m_StudentList[i].GetClass() == Class)
		{
			m_StudentList[i].ShowStudent();
			State = true;
		}
	}
	cout << "└─────────────┘" << endl;
	return State;
}


void StudentManager::DeleteStudent()
{
	if (m_iStudentCount < 1)
		cout << "삭제할 학생이 없습니다." << endl;
	else
	{
		m_iStudentCount--;
		m_StudentList[m_iStudentCount].ShowStudent();
		cout << "삭제 완료" << endl;
	}
}
void StudentManager::ClearStudent()
{
	m_iStudentCount = 0;
}

StudentManager::~StudentManager()
{
}
