#include "Add.h"

void main()
{
	int x = 0, y = 0, z = 0;

	cout << "���ڰ� ���� : ";
	Add Q1;

	Add::add = 0;

	cout << "���ڰ� �ϳ� �Է� : ";
	cin >> x;
	Add Q2(x);

	Add::add = 0;

	cout << "���ڰ� �ΰ� �Է� : ";
	cin >> y >> z;
	Add Q3(y,z);
}