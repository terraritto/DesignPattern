#pragma once
#include <map>
#include <memory>
#include "Product.h"

class Manager
{
public:
	void Register(std::string name, Product* poto);
	Product* Create(std::string protoName);
private:
	std::map<std::string, Product*> mShowCase;
};