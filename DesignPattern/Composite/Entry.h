#pragma once
#include <string>

class Entry
{
public:
	virtual std::string GetName() = 0;
	virtual int GetSize() = 0;
	virtual Entry* Add(Entry* entry);
	virtual void PrintList(std::string prefix) = 0;
	virtual void PrintList();
	std::string ToString();
};