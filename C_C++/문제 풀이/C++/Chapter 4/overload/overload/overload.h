#pragma once
#include <iostream>
#include <string>
using namespace std;

class overload
{
public:
	void load(int x, int y);
	void load(char ch, int y);
	void load(string a);
	void load(string a, string b);
	void load(char num[]);
};