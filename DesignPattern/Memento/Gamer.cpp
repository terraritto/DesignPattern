#include "Gamer.h"
#include <random>
#include <iostream>

std::vector<std::string> Gamer::mFruitsName = {"apple","grape","banana","orange"};


Gamer::Gamer(int money)
	: mMoney(money)
{
}

int Gamer::GetMoney()
{
	return mMoney;
}

void Gamer::Bet()
{
	std::random_device rnd;
	std::mt19937 mt(rnd());
	std::uniform_int_distribution<> randHand50(0, 6);

	int dice = randHand50(mt) + 1;
	if (dice == 1)
	{
		mMoney += 100;
		std::cout << "money is increased!!" << std::endl;
	}
	else if (dice == 2)
	{
		mMoney /= 2;
		std::cout << "money is decresed by half..." << std::endl;
	}
	else if (dice == 5)
	{
		std::string f = GetFruit();
		std::cout << "get fruit:" << f << std::endl;
		mFruits.push_back(f);
	}
	else
	{
		std::cout << "No event is happened..." << std::endl;
	}
}

Memento Gamer::CreateMemento()
{
	Memento m(mMoney);
	for (auto& f : mFruits)
	{
		if (f.find("yammy"))
		{
			m.AddFruit(f);
		}
	}

	return m;
}

void Gamer::RestoreMemento(Memento memento)
{
	mMoney = memento.mMoney;
	mFruits = memento.GetFruits();
}

std::string Gamer::ToString()
{
	std::string str = "[money = " + std::to_string(mMoney);
	str += ", fruits = ";
	for (auto& f : mFruits)
	{
		str += f + ",";
	}
	str += "]";
	return str;
}

std::string Gamer::GetFruit()
{
	std::random_device rnd;
	std::mt19937 mt(rnd());
	std::uniform_int_distribution<> randHand50(0, 100);
	std::string prefix;
	if (randHand50(mt) < 50)
	{
		prefix = "yammy";
	}

	std::uniform_int_distribution<> randHand6(0, mFruitsName.size()-1);
	return prefix + mFruitsName[randHand6(mt)];
}
