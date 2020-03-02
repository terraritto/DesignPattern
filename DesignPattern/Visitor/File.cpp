#include "File.h"
#include <iostream>

File::File(std::string name, int size)
	: mName(name)
	, mSize(size)
{
}

std::string File::GetName()
{
	return mName;
}

int File::GetSize()
{
	return mSize;
}

void File::Accept(Visitor* v)
{
	v->Visit(this);
}
