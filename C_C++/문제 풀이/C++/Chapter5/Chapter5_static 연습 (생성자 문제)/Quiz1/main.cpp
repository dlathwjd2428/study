#include "Add.h"

void main()
{
	int x = 0, y = 0, z = 0;

	cout << "인자값 없음 : ";
	Add Q1;

	Add::add = 0;

	cout << "인자값 하나 입력 : ";
	cin >> x;
	Add Q2(x);

	Add::add = 0;

	cout << "인자값 두개 입력 : ";
	cin >> y >> z;
	Add Q3(y,z);
}