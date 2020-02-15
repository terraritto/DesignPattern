#pragma once
#include "Display.h"

class CountDisplay : public Display
{
public:
	CountDisplay(DisplayImpl* impl);
	void MultiDisplay(int times);
};