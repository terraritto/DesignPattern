#include "Display.h"

Display::Display(DisplayImpl* impl)
	: mImpl(impl)
{
}

void Display::Open()
{
	mImpl->RawOpen();
}

void Display::Print()
{
	mImpl->RawPrint();
}

void Display::Close()
{
	mImpl->RawClose();
}

void Display::Disp()
{
	Open();
	Print();
	Close();
}
