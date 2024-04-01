#include "Bank.h"

int Bank::id_counter = 1;

int Bank::AddUser(const std::string& username)
{
	User user(username);
	int id = id_counter;

	users.insert(std::make_pair(id, user));

	id_counter++;

	return id;
}

void Bank::IncreaseUserBalance(const int id, const double value)
{
	users.at(id).IncreaseBalance(value);
}

void Bank::DecreaseUserBalance(const int id, const double value)
{
	users.at(id).DecreaseBalance(value);
}

double Bank::GetUserBalance(const int id) const
{
	return users.at(id).GetBalance();
}

size_t Bank::GetUsersCount() const
{
	return users.size();
}
