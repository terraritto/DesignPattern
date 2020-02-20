#pragma once
#include "Aggregate.h"
#include "Book.h"
#include <vector>

// bookshelf has many books.

class BookShelf : public Aggregate
{
public:
	BookShelf(int maxSize);
	Book GetBookAt(int index);
	void AppendBook(Book book);
	int GetLength();
	Iterator* Iter() override;
private:
	std::vector<Book> mBooks;
	int mLast;
};