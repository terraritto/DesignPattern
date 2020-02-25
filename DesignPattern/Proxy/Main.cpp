#include "Printable.h"
#include "PrinterProxy.h"
#include <iostream>
#include <memory>

int main()
{
	std::shared_ptr<Printable> p(new PrinterProxy("Alice"));
	std::cout << " now, name is " << p->GetPrinterName() << "." << std::endl;
	p->SetPrinterName("Bob");
	std::cout << " now, name is " << p->GetPrinterName() << "." << std::endl;
	p->Print("Hello,world");
}