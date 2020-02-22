#include "DigitObserver.h"
#include "NumberGenerator.h"
#include <iostream>

void DigitalObserver::Update(NumberGenerator* generator)
{
	std::cout << "DigitObserver:" << generator->GetNumber() << std::endl;
}
