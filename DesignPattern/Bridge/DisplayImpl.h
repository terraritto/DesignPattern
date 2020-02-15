#pragma once

class DisplayImpl
{
public:
	virtual void RawOpen() = 0;
	virtual void RawPrint() = 0;
	virtual void RawClose() = 0;
};