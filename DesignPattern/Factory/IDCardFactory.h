#pragma once
#include "Factory.h"
#include "IDCard.h"
#include <vector>

class IDCardFactory : public Factory
{
public:
	std::vector<Product*> GetOwners();
protected:
	Product* CreateProduct(std::string owner) override;
	void RegisterProduct(Product* product) override;
private:
	std::vector<Product*> mOwners;
};