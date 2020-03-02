#pragma once
#include "Visitor.h"

class Visitor;

class Element
{
public:
	virtual void Accept(Visitor* v) = 0;
};