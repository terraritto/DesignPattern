#include "HTMLBuilder.h"

void HTMLBuilder::MakeTitle(std::string title)
{
	mFileName = title + ".html";

	mWriter += "<html><head><title>" + title + "</title></head><body>" + "\n";
	mWriter += "<h1>" + title + "</h1>" + "\n";
}

void HTMLBuilder::MakeString(std::string str)
{
	mWriter += "<p>" + str + "</p>" + "\n";
}

void HTMLBuilder::MakeItems(std::vector<std::string> items)
{
	mWriter += "<ul>" + static_cast<std::string>("\n");

	for (auto& text : items)
	{
		mWriter += "<li>" + text + "</li>" + "\n";
	}

	mWriter += "</ul>" + static_cast<std::string>("\n");
}

void HTMLBuilder::Close()
{
	mWriter += "</body></html>" + static_cast<std::string>("\n");

}

std::string HTMLBuilder::GetResult()
{
	return mWriter;
}

std::string HTMLBuilder::GetFileName()
{
	return mFileName;
}
