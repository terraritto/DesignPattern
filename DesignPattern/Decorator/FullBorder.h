#pragma once
#include "Border.h"

class FullBorder : public Border
{
public:
	FullBorder(Display* disp);
	int GetColumns() override;
	int GetRows() override;
	std::string GetRowText(int row) override;
private:
	std::string MakeLine(char ch, int count);
};