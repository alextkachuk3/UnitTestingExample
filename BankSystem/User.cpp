#include "User.h"

User::User(const std::string& _name)
{
	name = _name;
	balance = 0.0;
}

void User::IncreaseBalance(const double value)
{
	balance += value;
}

void User::DecreaseBalance(const double value)
{
	balance -= value;
}

double User::GetBalance() const
{
	return balance;
}

const std::string& User::GetName() const
{
	return name;
}
