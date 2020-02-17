#pragma once
#include "Border.h"

class SideBorder : public Border
{
public:
	SideBorder(Display* disp, char ch);
	int GetColumns() override;
	int GetRows() override;
	std::string GetRowText(int row) override;
private:
	char mBorderChar;
};