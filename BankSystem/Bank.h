#pragma once

#include <map>
#include <unordered_map>
#include "User.h"

class Bank
{
public:
	Bank() = default;
	int AddUser(const std::string& username);
	void IncreaseUserBalance(const int id, const double value);
	void DecreaseUserBalance(const int id, const double value);
	double GetUserBalance(const int id) const;
	size_t GetUsersCount() const;

private:
	std::unordered_map<int, User> users;

	static int id_counter;
};
