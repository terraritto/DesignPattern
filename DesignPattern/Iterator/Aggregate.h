#pragma once
#include "Iterator.h"

class Aggregate
{
public:
	virtual Iterator* Iter() = 0;
};