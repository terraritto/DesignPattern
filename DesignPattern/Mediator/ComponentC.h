#pragma once
#include "Colleages.h"

class ComponentC : public Collage
{
public:
	ComponentC(Mediator* mediator);
	void ModeChange() override;
	void ReceiveModeChange(const std::string name) override;
};