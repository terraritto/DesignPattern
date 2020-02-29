#include "Clock.h"
#include <iostream>

int main()
{
	Clock clock;

	for (int i = 0; i < 24; i++)
	{
		std::cout << i << ":00=";
		clock.ShowTime(i);
	}
}