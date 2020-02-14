#pragma once
#include "Factory.h"

class ListFactory : public Factory
{
public:
	Link* CreateLink(std::string caption, std::string url) override;
	Tray* CreateTray(std::string caption) override;
	Page* CreatePage(std::string title, std::string author) override;
};