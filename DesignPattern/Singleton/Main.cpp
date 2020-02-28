#include "Singleton.h"
#include <iostream>

int main()
{
	Singleton obj1 = Singleton::GetInstance();
	Singleton obj2 = Singleton::GetInstance();

	if (obj1 == obj2)
	{
		std::cout << "same object" << std::endl;
	}
	else
	{
		//this process don't use never.
		std::cout << "other object" << std::endl;
	}

	return 0;
}