#pragma once
#include "Book.h"

class Iterator
{
public:
	virtual bool HasNext() = 0;
	virtual Book Next() = 0;
};