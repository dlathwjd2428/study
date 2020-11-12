#pragma once
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#define MAX 5

class overload
{
public:
	void load(int x, int y);
	void load(char ch, int y);
	void load(string a);
	void load(string a, string b);
	void load(int *num);
	void load(char *ch);
};