#pragma once
#include "Printable.h"

class Printer : public Printable
{
public:
	Printer();
	Printer(std::string name);
	void SetPrinterName(std::string name) override;
	std::string GetPrinterName() override;
	void Print(std::string str) override;
	void HeavyJob(std::string msg);
private:
	std::string mName;
};