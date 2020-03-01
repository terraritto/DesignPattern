#include "Hand.h"

std::array<std::shared_ptr<Hand>, 3> Hand::mHand = {
	std::shared_ptr<Hand>(new Hand(Hand::EHAND::HANDVALUE_GUU)),
	std::shared_ptr<Hand>(new Hand(Hand::EHAND::HANDVALUE_CHO)),
	std::shared_ptr<Hand>(new Hand(Hand::EHAND::HANDVALUE_PAA))
};

std::array<std::string, 3> Hand::mName = {
	"グー","チョキ","パー"
};

Hand* Hand::GetHand(EHAND handValue)
{
	return mHand[static_cast<int>(handValue)].get();
}

bool Hand::IsStrongerThan(Hand h)
{
	return Fight(h) == 1;
}

bool Hand::IsWeakerThan(Hand h)
{
	return Fight(h) == -1;
}

std::string Hand::ToString()
{
	return mName[static_cast<int>(mHandValue)];
}

bool Hand::operator==(const Hand& rhs)
{
	return mHandValue == rhs.mHandValue;
}

Hand::Hand(EHAND handValue)
	: mHandValue(handValue)
{
}

int Hand::Fight(Hand h)
{
	if (*this == h)
	{
		return 0;
	}
	else if ((static_cast<int>(mHandValue) + 1) % 3 == static_cast<int>(h.mHandValue))
	{
		return 1;
	}
	else
	{
		return -1;
	}
}
