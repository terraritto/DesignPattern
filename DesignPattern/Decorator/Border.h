#pragma once
#include "Display.h"

class Border : public Display
{
protected:
	Display* mDisp;
	Border(Display* disp);
};