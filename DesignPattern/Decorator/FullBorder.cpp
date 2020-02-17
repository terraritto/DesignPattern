#include "FullBorder.h"

FullBorder::FullBorder(Display* disp)
	: Border(disp)
{
}

int FullBorder::GetColumns()
{
	return 1 + mDisp->GetColumns() + 1;
}

int FullBorder::GetRows()
{
	return 1 + mDisp->GetRows() + 1;
}

std::string FullBorder::GetRowText(int row)
{
	if (row == 0)
	{
		return "+" + MakeLine('-', mDisp->GetColumns()) + "+";
	}
	else if (row == mDisp->GetRows() + 1)
	{
		return "+" + MakeLine('-', mDisp->GetColumns()) + "+";
	}
	else
	{
		return "|" + mDisp->GetRowText(row - 1) + "|";
	}
}

std::string FullBorder::MakeLine(char ch, int count)
{
	std::string buf;
	for (int i = 0; i < count; i++)
	{
		buf += ch;
	}

	return buf;
}
