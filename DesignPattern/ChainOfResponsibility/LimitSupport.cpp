#include "LimitSupport.h"

LimitSupport::LimitSupport(std::string name, int limit)
	: Support(name)
	, mLimit(limit)
{
}

bool LimitSupport::Resolve(Trouble* trouble)
{
	if (trouble->GetNumber() < mLimit)
	{
		return true;
	}
	else
	{
		return false;
	}
}
