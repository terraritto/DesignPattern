#pragma once
#include "Strategy.h"
#include <random>

class WinningStrategy : public Strategy
{
public:
	WinningStrategy(int seed);
	Hand NextHand() override;
	void Study(bool win) override;
private:
	//random device
	std::random_device rnd;
	std::mt19937 mt;
	std::uniform_int_distribution<> randHand;

	bool mWon;
	Hand* mPrevHand;
};