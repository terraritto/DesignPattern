#pragma once
#include "Item.h"

class Link : public Item
{
public:
	Link(std::string caption, std::string url);
	virtual std::string MakeHTML() override = 0;
protected:
	std::string mUrl;
};