#pragma once
#include <string>

class Printable
{
public:
	virtual void SetPrinterName(std::string name) = 0;
	virtual std::string GetPrinterName() = 0;
	virtual void Print(std::string str) = 0;
};