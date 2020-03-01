#pragma once
#include "Strategy.h"
#include <random>
#include <array>

class ProbStrategy : public Strategy
{
public:
	ProbStrategy(int seed);
	Hand NextHand() override;
	void Study(bool win) override;
	int GetSum(int hv);
private:
	//random device
	std::random_device rnd;
	std::mt19937 mt;
	std::uniform_int_distribution<> randHand;

	int mPrevHandValue;
	int mCurrentHandValue;
	std::array<std::array<int, 3>, 3> mHistory;
};