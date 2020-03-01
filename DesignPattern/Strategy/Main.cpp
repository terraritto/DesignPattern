#include "Player.h"
#include "Hand.h"
#include "ProbStrategy.h"
#include "WinningStrategy.h"
#include <memory>
#include <iostream>

int main()
{
	std::shared_ptr<Strategy> win(new WinningStrategy(0));
	std::shared_ptr<Strategy> prob(new ProbStrategy(0));

	Player player1("Taro", win.get());
	Player player2("Hana", prob.get());

	for (int i = 0; i < 10000; i++)
	{
		Hand nextHand1 = player1.NextHand();
		Hand nextHand2 = player2.NextHand();

		if (nextHand1.IsStrongerThan(nextHand2))
		{
			std::cout << "winner: " + player1.ToString() << std::endl;
			player1.Win();
			player2.Lose();
		}
		else if (nextHand2.IsStrongerThan(nextHand1))
		{
			std::cout << "winner: " + player2.ToString() << std::endl;
			player2.Win();
			player1.Lose();
		}
		else
		{
			std::cout << "Even..." << std::endl;
			player1.Even();
			player2.Even();
		}
	}

	std::cout << "Total Result:" << std::endl;
	std::cout << player1.ToString() << std::endl;
	std::cout << player2.ToString() << std::endl;
}