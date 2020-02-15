#pragma once
#include <string>
#include "Trouble.h"

class Support
{
public:
	Support(std::string name);
	virtual Support* SetNext(Support* next) final;
	void support(Trouble* trouble);
	std::string ToString();
protected:
	virtual bool Resolve(Trouble* trouble) = 0;
	void Done(Trouble* trouble);
	void Fail(Trouble* trouble);
private:
	std::string mName;
	Support* mNext;
};