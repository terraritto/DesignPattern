#include "PageMaker.h"
#include <iostream>

void PageMaker::MakeWelcomePage(std::string mailaddr, std::string filename)
{
	std::string username = Database::GetProperties(mailaddr);

	HtmlWriter writer = HtmlWriter();
	writer.Title("Welcome to " + username + "'s page!");
	writer.Paragraph(username + "'s page.");
	writer.Paragraph("I'll wait a mail.");
	writer.MailTo(mailaddr, username);
	std::cout << "generated!!" << std::endl;

	writer.Output();
}
