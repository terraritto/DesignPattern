#pragma once
#include "Mediator.h"

class Collage
{
public:
	Collage(Mediator* mediator);
	virtual void ModeChange() = 0;
	virtual void ReceiveModeChange(const std::string name) = 0;
protected:
	Mediator* mMediator;
};