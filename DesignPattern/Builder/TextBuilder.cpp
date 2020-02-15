#include "TextBuilder.h"

void TextBuilder::MakeTitle(std::string title)
{
	mBuffer += "==========================\n";
	mBuffer += "[" + title + "]\n";
	mBuffer += "\n";
}

void TextBuilder::MakeString(std::string str)
{
	mBuffer += "<" + str + ">" + "\n";
	mBuffer += "\n";
}

void TextBuilder::MakeItems(std::vector<std::string> items)
{
	for (auto& text : items)
	{
		mBuffer += " ÅE" + text + "\n";
	}

	mBuffer += "\n";
}

void TextBuilder::Close()
{
	mBuffer += "==========================\n";

}

std::string TextBuilder::GetResult()
{
	return mBuffer;
}
