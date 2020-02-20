#include "Book.h"

Book::Book(std::string name)
	: mName(name)
{
}

std::string Book::GetName()
{
	return mName;
}
