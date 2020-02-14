#pragma once
#include <string>
#include <vector>
#include "Item.h"

class Page
{
public:
	Page(std::string title, std::string author);
	void Add(Item* item);
	void Output();
	virtual std::string MakeHTML() = 0;
protected:
	std::string mTitle;
	std::string mAuthor;
	std::vector<Item*> mContent;
};