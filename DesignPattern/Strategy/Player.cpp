#include "Player.h"

Player::Player(std::string name, Strategy* strategy)
	: mName(name)
	, mStrategy(strategy)
	, mWinCount(0)
	, mLoseCount(0)
	, mGameCount(0)
{
}

Hand Player::NextHand()
{
	return mStrategy->NextHand();
}

void Player::Win()
{
	mStrategy->Study(true);
	mWinCount++;
	mGameCount++;
}

void Player::Lose()
{
	mStrategy->Study(false);
	mLoseCount++;
	mGameCount++;
}

void Player::Even()
{
	mGameCount++;
}

std::string Player::ToString()
{
	std::string str;
	str += "[" + mName + ":" + std::to_string(mGameCount);
	str += " games, " + std::to_string(mWinCount) + " win, ";
	str += std::to_string(mLoseCount) + " lose" + "]";

	return str;
}
