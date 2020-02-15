#include "CountDisplay.h"

CountDisplay::CountDisplay(DisplayImpl* impl)
	: Display(impl)
{
}

void CountDisplay::MultiDisplay(int times)
{
	Open();
	for (int i = 0; i < times; i++)
	{
		Print();
	}
	Close();
}
