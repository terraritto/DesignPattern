#include "Page.h"
#include <iostream>

Page::Page(std::string title, std::string author)
	: mTitle(title)
	, mAuthor(author)
{
}

void Page::Add(Item* item)
{
	mContent.push_back(item);
}

void Page::Output()
{
	std::cout << MakeHTML() << std::endl;
}