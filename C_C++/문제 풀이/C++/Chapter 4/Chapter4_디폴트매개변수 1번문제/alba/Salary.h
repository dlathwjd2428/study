#pragma once
#include <iostream>
using namespace std;

class Salary
{
private:
	int time;
	int price;
	int day;

public:
	void Enter_Salary(int day, int time = 8, int price = 7500);
	void Show_Salary();
};