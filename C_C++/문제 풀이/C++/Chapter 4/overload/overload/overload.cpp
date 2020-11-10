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
	cout << ch << " >> " << y << " : "<< result;
}

void overload::load(string a)
{
	
}

void overload::load(string first, string last)
{
	cout << first << " + " << last;
}

void overload::load(char num[])
{

}
