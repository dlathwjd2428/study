#pragma once
#include <iostream>
#include <string>
using namespace std;

enum GENDER
{
	MAN,
	WOMAN
};

class Student
{
private:
	string m_strName;
	int m_iAge;
	GENDER m_eGender;
	int m_iClass;
	int m_iNumber;
public:

	void SetStudent(int Number);
	void ShowStudent();
	inline string GetName() const
	{
		return m_strName;
	}
	inline int GetClass() const
	{
		return m_iClass;
	}
	Student();
	~Student();
};
