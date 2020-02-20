#pragma once
#include "BookShelf.h"

class BookShelfIterator : public Iterator
{
public:
	BookShelfIterator(BookShelf bookShelf);
	bool HasNext() override;
	Book Next() override;
private:
	BookShelf mBookShelf;
	int mIndex;
};