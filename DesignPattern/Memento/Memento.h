#pragma once
#include <string>
#include <vector>

class Memento
{
public:
	int GetMoney();
	Memento(int money);
	void AddFruit(std::string fruit);
	std::vector<std::string> GetFruits();
public:
	int mMoney;
	std::vector<std::string> mFruits;
};