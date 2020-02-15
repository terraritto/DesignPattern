#pragma once
#include "Builder.h"

class TextBuilder : public Builder
{
public:
	void MakeTitle(std::string title) override;
	void MakeString(std::string str) override;
	void MakeItems(std::vector<std::string> items) override;
	void Close() override;
	std::string GetResult();
private:
	std::string mBuffer;
};