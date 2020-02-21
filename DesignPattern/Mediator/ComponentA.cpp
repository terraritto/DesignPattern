#include "ComponentA.h"
#include <iostream>

ComponentA::ComponentA(Mediator* mediator)
	: Collage(mediator)
{
}

void ComponentA::ModeChange()
{
	std::cout << "ComponentA change mode" << std::endl;
	mMediator->ColleageChanged("a");
}

void ComponentA::ReceiveModeChange(const std::string name)
{
	std::cout << "ComponentA receive mode change from " << name << std::endl;
}
