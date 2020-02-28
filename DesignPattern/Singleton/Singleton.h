#pragma once
#include <iostream>

class Singleton
{
public:
	static Singleton GetInstance();


	bool operator==(Singleton& rhs);
private:
	static Singleton mSingleton;
	Singleton()
	{
		std::cout << "Singleton is generated." << std::endl;
	}
};