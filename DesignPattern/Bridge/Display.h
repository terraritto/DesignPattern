#pragma once
#include "DisplayImpl.h"

class Display
{
public:
	Display(DisplayImpl* impl);
	void Open();
	void Print();
	void Close();
	virtual void Disp() final;
private:
	DisplayImpl* mImpl;
};