#pragma once
#include "Colleages.h"

class ComponentA : public Collage
{
public:
	ComponentA(Mediator* mediator);
	void ModeChange() override;
	void ReceiveModeChange(const std::string name) override;
};