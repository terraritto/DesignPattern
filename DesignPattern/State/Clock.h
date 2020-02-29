#pragma once
#include "State.h"
#include <memory>

class Clock
{
public:
	Clock();
	void ShowTime(int time);
private:
	std::shared_ptr<State> mState;
};