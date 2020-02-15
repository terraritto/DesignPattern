#include "Director.h"
#include "HTMLBuilder.h"
#include "TextBuilder.h"
#include <iostream>
#include <memory>

int main()
{
	int select;

	std::cout << "select text:0 html:1 >> ";
	std::cin >> select;

	if (select == 0)
	{
		std::shared_ptr<TextBuilder> textBuilder = std::make_shared<TextBuilder>();
		Director director(textBuilder.get());
		director.Construct();
		std::cout << textBuilder->GetResult() << std::endl;
	}

	if (select == 1)
	{
		std::shared_ptr<HTMLBuilder> htmlBuilder = std::make_shared<HTMLBuilder>();
		Director director(htmlBuilder.get());
		director.Construct();
		std::cout << htmlBuilder->GetFileName() << "is generated." << std::endl;
		std::cout << htmlBuilder->GetResult() << std::endl;
	}
}