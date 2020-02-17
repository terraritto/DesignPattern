#include "SideBorder.h"

SideBorder::SideBorder(Display* disp, char ch)
	: Border(disp)
	, mBorderChar(ch)
{
}

int SideBorder::GetColumns()
{
	return 1 + mDisp->GetColumns() + 1;
}

int SideBorder::GetRows()
{
	return mDisp->GetRows();
}

std::string SideBorder::GetRowText(int row)
{
	return mBorderChar + mDisp->GetRowText(row) + mBorderChar;
}
