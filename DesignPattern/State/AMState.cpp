#include "AMState.h"
#include <iostream>

void AMState::ShowTime(int time)
{
	std::cout << "AM" << time << ":00" << std::endl;
}

AMState* AMState::GetInstance()
{
	return new AMState();
}
