#pragma once
#include "Printable.h"
#include "Printer.h"
#include <memory>

class PrinterProxy : public Printable
{
public:
	PrinterProxy();
	PrinterProxy(std::string name);
	void SetPrinterName(std::string name) override;
	std::string GetPrinterName() override;
	void Print(std::string str) override;
	void Realize();
private:
	std::string mName;
	std::shared_ptr<Printer> mReal;
};