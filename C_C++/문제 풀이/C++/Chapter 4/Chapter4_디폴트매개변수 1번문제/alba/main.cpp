#include "Salary.h"

void main()
{
	Salary p1;

	int day, time, price;

	cout << "�ñ� : ";
	cin >> price;
	cout << "���� �ð� : ";
	cin >> time;
	cout << "���� ��¥ : ";
	cin >> day;
	
	p1.Enter_Salary(day, time, price);
	p1.Show_Salary();
	cout << "<�⺻��>" << endl;
	p1.Enter_Salary(day);
	p1.Show_Salary();
	
}