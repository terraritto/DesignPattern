#pragma once
#include <string>

class Item
{
public: 
	virtual std::string MakeHTML() = 0;
	Item(std::string caption);
protected:
	std::string mCaption;
};