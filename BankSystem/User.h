#pragma once

#include <string>

class User
{
public:
	User(const std::string& _name);
	void IncreaseBalance(const int value);
	void DecreaseBalance(const int value);
	int GetBalance() const;

private:
	double balance;
	std::string name;
};
