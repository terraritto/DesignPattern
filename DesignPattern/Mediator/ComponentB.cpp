#include "ComponentB.h"
#include <iostream>

ComponentB::ComponentB(Mediator* mediator)
	: Collage(mediator)
{
}

void ComponentB::ModeChange()
{
	std::cout << "ComponentB change mode" << std::endl;
	mMediator->ColleageChanged("b");
}

void ComponentB::ReceiveModeChange(const std::string name)
{
	std::cout << "ComponentB receive mode change from " << name << std::endl;
}
