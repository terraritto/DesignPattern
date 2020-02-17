#pragma once
#include "Entry.h"

class File : public Entry
{
public:
	File(std::string name, int size);
	std::string GetName() override;
	int GetSize() override;
	void PrintList(std::string prefix) override;

private:
	std::string mName;
	int mSize;
};