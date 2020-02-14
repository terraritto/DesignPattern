#pragma once
#include "Link.h"
#include "Tray.h"
#include "Page.h"

class Factory
{
public:
	template<class T>
	static Factory* GetFactory()
	{
		Factory* factory = new T();

		return factory;
	}

	virtual Link* CreateLink(std::string caption, std::string url) = 0;
	virtual Tray* CreateTray(std::string caption) = 0;
	virtual Page* CreatePage(std::string title, std::string author) = 0;
};
