#pragma once
#include <string>

class Database
{
public:
	static std::string GetProperties(std::string dbname);
private:
	Database();
};