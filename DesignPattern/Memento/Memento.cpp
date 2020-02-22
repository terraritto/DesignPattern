#include "Memento.h"

int Memento::GetMoney()
{
	return mMoney;
}

Memento::Memento(int money)
	: mMoney(money)
{
}

void Memento::AddFruit(std::string fruit)
{
	mFruits.push_back(fruit);
}

std::vector<std::string> Memento::GetFruits()
{
	return mFruits;
}
