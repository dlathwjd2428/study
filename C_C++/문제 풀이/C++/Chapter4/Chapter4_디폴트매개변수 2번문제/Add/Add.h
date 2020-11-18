#pragma once
#include <iostream>
using namespace std;

class Add
{
private:
	int get_num;
	int result;

public:
	void SetNum(int get_num=10, int result = 0);
	void AddNum();
	inline void ShowNum()
	{
		cout << "1 ~ " << get_num << " ÃÑ ÇÕ : " << result<<endl;
	}
};
