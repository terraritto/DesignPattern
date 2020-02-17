#pragma once
#include <string>

class Display
{
public:
	virtual int GetColumns() = 0;
	virtual int GetRows() = 0;
	virtual std::string GetRowText(int row) = 0;
	virtual void Show() final;
};