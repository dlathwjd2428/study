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

	cout << "1.���� 2�� �Է� : ";
	cin >> q1_1 >> q1_2;
	Quiz.load(q1_1, q1_2);

	cout << "2.���Ϲ��ڿ� ���� �Է� : ";
	cin >> q2_1 >> q2_2;
	Quiz.load(q2_1, q2_2);

	cout << "3.���ڿ� �ϳ� �Է� : ";
	cin >> q3_1;
	Quiz.load(q3_1);

	cout << "4.���ڿ� �ΰ� �Է� : ";
	cin >> q4_1 >> q4_2;
	Quiz.load(q4_1, q4_2);

	cout << "5.���� 5�� �Է� : ";
	for (int i = 0; i < 5; i++)
	{
		cin >> num[i];
	}

	Quiz.load(num);

	cout << "6.���� ���� 5�� �Է� : ";
	for (int i = 0 ; i < 5; i++)
	{
		cin >> ch[i];
	}

	Quiz.load(ch);
}