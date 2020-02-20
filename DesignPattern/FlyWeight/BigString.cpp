#include "BigString.h"

BigString::BigString(std::string str)
{
	BigCharFactory* factory = BigCharFactory::GetInstance();

	for (int i = 0; i < str.size(); i++)
	{
		mBigChars.push_back(factory->GetBigChar(str.at(i)));
	}
}

void BigString::Print()
{
	for (auto& ch : mBigChars)
	{
		ch->Print();
	}
}
