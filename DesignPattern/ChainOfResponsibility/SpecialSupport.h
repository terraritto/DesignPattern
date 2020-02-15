#pragma once
#include "Support.h"

class SpecialSupport : public Support
{
public:
	SpecialSupport(std::string name, int number);
protected:
	bool Resolve(Trouble* trouble) override;
private:
	int mNumber;
};