#include "RandomNumberGenerator.h"
#include "DigitObserver.h"
#include "GraphObserver.h"
#include <memory>

int main()
{
	std::shared_ptr<NumberGenerator> generator(new RandomNumberGenerator());

	std::shared_ptr<Observer> observer1(new DigitalObserver());
	std::shared_ptr<Observer> observer2(new GraphObserver());

	generator->AddObserver(observer1.get());
	generator->AddObserver(observer2.get());
	generator->Execute();
}