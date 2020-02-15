#pragma once
#include "Support.h"

class OddSupport : public Support
{
public:
	OddSupport(std::string name);
protected:
	bool Resolve(Trouble* trouble) override;
};