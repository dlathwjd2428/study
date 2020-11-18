#pragma once
#include "Student.h"

#define STUDENT_MAX 10

class StudentManager
{
private:
	Student m_StudentList[STUDENT_MAX];

public:	
	static int m_iStudentCount;
	void AddStudent();
	void DeleteStudent(int menu);
	void ShowStudentList();
	void ShowGradeList(int num);
	void FindStudent(string Name);

	inline int GetStudentCount() const
	{
		return m_iStudentCount;
	}
	StudentManager();
	~StudentManager();
};
