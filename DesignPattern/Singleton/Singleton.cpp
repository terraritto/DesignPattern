#include "Singleton.h"

Singleton Singleton::mSingleton;

Singleton Singleton::GetInstance()
{
	return mSingleton;
}

// simplified
bool Singleton::operator==(Singleton& rhs)
{
	Singleton* temp = &mSingleton;
	if (temp)
	{
		return true;
	}
	else
	{
		return false;
	}
}
