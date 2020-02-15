#include "CalculatorEngine.h"
#include <iostream>

CalculatorEngine::CalculatorEngine()
	: mNum(0)
{
}

void CalculatorEngine::Operation(CalculatorCommand* cmd)
{
	if (cmd->mOperation == "+")
	{
		mNum += cmd->mNum;
	}
	else if (cmd->mOperation == "-")
	{
		mNum -= cmd->mNum;
	}
	else if (cmd->mOperation == "*")
	{
		mNum *= cmd->mNum;
	}
	else if (cmd->mOperation == "/")
	{
		mNum /= cmd->mNum;
	}

	std::cout << "Calculate Result:" << mNum << " (Operator:" << cmd->mOperation << ",num:" << cmd->mNum << ")" << std::endl;

}

void CalculatorEngine::InitNum()
{
	mNum = 0;
}

