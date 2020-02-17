#pragma once
#include "Entry.h"
#include <vector>

class Directory : public Entry
{
public:
	Directory(std::string name);
	std::string GetName() override;
	int GetSize() override;
	Entry* Add(Entry* entry) override;
	void PrintList(std::string prefix) override;
	void PrintList() override;
private:
	std::string mName;
	std::vector<Entry*> mDirectory;
};