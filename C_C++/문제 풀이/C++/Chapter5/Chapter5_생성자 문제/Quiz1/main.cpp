#include "Add.h"

void main()
{
	int x = 0, y = 0, z = 0;
	Add Q1; 

	cout << "���ڰ� �ϳ� �Է� : ";
	cin >> x;
	Add Q2(x);

	cout << "���ڰ� �ΰ� �Է� : ";
	cin >> y >> z;
	Add Q3(y, z);

	cout << endl;

	cout << "���ڰ� ���� : ";
	Q1.AddNum();
	
	cout << "Q2<���ڰ� �ϳ�> : ";
	Q2.AddNum();

	cout << "Q1<���ڰ� �ΰ�> : ";
	Q3.AddNum();
}