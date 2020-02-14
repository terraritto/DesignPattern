#pragma once
#include <string>
#include <iostream>

class Banner
{
public:
	Banner(std::string str);
	void ShowWithParen();
	void ShowWithAster();
private:
	std::string mStr;
};