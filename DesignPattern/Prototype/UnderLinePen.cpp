#include "UnderLinePen.h"
#include <iostream>

UnderLinePen::UnderLinePen(char ulchar)
	: mUlChar(ulchar)
{
}

void UnderLinePen::Use(std::string s)
{
	int length = s.size();

	std::cout << "\"" << s << "\"" << std::endl;
	std::cout << " ";
	for (int i = 0; i < length; i++)
	{
		std::cout << mUlChar;
	}
	std::cout << std::endl;
}

Product* UnderLinePen::CreateClone()
{
	Product* p = new UnderLinePen(*this);

	return p;
}
