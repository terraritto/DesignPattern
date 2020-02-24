#pragma once
#include <string>

class Product
{
public:
	virtual void Use(std::string s)=0;
	virtual Product* CreateClone()=0;
};