#pragma once
#include <string>

class Mediator
{
public:
	virtual void CreateColleagues() = 0;
	virtual void ColleageChanged(const std::string name) = 0;
};