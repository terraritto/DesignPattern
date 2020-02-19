#include "IDCardFactory.h"
#include "Product.h"
#include <memory>
#include <iostream>

int main()
{
	std::shared_ptr<Factory> factory = std::make_shared<IDCardFactory>();

	std::shared_ptr<Product> card1(factory->Create("test1"));
	std::shared_ptr<Product> card2(factory->Create("test2"));
	std::shared_ptr<Product> card3(factory->Create("test3"));

	card1->Use();
	card2->Use();
	card3->Use();

	return 0;
}