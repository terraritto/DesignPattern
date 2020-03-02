#pragma once
#include "Visitor.h"
#include <string>

class File;
class Directory;

class ListVisitor : public Visitor
{
public:
	void Visit(File* file) override;
	void Visit(Directory* dir) override;
private:
	std::string mCurrentDir = "";
};