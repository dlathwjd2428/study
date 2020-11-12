#include "overload.h"

void main()
{
	overload Quiz;

	int q1_1, q1_2, q2_2;
	char q2_1;
	string q3_1;
	string q4_1, q4_2;
	int num[5] = {};
	char ch[5] = {};

	cout << "1.정수 2개 입력 : ";
	cin >> q1_1 >> q1_2;
	Quiz.load(q1_1, q1_2);

	cout << "2.단일문자와 정수 입력 : ";
	cin >> q2_1 >> q2_2;
	Quiz.load(q2_1, q2_2);

	cout << "3.문자열 하나 입력 : ";
	cin >> q3_1;
	Quiz.load(q3_1);

	cout << "4.문자열 두개 입력 : ";
	cin >> q4_1 >> q4_2;
	Quiz.load(q4_1, q4_2);

	cout << "5.숫자 5개 입력 : ";
	for (int i = 0; i < 5; i++)
	{
		cin >> num[i];
	}

	Quiz.load(num);

	cout << "6.단일 문자 5개 입력 : ";
	for (int i = 0 ; i < 5; i++)
	{
		cin >> ch[i];
	}

	Quiz.load(ch);
}