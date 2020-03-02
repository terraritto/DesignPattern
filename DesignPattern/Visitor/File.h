#pragma once
#include "Entry.h"

class Entry;
class Visitor;

class File : public Entry
{
public:
	File(std::string name, int size);
	std::string GetName() override;
	int GetSize() override;
	void Accept(Visitor* v) override;
private:
	std::string mName;
	int mSize;
};