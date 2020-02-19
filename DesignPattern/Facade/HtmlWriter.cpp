#include "HtmlWriter.h"
#include <iostream>

void HtmlWriter::Title(std::string title)
{
	writer += "<html>";
	writer += "<head>";
	writer += "<title>" + title + "</title>";
	writer += "</head>";
	writer += "<body>\n";
	writer += "<h1>" + title + "</h1>";
}

void HtmlWriter::Paragraph(std::string msg)
{
	writer += "<p>" + msg + "</p>\n";
}

void HtmlWriter::Link(std::string href, std::string caption)
{
	writer += "<a href=\"" + href + "\">" + caption + "</a>";
}

void HtmlWriter::MailTo(std::string mailaddr, std::string username)
{
	Link("mailto:" + mailaddr, username);
}

void HtmlWriter::Output()
{
	writer += "</body>";
	writer += "</html>\n";
	std::cout << writer << std::endl;
}
