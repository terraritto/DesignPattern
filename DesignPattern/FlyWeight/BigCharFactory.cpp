#include "BigCharFactory.h"

std::shared_ptr<BigCharFactory> BigCharFactory::mSingleton(new BigCharFactory());

BigCharFactory* BigCharFactory::GetInstance()
{
	return mSingleton.get();
}

BigChar* BigCharFactory::GetBigChar(char charName)
{
	auto bc = mPool.find(charName);
	if (bc == mPool.end())
	{
		std::shared_ptr<BigChar> saveObj(new BigChar(charName));
		mPool[charName] = saveObj;
		return saveObj.get();
	}
	else
	{
		return bc->second.get();
	}
}

BigCharFactory::BigCharFactory()
{
}
