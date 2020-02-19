#pragma once
#include "Database.h"
#include "HtmlWriter.h"
#include <string>

class PageMaker
{
public:
	static void MakeWelcomePage(std::string mailaddr, std::string filename);
private:
	PageMaker();
};