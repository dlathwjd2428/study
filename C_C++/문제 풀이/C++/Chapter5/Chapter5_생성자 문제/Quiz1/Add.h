#pragma once
#include <iostream>
using namespace std;

class Add
{
private:
	int x;
	int y;

public:
	void AddNum();
	Add();
	Add(int x);
	Add(int x, int y);
};
