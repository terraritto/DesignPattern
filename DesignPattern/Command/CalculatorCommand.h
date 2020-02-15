#pragma once
#include <string>

class CalculatorCommand
{
public:
	CalculatorCommand(std::string ope, int num);

public:
	std::string mOperation;
	int mNum;
};