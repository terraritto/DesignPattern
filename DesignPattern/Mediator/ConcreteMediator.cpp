#include "ConcreteMediator.h"
#include "ComponentA.h"
#include "ComponentB.h"
#include "ComponentC.h"

void ConcreteMediator::CreateColleagues()
{
	std::shared_ptr<Collage> a(new ComponentA(this));
	std::shared_ptr<Collage> b(new ComponentB(this));
	std::shared_ptr<Collage> c(new ComponentC(this));

	mColleages["a"] = a;
	mColleages["b"] = b;
	mColleages["c"] = c;
}

void ConcreteMediator::ColleageChanged(const std::string name)
{
	for (auto& it : mColleages)
	{
		if (it.first != name)
		{
			it.second->ReceiveModeChange(name);
		}
	}
}

void ConcreteMediator::ChangeMode(const std::string name)
{
	for (auto& it : mColleages)
	{
		if (it.first == name)
		{
			it.second->ModeChange();
		}
	}
}
