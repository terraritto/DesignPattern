#include "ListFactory.h"
#include "ListLink.h"
#include "ListPage.h"
#include "ListTray.h"

Link* ListFactory::CreateLink(std::string caption, std::string url)
{
	return new ListLink(caption, url);
}

Tray* ListFactory::CreateTray(std::string caption)
{
	return new ListTray(caption);
}

Page* ListFactory::CreatePage(std::string title, std::string author)
{
	return new ListPage(title, author);
}
