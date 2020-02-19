#include "IDCardFactory.h"
#include "IDCard.h"

std::vector<Product*> IDCardFactory::GetOwners()
{
	return mOwners;
}

Product* IDCardFactory::CreateProduct(std::string owner)
{
	return new IDCard(owner);
}

void IDCardFactory::RegisterProduct(Product* product)
{
	mOwners.push_back(product);
}
