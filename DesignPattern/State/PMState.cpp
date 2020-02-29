#include "PMState.h"
#include <iostream>

void PMState::ShowTime(int time)
{
	std::cout << "PM" << (time - 12) << ":00" << std::endl;
}

PMState* PMState::GetInstance()
{
	return new PMState();
}
