#include "NumberGenerator.h"
#include "Observer.h"

void NumberGenerator::AddObserver(Observer* observer)
{
	mObservers.push_back(observer);
}

void NumberGenerator::NotifyObservers()
{
	for (auto& ob : mObservers)
	{
		ob->Update(this);
	}
}
