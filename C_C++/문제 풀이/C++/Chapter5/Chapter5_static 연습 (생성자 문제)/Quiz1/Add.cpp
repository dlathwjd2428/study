#include "Add.h"

int Add::add = 0;

Add::Add()
{
	int x = 10;

	for (int i = 1; i <= x; i++)
		add = add + i;
	print();
}

Add::Add(int x)
{
	for (int i = 1; i <= x; i++)
		add = add + i;
	print();
}

Add::Add(int x, int y)
{
	int temp;
	if (x > y)
	{
		temp = x;
		x = y;
		y = temp;
	}

	for (x; x <= y; x++)
		add = add + x;
	print();
}
