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
			cout << "���� ���� 2���� �۰ų� 9���� Ů�ϴ�." << endl;
		}
		else if (last < 2 || last>9)
		{
			cout << "�� ���� 2���� �۰ų� 9���� Ů�ϴ�."<<endl;
		}
		else if (first <= last)
		{
			for (int i = 1; i < 10; i++)
			{
				for (first; first <= last; first++)
				{
					cout << "=======" << first << "��=======     ";
					cout << first << "x" << i << "=" << first * i;
				}
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

	p1.OnMakeGuGu(first_in,last_in);
}