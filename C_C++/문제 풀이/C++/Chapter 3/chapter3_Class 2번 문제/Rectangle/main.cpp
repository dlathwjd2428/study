#include <iostream>
using namespace std;

class Rectangle
{
private:
	int heigh;
	int width;
public:
	void SetRectangle(int _heigh, int _width)
	{
		heigh = _heigh;
		width = _width;
	}

	void MakeRect()
	{
		if (0 >= heigh || 0 >= width)
		{
			cout << "���� �Ǵ� ���ΰ� 1���� �۽��ϴ�." << endl;
		}
		else
		{
			cout << "��";
			if (width > 1)
			{
				for (int i = 1; i < width - 1; i++)
				{
					cout << "��";
				}
				cout << "��" << endl;
			}
			
			for (int i = 0; i < heigh-2; i++)
			{
				cout << "��";
				for (int i = 1; i < width - 1; i++)
				{
					cout << "  ";
				}
				cout << "��" << endl;
			}
			if (heigh > 1)
			{
				cout << "��" ;
				for (int i = 1; i < width - 1; i++)
				{
					cout << "��";
				}
				cout << "��" << endl;
			}			
		}
		cout<<endl;
	}


};
void main()
{
	int w;
	int h;

	Rectangle re;
	cout << "���� �Է� : ";
	cin >> w;
	cout << "���� �Է� : ";
	cin >> h;

	re.SetRectangle(h, w);
	re.MakeRect();
}