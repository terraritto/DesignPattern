#include "Manager.h"

void Manager::Register(std::string name, Product* poto)
{
	mShowCase.insert(std::make_pair(name, poto));
}

Product* Manager::Create(std::string protoName)
{
	Product* p = mShowCase.at(protoName);
	return p->CreateClone();
}
