#pragma once
#include <iostream>
using namespace std;

class Add
{
public:
	static int add;
	Add();
	Add(int x);
	Add(int x, int y);

	static void print()
	{
		cout << add << endl;
	}
};

