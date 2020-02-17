#include "Entry.h"

Entry* Entry::Add(Entry* entry)
{
	return nullptr;
}

void Entry::PrintList()
{
	PrintList("");
}

std::string Entry::ToString()
{
	return GetName() + "(" + std::to_string(GetSize()) + ")";
}
