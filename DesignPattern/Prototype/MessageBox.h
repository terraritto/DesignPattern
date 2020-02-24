#pragma once
#include "Product.h"

class MessageBox :public Product
{
public:
	MessageBox(char decoChar);
	
	void Use(std::string s) override;
	Product* CreateClone() override;
private:
	char mDecoChar;
};