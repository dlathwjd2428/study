#include <iostream>
#include <string>
using namespace std;

#define MAX 10

struct Student
{
	string name;
	int age;
	int grade;
	int grade_num;
	int Kor;
	int Eng;
	int Math;
};

Student* Student_List[MAX];

int Student_num = 0;

void main()
{
	while (1)
	{
		switch (1/*menu()*/)
		{
		case 1:
			if (Student_num + 1 >= 10)
			{
				cout << "���̻� ȸ���� ����� �� �����ϴ�.";
				system("pause");
				break;
			}
			Student_List[Student_num] = new Student;
		}
	}
}