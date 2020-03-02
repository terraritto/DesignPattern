#include "Directory.h"
#include <iostream>

Directory::Directory(std::string name)
	: mName(name)
{
}

std::string Directory::GetName()
{
	return mName;
}

int Directory::GetSize()
{
	int size = 0;
	for (auto& dir : mDirectory)
	{
		size += dir->GetSize();
	}

	return size;
}

Entry* Directory::Add(Entry* entry)
{
	mDirectory.push_back(entry);
	return this;
}

void Directory::Accept(Visitor* v)
{
	v->Visit(this);
}

const std::vector<Entry*>& Directory::GetDir()
{
	return mDirectory;
}
