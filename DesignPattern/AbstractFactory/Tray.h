#pragma once
#include "Item.h"
#include <vector>

class Tray : public Item
{
public:
	Tray(std::string caption);
	void Add(Item* item);
protected:
	std::vector<Item*> mTray;
};