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
				cout << "���� ���� 2���� �۰ų� 9���� Ů�ϴ�." << endl;
			}
			else if (last < 2 || last>9)
			{
				cout << "�� ���� 2���� �۰ų� 9���� Ů�ϴ�." << endl;
			}
			else if (first <= last)
			{
				for (first; first <= last; first++)
				{
					cout <<"=======" << first << "��=======     ";
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
				cout << "���� ���� �� �ܺ��� Ů�ϴ�." << endl;
			}
	}
};




void main()
{
	int first_in;
	int last_in;
	GuGudan p1;

	cout << "���� �� �Է� : ";
	cin >> first_in;
	cout << "�� �� �Է� : ";
	cin >> last_in;
	p1.SetGuGudan(first_in, last_in);
	p1.OnMakeGuGu();
}