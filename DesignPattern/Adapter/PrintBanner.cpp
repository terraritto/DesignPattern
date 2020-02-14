#include "PrintBanner.h"

PrintBanner::PrintBanner(std::string str)
	: mBanner(Banner(str))
{
}

void PrintBanner::PrintWeak()
{
	mBanner.ShowWithParen();
}

void PrintBanner::PrintStrong()
{
	mBanner.ShowWithAster();
}
