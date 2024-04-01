#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#define private public

#include "Bank.h"

namespace UnitTest
{
	TEST_CLASS(UserTest)
	{
	public:
		std::string test_name = "Alex";
		TEST_METHOD(TestInit)
		{			
			User user(test_name);

			Assert::AreEqual(0.0, user.balance);
			Assert::AreEqual(test_name, user.name);
		}

		TEST_METHOD(TestUserGetBalance)
		{
			User user(test_name);

			double test_balance_value = 100.2;

			user.balance = test_balance_value;

			Assert::AreEqual(test_balance_value, user.GetBalance());
		}

		TEST_METHOD(TestUserGetName)
		{
			User user(test_name);

			Assert::AreEqual(test_name, user.GetName());
		}

		TEST_METHOD(TestIncreaseUserBalance)
		{
			User user(test_name);

			double test_increase_balance_value = 150.2;

			user.IncreaseBalance(test_increase_balance_value);

			Assert::AreEqual(user.balance, test_increase_balance_value);
		}

		TEST_METHOD(TestMultipleIncreaseUserBalance)
		{
			User user(test_name);

			double test_increase_balance_first_value = 140.2;
			double test_increase_balance_second_value = 20.2;
			double test_balance_sum = test_increase_balance_first_value + test_increase_balance_second_value;

			user.IncreaseBalance(test_increase_balance_first_value);

			Assert::AreEqual(user.balance, test_increase_balance_first_value);

			user.IncreaseBalance(test_increase_balance_second_value);

			Assert::AreEqual(user.balance, test_balance_sum);
		}

		TEST_METHOD(TestDecreaseUserBalance)
		{
			User user(test_name);

			double test_increase_balance_first_value = 140.2;

			user.DecreaseBalance(test_increase_balance_first_value);

			Assert::AreEqual(user.balance, -test_increase_balance_first_value);
		}

		TEST_METHOD(TestMultipleDecreaseUserBalance)
		{
			User user(test_name);

			double test_increase_balance_first_value = 140.2;
			double test_increase_balance_second_value = 20.2;
			double test_balance_sum = test_increase_balance_first_value + test_increase_balance_second_value;

			user.DecreaseBalance(test_increase_balance_first_value);

			Assert::AreEqual(user.balance, -test_increase_balance_first_value);

			user.DecreaseBalance(test_increase_balance_second_value);

			Assert::AreEqual(user.balance, -test_balance_sum);
		}
	};

	TEST_CLASS(BankTest)
	{
	public:
		TEST_METHOD(TestEmptyBankUsersCount)
		{
			Bank bank;

			Assert::AreEqual(size_t(0), bank.GetUsersCount());
		}

		TEST_METHOD(TestBankUsersCount)
		{
			Bank bank;

			bank.AddUser("Jame");
			bank.AddUser("David");
			bank.AddUser("Alex");

			Assert::AreEqual(size_t(3), bank.GetUsersCount());
		}

		TEST_METHOD(TestNotExistUserIncreaseBalance)
		{
			Bank bank;

			Assert::ExpectException<std::out_of_range>([&]() {
				bank.IncreaseUserBalance(1, 0.0);
			});
		}

		TEST_METHOD(TestNotExistUserDecreaseBalance)
		{
			Bank bank;

			Assert::ExpectException<std::out_of_range>([&]() {
				bank.DecreaseUserBalance(1, 0.0);
				});
		}

		TEST_METHOD(TestUserIncreaseBalance)
		{
			Bank bank;

			std::string test_username = "Alex";
			double test_increase_balance_value = 117.4;

			int new_user_id = bank.AddUser(test_username);

			bank.IncreaseUserBalance(new_user_id, test_increase_balance_value);

			Assert::AreEqual(test_increase_balance_value, bank.GetUserBalance(new_user_id));
		}

		TEST_METHOD(TestUserDecreaseBalance)
		{
			Bank bank;

			std::string test_username = "Alex";
			double test_increase_balance_value = 117.4;

			int new_user_id = bank.AddUser(test_username);

			bank.DecreaseUserBalance(new_user_id, test_increase_balance_value);

			Assert::AreEqual(-test_increase_balance_value, bank.GetUserBalance(new_user_id));
		}
	};
}
