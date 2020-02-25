#include "PrinterProxy.h"

PrinterProxy::PrinterProxy()
	: mReal(nullptr)
{
}

PrinterProxy::PrinterProxy(std::string name)
	: mName(name)
	, mReal(nullptr)
{
}

void PrinterProxy::SetPrinterName(std::string name)
{
	if (mReal)
	{
		mReal->SetPrinterName(name);
	}
	mName = name;
}

std::string PrinterProxy::GetPrinterName()
{
	return mName;
}

void PrinterProxy::Print(std::string str)
{
	Realize();
	mReal->Print(str);
}

void PrinterProxy::Realize()
{
	if (!mReal)
	{
		mReal = std::shared_ptr<Printer>(new Printer(mName));
	}
}
