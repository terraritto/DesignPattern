#pragma once
#include "DisplayImpl.h"
#include <string>

class StringDisplayImpl : public DisplayImpl
{
public:
	StringDisplayImpl(std::string str);
	void RawOpen() override;
	void RawPrint() override;
	void RawClose() override;
private:
	std::string mStr;
	int mWidth;

	void PrintLine();
};