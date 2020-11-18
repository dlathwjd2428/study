#include "Add.h"

Add::Add()
{
	x = 1;
	y = 10;
}

Add::Add(int y)
{
	x = 1;
	this->y = y;
}
Add::Add(int x, int y)
{
	this->x = x;
	this->y = y;
}

void Add::AddNum()
{
	int temp=0;
	int result = 0;

	if (x > y)
	{
		temp = x;
		x = y;
		y = temp;
	}

	for (int i = x; i <= y; i++)
	{
		result = result + i;
	}

	cout << result<<endl;
}