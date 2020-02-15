#include "Support.h"
#include <iostream>

Support::Support(std::string name)
	: mName(name)
	, mNext(nullptr)
{
}

Support* Support::SetNext(Support* next)
{
	mNext = next;
	return next;
}

void Support::support(Trouble* trouble)
{
	if (Resolve(trouble))
	{
		Done(trouble);
	}
	else if (mNext)
	{
		mNext->support(trouble);
	}
	else
	{
		Fail(trouble);
	}
}

std::string Support::ToString()
{
	return "[" + mName + "]";
}

void Support::Done(Trouble* trouble)
{
	std::cout << trouble->ToString() + " is resolved by " + ToString() + "." << std::endl;
}

void Support::Fail(Trouble* trouble)
{
	std::cout << trouble->ToString() + "cannot be resolved." << std::endl;
}
