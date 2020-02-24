#include "MessageBox.h"
#include <iostream>

MessageBox::MessageBox(char decoChar)
	: mDecoChar(decoChar)
{
}

void MessageBox::Use(std::string s)
{
	int length = s.size();
	
	for (int i = 0; i < length + 4; i++)
	{
		std::cout << mDecoChar;
	}
	std::cout << std::endl;

	std::cout << mDecoChar << " " << s << " " << mDecoChar << std::endl;
	
	for (int i = 0; i < length + 4; i++)
	{
		std::cout << mDecoChar;
	}
	std::cout << std::endl;
}

Product* MessageBox::CreateClone()
{
	Product* p = new MessageBox(*this);

	return p;
}
