#include "Salary.h"

void main()
{
	Salary p1;

	int day, time, price;

	cout << "시급 : ";
	cin >> price;
	cout << "일한 시간 : ";
	cin >> time;
	cout << "일한 날짜 : ";
	cin >> day;
	
	p1.Enter_Salary(day, time, price);
	p1.Show_Salary();
	cout << "<기본값>" << endl;
	p1.Enter_Salary(day);
	p1.Show_Salary();
	
}