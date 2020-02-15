#include "OddSupport.h"

OddSupport::OddSupport(std::string name)
	: Support(name)
{
}

bool OddSupport::Resolve(Trouble* trouble)
{
	if (trouble->GetNumber() % 2 == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
