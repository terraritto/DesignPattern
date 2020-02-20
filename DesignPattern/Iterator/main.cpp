#include "BookShelf.h"
#include "Iterator.h"
#include <iostream>
#include <memory>

int main()
{
	BookShelf bookShelf(4);
	bookShelf.AppendBook(Book("test1"));
	bookShelf.AppendBook(Book("test2"));
	bookShelf.AppendBook(Book("test3"));
	bookShelf.AppendBook(Book("test4"));

	std::shared_ptr<Iterator> it = std::shared_ptr<Iterator>(bookShelf.Iter());

	while (it->HasNext())
	{
		Book book = it->Next();
		std::cout << book.GetName() << std::endl;
	}

	return 0;
}