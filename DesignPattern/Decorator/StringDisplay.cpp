#include "StringDisplay.h"

StringDisplay::StringDisplay(std::string str)
	: mStr(str)
{
}

int StringDisplay::GetColumns()
{
	return mStr.size();
}

int StringDisplay::GetRows()
{
	return 1;
}

std::string StringDisplay::GetRowText(int row)
{
	if (row == 0)
	{
		return mStr;
	}
	else
	{
		return std::string("");
	}
}
