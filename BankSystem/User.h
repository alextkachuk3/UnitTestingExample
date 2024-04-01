#pragma once

#include <string>

class User
{
public:
	User(const std::string& _name);
	void IncreaseBalance(const double value);
	void DecreaseBalance(const double value);
	double GetBalance() const;
	const std::string& GetName() const;

private:
	double balance;
	std::string name;
};
