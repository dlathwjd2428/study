#include "Add.h"

void Add::SetNum(int get_num, int result)
{
	this->get_num = get_num;
	this->result = result;
}

void Add::AddNum()
{
	for (int i = 1; i <= get_num; i++)
	{
		result = result + i;
	}
}