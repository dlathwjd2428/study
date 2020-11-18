#include "Add.h"

void main()
{
	int x = 0, y = 0, z = 0;
	Add Q1; 

	cout << "인자값 하나 입력 : ";
	cin >> x;
	Add Q2(x);

	cout << "인자값 두개 입력 : ";
	cin >> y >> z;
	Add Q3(y, z);

	cout << endl;

	cout << "인자값 없음 : ";
	Q1.AddNum();
	
	cout << "Q2<인자값 하나> : ";
	Q2.AddNum();

	cout << "Q1<인자값 두개> : ";
	Q3.AddNum();
}