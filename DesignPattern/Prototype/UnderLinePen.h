#pragma once
#include "Product.h"

class UnderLinePen :public Product
{
public:
	UnderLinePen(char ulchar);
	void Use(std::string s) override;
	Product* CreateClone() override;
private:
	char mUlChar;
};