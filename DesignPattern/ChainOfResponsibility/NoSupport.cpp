#include "NoSupport.h"

NoSupport::NoSupport(std::string name)
	: Support(name)
{
}

bool NoSupport::Resolve(Trouble* trouble)
{
	return false;
}
