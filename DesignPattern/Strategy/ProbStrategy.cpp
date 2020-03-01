#include "ProbStrategy.h"

ProbStrategy::ProbStrategy(int seed)
	: mPrevHandValue(0)
	, mCurrentHandValue(0)
{
	mt = std::mt19937(rnd());
	randHand = std::uniform_int_distribution<>(0, 2);

	for (auto& val : mHistory)
	{
		for (auto& init : val)
		{
			init = 1;
		}
	}
}

Hand ProbStrategy::NextHand()
{
	randHand = std::uniform_int_distribution<>(0, GetSum(mCurrentHandValue));
	int bet = randHand(mt);
	int handValue = 0;

	if (bet < mHistory[mCurrentHandValue][0])
	{
		handValue = 0;
	}
	else if (bet < mHistory[mCurrentHandValue][0] + mHistory[mCurrentHandValue][1])
	{
		handValue = 1;
	}
	else
	{
		handValue = 2;
	}

	mPrevHandValue = mCurrentHandValue;
	mCurrentHandValue = handValue;
	
	return *Hand::GetHand(static_cast<Hand::EHAND>(handValue));
}

void ProbStrategy::Study(bool win)
{
	if (win)
	{
		mHistory[mPrevHandValue][mCurrentHandValue]++;
	}
	else
	{
		mHistory[mPrevHandValue][(mCurrentHandValue + 1) % 3]++;
		mHistory[mPrevHandValue][(mCurrentHandValue + 2) % 3]++;
	}
}

int ProbStrategy::GetSum(int hv)
{
	int sum = 0;
	for (int i = 0; i < 3; i++)
	{
		sum += mHistory[hv][i];
	}

	return sum;
}
