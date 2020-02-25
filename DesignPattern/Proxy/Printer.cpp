#include "Printer.h"
#include <iostream>

Printer::Printer()
{
	std::cout << "generate Printer instance now..." << std::endl;
}

Printer::Printer(std::string name)
	: mName(name)
{
	HeavyJob("Generate " + name + " instance of Printer now...");
}

void Printer::SetPrinterName(std::string name)
{
	mName = name;
}

std::string Printer::GetPrinterName()
{
	return mName;
}

void Printer::Print(std::string str)
{
	std::cout << "===" << mName << "===" << std::endl;
	std::cout << str << std::endl;
}

void Printer::HeavyJob(std::string msg)
{
	std::cout << msg;
	std::cout << " complete." << std::endl;
}
