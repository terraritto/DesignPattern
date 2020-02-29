#include "Clock.h"
#include "AMState.h"
#include "PMState.h"

Clock::Clock()
{
	mState = std::shared_ptr<State>(new AMState());
}

void Clock::ShowTime(int time)
{
	mState->ShowTime(time);

	if (time >= 12)
	{
		mState = std::shared_ptr<State>(PMState::GetInstance());
	}
	else
	{
		mState = std::shared_ptr<State>(AMState::GetInstance());
	}
}
