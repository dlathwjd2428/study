#include "GuGuDan.h"

void main()
{
	gugudan n1;
	int first, last;

	cout << "ù �� �Է� : ";
	cin >> first;
	cout << "������ �� �Է� : ";
	cin >> last;

	n1.SetDan(first, last);
	n1.GetGuGu();
	cout << "<�⺻��>" << endl;
	n1.SetDan();
	n1.GetGuGu();
}