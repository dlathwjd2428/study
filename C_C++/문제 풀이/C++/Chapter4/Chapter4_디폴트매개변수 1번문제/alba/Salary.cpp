#include "Salary.h"

void Salary::Enter_Salary(int day, int time, int price)
{
	this->day = day;
	this->time = time;
	this->price = price;
}

void Salary::Show_Salary()
{
	cout << "�ñ� : " << price << endl;
	cout << "���� �ð� : " << time << "�ð� ���� ��¥ : " << day << "��" << endl;
	cout << "�� �޿� : " << price * time * day << "��"<<endl<<endl;
}