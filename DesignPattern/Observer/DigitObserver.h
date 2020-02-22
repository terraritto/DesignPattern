#pragma once
#include "Observer.h"

class DigitalObserver : public Observer
{
public:
	void Update(NumberGenerator* generator) override;
};