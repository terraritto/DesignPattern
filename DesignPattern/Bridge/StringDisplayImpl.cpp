#include "StringDisplayImpl.h"
#include <iostream>

StringDisplayImpl::StringDisplayImpl(std::string str)
	: mStr(str)
{
	mWidth = mStr.size();
}

void StringDisplayImpl::RawOpen()
{
	PrintLine();
}

void StringDisplayImpl::RawPrint()
{
	std::cout << "|" << mStr << "|" << std::endl;
}

void StringDisplayImpl::RawClose()
{
	PrintLine();
}

void StringDisplayImpl::PrintLine()
{
	std::cout << "+";
	for (int i = 0; i < mWidth; i++)
	{
		std::cout << "-";
	}

	std::cout << "+" << std::endl;
}
