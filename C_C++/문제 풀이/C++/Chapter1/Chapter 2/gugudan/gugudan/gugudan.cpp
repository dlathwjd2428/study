#include <iostream>
#include <string>
using namespace std;

class GuGudan
{
private:
	int first;
	int last;

public:

	void OnMakeGuGu(int first, int last)
	{
		if (first < 2 || first>9)
		{
			cout << "시작 단이 2보다 작거나 9보다 큽니다." << endl;
		}
		else if (last < 2 || last>9)
		{
			cout << "끝 단이 2보다 작거나 9보다 큽니다."<<endl;
		}
		else if (first <= last)
		{
			for (int i = 1; i < 10; i++)
			{
				for (first; first <= last; first++)
				{
					cout << "=======" << first << "단=======     ";
					cout << first << "x" << i << "=" << first * i;
				}
			}
		}
		else
		{
			cout << "시작 단이 끝 단보다 큽니다." << endl;
		}	
	}
};




void main()
{
	int first_in;
	int last_in;
	GuGudan p1;

	cout << "시작 단 입력 : ";
	cin >> first_in;
	cout << "끝 단 입력 : ";
	cin >> last_in;

	p1.OnMakeGuGu(first_in,last_in);
}