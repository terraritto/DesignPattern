#pragma once
#include "Entry.h"
#include <vector>

class Entry;
class Visitor;

class Directory : public Entry
{
public:
	Directory(std::string name);
	std::string GetName() override;
	int GetSize() override;
	Entry* Add(Entry* entry) override;
	void Accept(Visitor* v) override;
	const std::vector<Entry*>& GetDir();
private:
	std::string mName;
	std::vector<Entry*> mDirectory;
};