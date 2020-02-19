#pragma once
#include "Product.h"
#include <string>

class IDCard : public Product
{
public:
	IDCard(std::string owner);
	void Use() override;
	std::string GetOwner();
private:
	std::string mOwner;
};