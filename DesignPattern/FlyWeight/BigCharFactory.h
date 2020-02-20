#pragma once
#include <map>
#include <memory>
#include "BigChar.h"

class BigCharFactory
{
public:
	static BigCharFactory* GetInstance();
	BigChar* GetBigChar(char charName);
private:
	std::map<char, std::shared_ptr<BigChar>> mPool;
	static std::shared_ptr<BigCharFactory> mSingleton;
	BigCharFactory();
};