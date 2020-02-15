#pragma once
#include <string>

class Trouble
{
public:
	Trouble(int num);
	int GetNumber();
	std::string ToString();
private:
	int mNumber;
};