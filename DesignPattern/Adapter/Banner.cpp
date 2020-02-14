#include "Banner.h"

Banner::Banner(std::string str)
	: mStr(str)
{
}

void Banner::ShowWithParen()
{
	std::cout << "(" << mStr << ")" << std::endl;
}

void Banner::ShowWithAster()
{
	std::cout << "*" << mStr << "*" << std::endl;

}
