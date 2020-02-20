#include "BookShelfIterator.h"

BookShelfIterator::BookShelfIterator(BookShelf bookShelf)
	: mBookShelf(bookShelf)
	, mIndex(0)
{

}

bool BookShelfIterator::HasNext()
{
	if (mIndex < mBookShelf.GetLength())
	{
		return true;
	}
	else
	{
		return false;
	}
}

Book BookShelfIterator::Next()
{
	Book book = mBookShelf.GetBookAt(mIndex);
	mIndex++;
	return book;
}
