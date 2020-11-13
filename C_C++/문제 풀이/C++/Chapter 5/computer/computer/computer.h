#pragma once
#include <iostream>
#include <Windows.h>
#include <string>
using namespace std;

class Computer
{
private:
	string name;
	bool state;
	string grp;
	string cpu;
	string memory;
public:
	Computer();
	~Computer();
	void first_menu();
	void sec_menu();
	void systemcall(int ch);
	void main_system(int ch);
	void print();
};