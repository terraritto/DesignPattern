#include "Factory.h"

Product* Factory::Create(std::string owner)
{
	Product* p = CreateProduct(owner);
	RegisterProduct(p);
	return p;
}
