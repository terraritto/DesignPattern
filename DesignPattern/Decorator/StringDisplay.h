#pragma once
#include "Display.h"
#include <iostream>

class StringDisplay : public Display
{
public:
	StringDisplay(std::string str);
	int GetColumns() override;
	int GetRows() override;
	std::string GetRowText(int row) override;
private:
	std::string mStr;
};