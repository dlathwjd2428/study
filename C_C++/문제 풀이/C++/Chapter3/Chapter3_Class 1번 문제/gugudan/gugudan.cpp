#include <iostream>
#include <iomanip>
using namespace std;

class GuGudan
{
private:
	int first;
	int last;

public:
	void SetGuGudan(int _first, int _last)
	{
		first = _first;
		last = _last;
	}
	
	void OnMakeGuGu()
	{
		int reset = first;
			if (first < 2 || first>9)
			{
				cout << "시작 단이 2보다 작거나 9보다 큽니다." << endl;
			}
			else if (last < 2 || last>9)
			{
				cout << "끝 단이 2보다 작거나 9보다 큽니다." << endl;
			}
			else if (first <= last)
			{
				for (first; first <= last; first++)
				{
					cout <<"=======" << first << "단=======     ";
				}

				cout << endl;

				for (int i = 1; i < 10; i++)
				{
					for (first = reset; first <= last; first++)
					{
						cout << setw(5) << first << " x " << i << " = " << first * i;
					}
					cout<<endl;
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
	p1.SetGuGudan(first_in, last_in);
	p1.OnMakeGuGu();
}