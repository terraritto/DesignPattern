#include "Tray.h"

Tray::Tray(std::string caption)
	: Item(caption)
{
}

void Tray::Add(Item* item)
{
	mTray.push_back(item);
}
