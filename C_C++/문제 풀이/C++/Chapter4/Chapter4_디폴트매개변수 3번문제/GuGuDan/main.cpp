#include "GuGuDan.h"

void main()
{
	gugudan n1;
	int first, last;

	cout << "첫 단 입력 : ";
	cin >> first;
	cout << "마지막 단 입력 : ";
	cin >> last;

	n1.SetDan(first, last);
	n1.GetGuGu();
	cout << "<기본값>" << endl;
	n1.SetDan();
	n1.GetGuGu();
}