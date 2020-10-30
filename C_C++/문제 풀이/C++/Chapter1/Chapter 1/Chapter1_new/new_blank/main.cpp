#include <iostream>
using namespace std;

#define MAX 5

void InputNum(int *num, int *ch);
void ReNum(int *num);

int check = 0;

void main()
{
	int *Num;
	Num = new int[MAX];

	InputNum(Num,&check);

	cout << "오름차순 정렬전" << endl;

	InputNum(Num, &check);

	cout << "오름차순 정렬후" << endl;

	ReNum(Num);
	InputNum(Num, &check);
}

void InputNum(int *num, int *ch)
{
	cout << "===============" << endl;
	for (int i = 0; i < MAX; i++)
	{
		cout << i+1 << "번째 정수 : ";
		if (*ch == 0)
		{
			cin >> num[i];
		}
		else
		{			
			cout << num[i]<<endl;			
		}
	}
	cout << endl;
	++(*ch);
}

void ReNum(int *num)
{
	int temp;

	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX-1; j++)
		{
			if (num[i] < num[j])
			{
				temp = num[i];
				num[i] = num[j];
				num[j] = temp;
			}
		}
	}
}