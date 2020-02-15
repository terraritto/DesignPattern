#include "Trouble.h"

Trouble::Trouble(int num)
	: mNumber(num)
{
}

int Trouble::GetNumber()
{
	return mNumber;
}

std::string Trouble::ToString()
{
	return "[Trouble" + std::to_string(mNumber) + "]";
}
