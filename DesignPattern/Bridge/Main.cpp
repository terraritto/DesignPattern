#include "Display.h"
#include "CountDisplay.h"
#include "StringDisplayImpl.h"
#include "CountDisplay.h"
#include <memory>

int main()
{
	std::shared_ptr<StringDisplayImpl> jp = std::make_shared<StringDisplayImpl>("Hello, Japan.");
	std::shared_ptr<StringDisplayImpl> wo = std::make_shared<StringDisplayImpl>("Hello, World.");
	std::shared_ptr<StringDisplayImpl> uni = std::make_shared<StringDisplayImpl>("Hello, Universe.");

	std::shared_ptr<Display> d1 = std::make_shared<Display>(jp.get());
	std::shared_ptr<Display> d2 = std::make_shared<CountDisplay>(wo.get());
	std::shared_ptr<CountDisplay> d3 = std::make_shared<CountDisplay>(uni.get());
	
	d1->Disp();
	d2->Disp();
	d3->Disp();
	d3->MultiDisplay(5);
}