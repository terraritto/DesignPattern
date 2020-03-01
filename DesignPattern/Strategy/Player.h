#pragma once
#include "Hand.h"
#include "Strategy.h"
#include <string>

class Player
{
public:
	Player(std::string name, Strategy* strategy);
	Hand NextHand();
	void Win();
	void Lose();
	void Even();
	std::string ToString();
private:
	std::string mName;
	Strategy* mStrategy;
	int mWinCount;
	int mLoseCount;
	int mGameCount;
};