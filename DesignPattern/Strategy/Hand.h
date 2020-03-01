#pragma once
#include <array>
#include <string>

class Hand
{
public:
	enum class EHAND
	{
		HANDVALUE_GUU,
		HANDVALUE_CHO,
		HANDVALUE_PAA
	};

	static std::array<std::shared_ptr<Hand>, 3> mHand;

	static Hand* GetHand(EHAND handValue);
	bool IsStrongerThan(Hand h);
	bool IsWeakerThan(Hand h);
	std::string ToString();

	bool operator==(const Hand& rhs);
private:
	static std::array<std::string,3> mName;
	EHAND mHandValue;

	Hand(EHAND handValue);
	int Fight(Hand h);
};