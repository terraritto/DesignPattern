#include "ListVisitor.h"
#include "File.h"
#include "Directory.h"
#include <iostream>

void ListVisitor::Visit(File* file)
{
	std::cout << mCurrentDir + "/" + file->ToString() << std::endl;
}

void ListVisitor::Visit(Directory* dir)
{
	std::cout << mCurrentDir + "/" + dir->ToString() << std::endl;
	std::string savedir = mCurrentDir;
	mCurrentDir = mCurrentDir + "/" + dir->GetName();

	for (auto& it : dir->GetDir())
	{
		it->Accept(this);
	}
	mCurrentDir = savedir;
}
