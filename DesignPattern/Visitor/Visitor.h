#pragma once

class File;
class Directory;

class Visitor
{
public:
	virtual void Visit(File* file) = 0;
	virtual void Visit(Directory* dir) = 0;
};