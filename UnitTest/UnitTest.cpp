#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#include "Bank.h"

namespace UnitTest
{
	TEST_CLASS(UserTest)
	{
	public:

		TEST_METHOD(TestInit)
		{
			std::string name = "Alex";
			User user(name);

			Assert::AreEqual(0.0, user.GetBalance());
			Assert::AreEqual(name, user.GetName());
		}

		TEST_METHOD(TestUserGetBalance)
		{
			std::string name = "Alex";
			User user(name);

			Assert::AreEqual(0.0, user.GetBalance());
		}

		TEST_METHOD(TestUserGetName)
		{
			std::string name = "Alex";
			User user(name);

			Assert::AreEqual(name, user.GetName());
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
	};
}
