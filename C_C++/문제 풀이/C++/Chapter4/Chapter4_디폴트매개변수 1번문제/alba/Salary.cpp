#include "Salary.h"

void Salary::Enter_Salary(int day, int time, int price)
{
	this->day = day;
	this->time = time;
	this->price = price;
}

void Salary::Show_Salary()
{
	cout << "시급 : " << price << endl;
	cout << "일한 시간 : " << time << "시간 일한 날짜 : " << day << "일" << endl;
	cout << "총 급여 : " << price * time * day << "원"<<endl<<endl;
}