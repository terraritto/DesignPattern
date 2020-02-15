#include "SpecialSupport.h"

SpecialSupport::SpecialSupport(std::string name, int number)
	: Support(name)
	, mNumber(number)
{
}

bool SpecialSupport::Resolve(Trouble* trouble)
{
	if (trouble->GetNumber() == mNumber)
	{
		return true;
	}
	else
	{
		return false;
	}
}
