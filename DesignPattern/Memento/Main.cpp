#include "Memento.h"
#include "Gamer.h"
#include <iostream>

int main()
{
	Gamer gamer(100);
	Memento memento = gamer.CreateMemento();
	
	for (int i = 0; i < 100; i++)
	{
		std::cout << "=== " << i << std::endl;
		std::cout << "now:" << gamer.ToString() << std::endl;

		gamer.Bet();

		std::cout << "my money:" << gamer.GetMoney() << std::endl;

		if (gamer.GetMoney() > memento.GetMoney())
		{
			std::cout << "save status" << std::endl;
			memento = gamer.CreateMemento();
		}
		else if (gamer.GetMoney() < memento.GetMoney() / 2)
		{
			std::cout << "reset status" << std::endl;
			gamer.RestoreMemento(memento);
		}
		std::cout << std::endl;
	}
}