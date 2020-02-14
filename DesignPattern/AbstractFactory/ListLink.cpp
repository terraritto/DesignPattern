#include "ListLink.h"

ListLink::ListLink(std::string caption, std::string url)
	: Link(caption, url)
{
}

std::string ListLink::MakeHTML()
{
	std::string str =
		"  <li><a href=\"" + mUrl + "\">" + mCaption + "</a></li>\n";

	return str;
}
