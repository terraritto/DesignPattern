#pragma once
#include "Hand.h"

class Strategy
{
public:
	virtual Hand NextHand() = 0;
	virtual void Study(bool win) = 0;
};