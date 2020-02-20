#include "BigChar.h"
#include <iostream>

BigChar::BigChar(char charName)
	: mCharName(charName)
{
}

void BigChar::Print()
{
	std::cout << mCharName << std::endl;
}
