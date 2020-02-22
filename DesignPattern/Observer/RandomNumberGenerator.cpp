#include "RandomNumberGenerator.h"
#include <random>

int RandomNumberGenerator::GetNumber()
{
	return mNumber;
}

void RandomNumberGenerator::Execute()
{
	std::random_device rnd;
	std::mt19937 mt(rnd());
	std::uniform_int_distribution<> randHand50(0,50);

	for (int i = 0; i < 20; i++)
	{
		mNumber = randHand50(mt);
		NotifyObservers();
	}

}
