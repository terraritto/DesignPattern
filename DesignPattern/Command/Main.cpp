#include "Calculator.h"
#include <string>
#include <iostream>

int main()
{
	Calculator calc;

	std::string ope = "+";

	calc.Compute(ope, 100);
	ope = "-";
	calc.Compute(ope, 50);
	ope = "*";
	calc.Compute(ope, 2);

	calc.Undo();

	std::cout << "ReCalculation" << std::endl;
	ope = "/";
	calc.Compute(ope, 5);
}