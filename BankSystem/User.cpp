#include "User.h"

User::User(const std::string& _name)
{
	name = _name;
	balance = 0;
}

void User::IncreaseBalance(const int value)
{
	balance += value;
}

void User::DecreaseBalance(const int value)
{
	balance -= value;
}

int User::GetBalance() const
{
	return balance;
}
