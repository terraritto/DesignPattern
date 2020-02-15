#pragma once
#include "Builder.h"

class Director
{
public:
	Director(Builder* build);
	void Construct();
private:
	Builder* mBuilder;
};