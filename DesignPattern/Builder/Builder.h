#pragma once
#include <vector>
#include <string>

class Builder
{
public:
	virtual void MakeTitle(std::string title) = 0;
	virtual void MakeString(std::string str) = 0;
	virtual void MakeItems(std::vector<std::string> items) = 0;
	virtual void Close() = 0;
};