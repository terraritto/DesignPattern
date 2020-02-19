#include "IDCard.h"
#include <iostream>

IDCard::IDCard(std::string owner)
	: mOwner(owner)
{
	std::cout << owner << "'s card can be created!" << std::endl;
}

void IDCard::Use()
{
	std::cout << mOwner << "'s card be used." << std::endl;
}

std::string IDCard::GetOwner()
{
	return mOwner;
}
