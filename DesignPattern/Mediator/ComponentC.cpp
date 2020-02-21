#include "ComponentC.h"
#include <iostream>

ComponentC::ComponentC(Mediator* mediator)
	: Collage(mediator)
{
}

void ComponentC::ModeChange()
{
	std::cout << "ComponentC change mode" << std::endl;
	mMediator->ColleageChanged("c");
}

void ComponentC::ReceiveModeChange(const std::string name)
{
	std::cout << "ComponentC receive mode change from " << name << std::endl;
}
