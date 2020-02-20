#pragma once
#include <string>
// this class is book
// book has only name

class Book
{
public:
	Book(std::string name);
	std::string GetName();
private:
	std::string mName;
};
