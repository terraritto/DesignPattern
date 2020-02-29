#pragma once
#include "State.h"

class AMState : public State
{
public:
	void ShowTime(int time) override;
	static AMState* GetInstance();
};