#pragma once
#include "Product.h"
#include <string>

class Factory
{
public:
	virtual Product* Create(std::string owner) final;
protected:
	virtual Product* CreateProduct(std::string owner) = 0;
	virtual void RegisterProduct(Product* product) = 0;
};