#pragma once
#include "State.h"

class PMState : public State
{
public:
	void ShowTime(int time) override;
	static PMState* GetInstance();
};