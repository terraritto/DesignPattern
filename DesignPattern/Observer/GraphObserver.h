#pragma once
#include "Observer.h"

class GraphObserver : public Observer
{
public:
	void Update(NumberGenerator* generator) override;
};