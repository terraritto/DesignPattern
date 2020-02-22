#include "GraphObserver.h"
#include "NumberGenerator.h"
#include <iostream>

void GraphObserver::Update(NumberGenerator* generator)
{
	std::cout << "GraphObserver:";
	int count = generator->GetNumber();
	for (int i = 0; i < count; i++)
	{
		std::cout << "*";
	}
	std::cout << std::endl;
}
