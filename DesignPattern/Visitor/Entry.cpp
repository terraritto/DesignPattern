#include "Entry.h"

Entry* Entry::Add(Entry* entry)
{
	return nullptr;
}

std::string Entry::ToString()
{
	return GetName() + "(" + std::to_string(GetSize()) + ")";
}
