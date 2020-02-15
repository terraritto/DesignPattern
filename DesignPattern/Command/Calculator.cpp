#include "Calculator.h"
#include <iostream>

Calculator::Calculator()
{
	mEngine = std::make_shared<CalculatorEngine>();
}

void Calculator::Compute(std::string ope, int num)
{
	std::shared_ptr<CalculatorCommand> command = std::make_shared<CalculatorCommand>(ope, num);
	mEngine->Operation(command.get());
	mCommandList.push_back(command);
}

void Calculator::Undo()
{
	std::cout << "Undo" << std::endl;
	mEngine->InitNum();

	for (int i = 0; i < mCommandList.size() - 1; i++)
	{
		mEngine->Operation(mCommandList[i].get());
	}
	mCommandList.pop_back();
}
