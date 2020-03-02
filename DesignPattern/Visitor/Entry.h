#pragma once
#include <string>
#include "Element.h"

class Entry : public Element
{
public:
	virtual std::string GetName() = 0;
	virtual int GetSize() = 0;
	virtual Entry* Add(Entry* entry);
	std::string ToString();
};