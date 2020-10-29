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
	string avr;
}Student;

int menu();
void SetRegister(Student St[], int *num);
void ShowStudent(Student *St);
void result(Student *St, float avr);
void Search(Student * St[]);
void ShowGrade(Student* Student_List[], int grade);
void ShowAvr(Student* Student_List[], string Avr);

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
				cout << "더이상 회원을 등록할 수 없습니다.";
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
			system("cls");
			ShowAvr(Student_List,"A");
			ShowAvr(Student_List, "B");
			ShowAvr(Student_List, "C");
			ShowAvr(Student_List, "D");
			ShowAvr(Student_List, "F");
			system("Pause");
			break;
		case 5:
			system("cls");
			ShowGrade(Student_List, 1);
			ShowGrade(Student_List, 2);
			ShowGrade(Student_List, 3);
			system("Pause");
			break;
		case 6:	
			system("cls");
			for (int i = 0; i < StudentCount; i++)
			{
				cout << i+1 << "번 학생 : " << Student_List[i]->name<<endl;
				cout << "할당 해제 완료"<<endl;
				delete Student_List[i];
			}	
			system("pause");
			exit(0);
		}
	}
}

int menu()
{
	int ch = 0;
	system("cls");
	cout << "===학생정보관리===(학생수 : " << StudentCount << "명)" << endl;
	cout << "  1.학생등록" << endl;
	cout << "  2.학생정보 보기" << endl;
	cout << "  3.학생 검색" << endl;
	cout << "  4.등급별 보기" << endl;
	cout << "  5.학년별 보기" << endl;
	cout << "  6.종료" << endl;
	cin >> ch;
	return ch;
}

void SetRegister(Student St[], int *num)
{
	int total; 
	float avr;

	St->grade_num = ++(*num);
	system("cls");
	cout << "   ======" << *num << "번째 학생======" << endl;
	cout << "   이름 : ";		cin >> St->name;
	cout << "   나이 : ";		cin >> St->age;
	while (1)
	{
		cout << "   학년<1~3> : ";  cin >> St->grade;
		if (St->grade < 1 || St->grade>3)
			cout << "잘못 입력하였습니다. 다시 입력해주세요." << endl;
		else
			break;
	}	
	cout << "   국어점수 : ";	cin >> St->Kor;
	cout << "   영어점수 : ";	cin >> St->Eng;
	cout << "   수학점수 : ";	cin >> St->Math;

	total = (St->Kor + St->Eng + St->Math);
	avr = total / 3; 
	result(St, avr);
}

void ShowStudent(Student *St)
{
	int total = (St->Kor + St->Eng + St->Math);
	float totalavr = total / 3.0;
		cout << "   ======" << St->grade_num << "번째 학생======" << endl;
		cout << "   이름 : " << St->name << endl;
		cout << "   나이 : " << St->age << endl;
		cout << "   학년<1~3> : " << St->grade << endl;
		cout << "   국어점수 : " << St->Kor << endl;
		cout << "   영어점수 : " << St->Eng << endl;
		cout << "   수학점수 : " << St->Math << endl;
		cout << "   합계 점수 : " << total << "   평균 점수 : ";
		cout << fixed;
		cout.precision(2);
		cout << totalavr << endl;
		cout << "   등급 : [" << St->avr<<"]"<<endl<<endl;
}
void result(Student *St, float avr)
{
	if (avr >= 90)
		St->avr = "A";	
	else if (avr < 90 && avr >= 80)
		St->avr = "B";		
	else if (avr < 80 && avr >= 70)
		St->avr = "C";
	else if (avr < 70 && avr >= 60)
		St->avr = "D";	
	else
		St->avr = "F";
}

void Search(Student * St[])
{
	string Search_name;
	bool Flag;
	system("cls");
	cout << "이름입력 : ";
	cin >> Search_name;

	Flag = false;

	for (int i = 0; i < StudentCount ; i++)
	{
		if (Search_name == St[i]->name)
		{
			ShowStudent(Student_List[i]);
			system("pause");
			Flag = true;
			break;
		}
		else
		{
			Flag = false;
		}
	}
	if (Flag == false)
	{
		cout << "해당 학생이 없습니다." << endl;
		system("pause");
	}
}

void ShowGrade(Student* Student_List[], int grade)
{
	cout << "┏───────" << grade <<" 학년──────┓"<<endl;
	for (int i = 0; i < StudentCount; i++)
	{
		if (Student_List[i]->grade == grade)
			ShowStudent(Student_List[i]);
	}	
	cout << "┗────────────────┛"<<endl;
}

void ShowAvr(Student* Student_List[], string Avr)
{
	cout << "┏───────" << Avr << " 등급──────┓" << endl;
	for (int i = 0; i < StudentCount; i++)
	{
		if (Student_List[i]->avr == Avr)
		{
			ShowStudent(Student_List[i]);
		}
	}
	cout << "┗────────────────┛" << endl;
}
