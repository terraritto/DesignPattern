#pragma once
#include "Memento.h"
#include <vector>
#include <string>

class Gamer
{
public:
	Gamer(int money);
	int GetMoney();
	void Bet();
	Memento CreateMemento();
	void RestoreMemento(Memento memento);
	std::string ToString();
	std::string GetFruit();
private:
	int mMoney;
	std::vector<std::string> mFruits;
	static std::vector<std::string> mFruitsName;
};