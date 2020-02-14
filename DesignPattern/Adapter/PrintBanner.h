#pragma once
#include "Banner.h"
#include "Print.h"

class PrintBanner : public Print
{
public:
	PrintBanner(std::string str);
	void PrintWeak() override;
	void PrintStrong() override;
private:
	Banner mBanner;
};