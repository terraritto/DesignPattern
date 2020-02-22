#pragma once
#include "NumberGenerator.h"

class RandomNumberGenerator : public NumberGenerator
{
public:
	int GetNumber() override;
	void Execute() override;
private:
	int mNumber;
};