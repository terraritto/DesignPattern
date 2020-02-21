#pragma once
#include "Mediator.h"
#include "Colleages.h"
#include <map>
#include <memory>

class ConcreteMediator : public Mediator
{
public:
	void CreateColleagues() override;
	void ColleageChanged(const std::string name) override;
	void ChangeMode(const std::string name);
private:
	std::map<std::string, std::shared_ptr<Collage>> mColleages;
};