#include <iostream>
#include <map>

class User
{
public:
	User(std::string _name);

private:
	std::string name;
	int balance;
};

class Bank
{
public:
	Bank();
	void AddUser();
	void IncreaseBalance();
	void DecreaseBalance();
	int GetBalance() const;

private:
	std::map<int, User> users;
};

int main()
{
	std::cout << "Hello World!\n";
}