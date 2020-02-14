#include "ListPage.h"

ListPage::ListPage(std::string title, std::string author)
	: Page(title,author)
{
}

std::string ListPage::MakeHTML()
{
	std::string buffer;
	buffer += "<html><head><title>" + mTitle + "</title></head>\n";
	buffer += "<body>\n";
	buffer += "<h1>" + mTitle + "</h1>\n";
	buffer += "<ul>\n";
	for (auto& text : mContent)
	{
		buffer += text->MakeHTML();
	}
	buffer += "</ul>\n";
	buffer += "<hr><address>" + mAuthor + "</address>";
	buffer += "</body></html>\n";
	return buffer;
}
