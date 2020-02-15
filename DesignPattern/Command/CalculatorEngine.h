#pragma once
#include "CalculatorCommand.h"

class CalculatorEngine
{
public:
	CalculatorEngine();
	void Operation(CalculatorCommand * cmd);
	void InitNum();
private:
	int mNum;
};