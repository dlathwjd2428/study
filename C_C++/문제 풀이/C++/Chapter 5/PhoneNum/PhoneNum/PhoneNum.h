#pragma once
#include <iostream>
#include <string>
using namespace std;

class Phone
{
private:
	string* PhoneNum;
public:
	Phone();
	void PrintPhoneNum();
	void Checklength();
	void CheckNum();
	~Phone();
};