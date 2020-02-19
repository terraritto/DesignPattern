#pragma once
#include <string>

class HtmlWriter
{
public:
	void Title(std::string title);
	void Paragraph(std::string msg);
	void Link(std::string href, std::string caption);
	void MailTo(std::string maikaddr, std::string username);
	void Output();
private:
	std::string writer;
};