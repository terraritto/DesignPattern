#pragma once
#include "Support.h"

class LimitSupport : public Support
{
public:
	LimitSupport(std::string name, int limit);
protected:
	bool Resolve(Trouble* trouble) override;
private:
	int mLimit;
};