#pragma once
#include "Colleages.h"

class ComponentB : public Collage
{
public:
	ComponentB(Mediator* mediator);
	void ModeChange() override;
	void ReceiveModeChange(const std::string name) override;
};