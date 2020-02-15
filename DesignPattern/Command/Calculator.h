#pragma once
#include "CalculatorEngine.h"
#include "CalculatorCommand.h"
#include <memory>
#include <vector>

class Calculator
{
public:
	Calculator();
	void Compute(std::string ope, int num);
	void Undo();
private:
	std::shared_ptr<CalculatorEngine> mEngine;
	std::vector<std::shared_ptr<CalculatorCommand>> mCommandList;
};