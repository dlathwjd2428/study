#include "Add.h"

void main()
{
	Add n1;

	int num;

	cout << "������ �� �Է� : ";
	cin >> num;

	n1.SetNum(num);
	n1.AddNum();
	n1.ShowNum();

	cout << "<�⺻��>" << endl;
	n1.SetNum();
	n1.AddNum();
	n1.ShowNum();
}