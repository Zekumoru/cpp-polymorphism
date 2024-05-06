#include "bank-account.hpp"

BankAccount::BankAccount(std::string holderName) : holderName(holderName), balance(0) {}
BankAccount::BankAccount(std::string holderName, double balance) : holderName(holderName), balance(balance) {}

int BankAccount::deposit(double amount)
{
  if (amount < 0)
    return -1;
  balance += amount;
  return 0;
}

int BankAccount::withdraw(double amount)
{
  if (amount < 0)
    return -1;
  if (balance <= 0)
    return -2;
  balance -= amount;
  return 0;
}

double BankAccount::checkBalance() const
{
  return balance;
}

std::string BankAccount::getHolderName() const
{
  return holderName;
}

/**
 * Checking Account
 */

CheckingAccount::CheckingAccount(std::string holderName, double overdrawnLimit) : BankAccount(holderName), overdrawnLimit(overdrawnLimit) {}
CheckingAccount::CheckingAccount(std::string holderName, double overdrawnLimit, double balance) : BankAccount(holderName, balance), overdrawnLimit(overdrawnLimit) {}

int CheckingAccount::deductFees(double amount)
{
  if (amount < 0)
    return -1;

  balance -= amount;
  return 0;
}

int CheckingAccount::withdraw(double amount)
{
  if (amount < 0)
    return -1;
  if (balance - amount < -overdrawnLimit)
    return -2;

  balance -= amount;
  return 0;
}

bool CheckingAccount::isOverdrawn() const
{
  return balance <= -overdrawnLimit;
}

double CheckingAccount::getOverdrawnLimit() const
{
  return overdrawnLimit;
}
