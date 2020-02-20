#pragma once
#include "BigChar.h"
#include "BigCharFactory.h"
#include <vector>
#include <string>

class BigString
{
public:
	BigString(std::string str);
	void Print();
private:
	std::vector<BigChar*> mBigChars;
};