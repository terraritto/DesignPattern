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

void Directory::PrintList(std::string prefix)
{
	std::cout << prefix + "/" + GetName() << std::endl;

	for (auto& dir : mDirectory)
	{
		dir->PrintList(prefix + "/" + mName);
	}
}

void Directory::PrintList()
{
	PrintList("");
}
