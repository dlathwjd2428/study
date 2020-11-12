#include "overload.h"

void overload::load(int first, int last)
{
	int result = 1;

	cout << "Quiz1<Á¤¼ö2°³>" << endl;
	cout << first << "ÀÇ " << last << "½Â : ";
	for (int i = 1; i <= last; i++)
	{
		result = result * first;
	}

	cout << result<<endl<<endl;
}

void overload::load(char ch, int y)
{
	char result = ch + y;
	if ((result > 90&&result<96)||(result>122))
	{
		result = result - 26;
	}
	cout << ch << " >> " << y << " : "<< result<<endl<<endl;
}

void overload::load(string a)
{
	cout << a <<" -> ";
	reverse(a.begin(), a.end());
	cout << a<<endl<<endl;
}

void overload::load(string first, string last)
{
	cout << first << " + " << last <<" : ";
	cout << first << last<<endl<<endl;
}

void overload::load(int *num)
{
	int temp;

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < MAX - 1; j++)
		{
			if (num[i] > num[j])
			{
				temp = num[i];
				num[i] = num[j];
				num[j] = temp;
			}
		}
	}

	cout << "=================iarr=================" << endl;
	for (int i = 0; i < MAX; i++)
	{
		cout << "iarr[" << i << "] : " << num[i]<<endl;
	}
}

void overload::load(char *ch)
{
	char temp;

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < MAX - 1; j++)
		{
			if (ch[i] < ch[j])
			{
				temp = ch[i];
				ch[i] = ch[j];
				ch[j] = temp;
			}
		}
	}

	cout << "=================charr=================" << endl;
	for (int i = 0; i < MAX; i++)
	{
		cout << "charr[" << i << "] : " << ch[i] << endl;
	}
}

