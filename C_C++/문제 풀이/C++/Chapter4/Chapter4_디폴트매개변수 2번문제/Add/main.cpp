#include "Add.h"

void main()
{
	Add n1;

	int num;

	cout << "마지막 수 입력 : ";
	cin >> num;

	n1.SetNum(num);
	n1.AddNum();
	n1.ShowNum();

	cout << "<기본값>" << endl;
	n1.SetNum();
	n1.AddNum();
	n1.ShowNum();
}