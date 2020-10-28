#include <iostream>
#include <string>
using namespace std;

#define MAX 10

typedef struct student
{
public:
	string name;
	int age;
	int grade;
	int grade_num;
	int Kor;
	int Eng;
	int Math;
}Student;

int menu();
void SetRegister(Student St[], int *num);
void ShowStudent(Student *St);
void result(float avr);
void Search(Student * St[]);
void ShowGrade(Student* Student_List[], int grade);

Student* Student_List[MAX];

int StudentCount = 0;

void main()
{
	while (1)
	{
		switch (menu())
		{
		case 1:
			if (StudentCount + 1 >= 10)
			{
				cout << "���̻� ȸ���� ����� �� �����ϴ�.";
				system("pause");
				break;
			}
			Student_List[StudentCount] = new Student;
			SetRegister(Student_List[StudentCount], &StudentCount);
			break;
		case 2:
			system("cls");
			for (int i = 0; i < StudentCount; i++)
			{
				ShowStudent(Student_List[i]);
			}
			system("pause");
			break;
		case 3:
			Search(Student_List);
			break;
		case 4:
			break;
		case 5:
			system("cls");
			ShowGrade(Student_List, 1);
			ShowGrade(Student_List, 2);
			ShowGrade(Student_List, 3);
			system("Pause");
			break;
		case 6:
			for (int i = 0; i < StudentCount; i++)
			{
				delete Student_List[i];
			}		
		}
	}
}

int menu()
{
	int ch = 0;
	system("cls");
	cout << "===�л���������===(�л��� : " << StudentCount << "��)" << endl;
	cout << "  1.�л����" << endl;
	cout << "  2.�л����� ����" << endl;
	cout << "  3.�л� �˻�" << endl;
	cout << "  4.��޺� ����" << endl;
	cout << "  5.�г⺰ ����" << endl;
	cout << "  6.����" << endl;
	cin >> ch;
	return ch;
}

void SetRegister(Student St[], int *num)
{
	St->grade_num = ++(*num);
	system("cls");
	cout << "   ======" << *num << "��° �л�======" << endl;
	cout << "   �̸� : ";		cin >> St->name;
	cout << "   ���� : ";		cin >> St->age;
	while (1)
	{
		cout << "   �г�<1~3> : ";  cin >> St->grade;
		if (St->grade < 1 || St->grade>3)
			cout << "�߸� �Է��Ͽ����ϴ�. �ٽ� �Է����ּ���." << endl;
		else
			break;
	}	
	cout << "   �������� : ";	cin >> St->Kor;
	cout << "   �������� : ";	cin >> St->Eng;
	cout << "   �������� : ";	cin >> St->Math;
}

void ShowStudent(Student *St)
{
		int total = (St->Kor + St->Eng + St->Math);
		float avr = total / 3;
		cout << "   ======" << St->grade_num << "��° �л�======" << endl;
		cout << "   �̸� : " << St->name << endl;
		cout << "   ���� : " << St->age << endl;
		cout << "   �г�<1~3> : " << St->grade << endl;
		cout << "   �������� : " << St->Kor << endl;
		cout << "   �������� : " << St->Eng << endl;
		cout << "   �������� : " << St->Math << endl;
		cout << "   �հ� ���� : " << total << "   ��� ���� : " << avr << endl;
		cout << "   ��� : ";
		result(avr);	
}
void result(float avr)
{
	if (avr >= 90)
		cout << "[A]" << endl << endl;
	else if (avr < 90 && avr >= 80)
		cout << "[B]" << endl << endl;
	else if (avr < 80 && avr >= 70)
		cout << "[C]" << endl << endl;
	else if (avr < 70 && avr >= 60)
		cout << "[D]" << endl << endl;
	else
		cout << "[F]" << endl << endl;
}

void Search(Student * St[])
{
	string Search_name;

	system("cls");
	cout << "�̸��Է� : ";
	cin >> Search_name;

	for (int i = 0; i < StudentCount ; i++)
	{
		if (Search_name == St[i]->name)
		{
			ShowStudent(Student_List[i]);
			system("pause");
		}
		else
		{
			cout << "�ش� �л��� �����ϴ�." << endl;
			system("pause");
		}
	}
}

void ShowGrade(Student* Student_List[], int grade)
{
	cout << "����������������" << grade << " �г⦡������������"<<endl;
	for (int i = 0; i < StudentCount; i++)
		if (Student_List[i]->grade == grade)
			ShowStudent(Student_List[i]);
	cout << "������������������������������������"<<endl;
}

void ShowAvr(Student* Student_List[], string Avr)
{
	cout << "����������������" << Avr << " ��ަ�������������" << endl;
	for (int i = 0; i < StudentCount; i++)
		//if (Student_List[i]-> == Avr)
			ShowStudent(Student_List[i]);
	cout << "������������������������������������" << endl;
}