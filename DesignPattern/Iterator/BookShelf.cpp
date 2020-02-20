#include "BookShelf.h"
#include "BookShelfIterator.h"

BookShelf::BookShelf(int maxSize)
	: mLast(0)
{
	mBooks.reserve(maxSize);
}

Book BookShelf::GetBookAt(int index)
{
	return mBooks[index];
}

void BookShelf::AppendBook(Book book)
{
	mBooks.push_back(book);
	mLast++;
}

int BookShelf::GetLength()
{
	return mLast;
}

Iterator* BookShelf::Iter()
{
	return new BookShelfIterator(*this);
}

