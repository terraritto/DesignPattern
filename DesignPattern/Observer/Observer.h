#pragma once
class NumberGenerator;

class Observer
{
public:
	virtual void Update(NumberGenerator* generator) = 0;
};