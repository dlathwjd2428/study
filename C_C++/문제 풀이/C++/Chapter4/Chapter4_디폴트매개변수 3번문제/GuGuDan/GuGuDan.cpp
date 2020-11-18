#include "GuGuDan.h"

void gugudan::SetDan(int first, int last)
{
	this->first = first;
	this->last = last;
}

void gugudan::GetGuGu()
{
	for (first; first <= last; first++)
	{
		cout << "========" << first << "´Ü========" << endl;
		for (int i = 1; i < 10; i++)
		{
			cout << first << "x" << i << " = " << first * i << endl;
		}
		cout << endl;
	}
	
}