#include "bank-system.hpp"

#include <new>
#include <stdexcept>
#include <algorithm>

BankAccount *BankSystem::findAccount(std::string holderName) const
{
  for (auto account : accounts)
  {
    if (account->getHolderName() == holderName)
      return account;
  }
  return nullptr;
}

int BankSystem::addAccount(BankAccount *account)
{
  if (std::find(accounts.begin(), accounts.end(), account) != accounts.end())
    return -1;

  accounts.push_back(account);
  return 0;
}

int BankSystem::deposit(std::string holderName, double amount)
{
  auto account = findAccount(holderName);
  if (account == nullptr)
    return -1;

  return account->deposit(amount);
}

int BankSystem::withdraw(std::string holderName, double amount)
{
  auto account = findAccount(holderName);
  if (account == nullptr)
    return -1;

  return account->withdraw(amount);
}

double BankSystem::getBalance(std::string holderName) const
{
  auto account = findAccount(holderName);
  if (account == nullptr)
    throw new std::out_of_range("Could not get balance, account does not exist!");

  return account->checkBalance();
}
