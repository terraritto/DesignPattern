#pragma once
#include <vector>

class Observer;

class NumberGenerator
{
public:
	void AddObserver(Observer* observer);
	void NotifyObservers();
	virtual int GetNumber() = 0;
	virtual void Execute() = 0;
private:
	std::vector<Observer*> mObservers;
};