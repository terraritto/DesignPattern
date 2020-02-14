#include "ListTray.h"

ListTray::ListTray(std::string caption)
	: Tray(caption)
{
}

std::string ListTray::MakeHTML()
{
	std::string buffer;
	buffer += "<li>\n";
	buffer += mCaption + "\n";
	buffer += "<ul>\n";
	
	for (auto& text : mTray)
	{
		buffer += text->MakeHTML();
	}

	buffer += "</ul>\n";
	buffer += "</li>\n";

	return buffer;
}
