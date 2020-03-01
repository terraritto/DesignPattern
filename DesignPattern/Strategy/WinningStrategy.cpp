#include "WinningStrategy.h"

WinningStrategy::WinningStrategy(int seed)
	: mWon(false)
	, mPrevHand(nullptr)
{
	mt = std::mt19937(rnd());
	randHand = std::uniform_int_distribution<>(0, 2);
}

Hand WinningStrategy::NextHand()
{
	if (!mWon)
	{
		mPrevHand = Hand::GetHand(static_cast<Hand::EHAND>(randHand(mt)));
	}
	return *mPrevHand;
}

void WinningStrategy::Study(bool win)
{
	mWon = win;
}
