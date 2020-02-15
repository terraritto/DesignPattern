#pragma once
#include "Builder.h"

class HTMLBuilder : public Builder
{
public:
	void MakeTitle(std::string title) override;
	void MakeString(std::string str) override;
	void MakeItems(std::vector<std::string> items) override;
	void Close() override;
	std::string GetResult();
	std::string GetFileName();
private:
	std::string mFileName;
	std::string mWriter; // simplify
};