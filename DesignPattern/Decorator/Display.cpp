#include "Display.h"
#include <iostream>

void Display::Show()
{
	for (int i = 0; i < GetRows(); i++)
	{
		std::cout << GetRowText(i) << std::endl;
	}
}
