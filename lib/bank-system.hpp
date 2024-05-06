#pragma once

#include <string>
#include <vector>
#include "bank-account.hpp"

class BankSystem
{
private:
  std::vector<BankAccount *> accounts;

  BankAccount *findAccount(std::string holderName) const;

public:
  int addAccount(BankAccount *account);
  int deposit(std::string holderName, double amount);
  int withdraw(std::string holderName, double amount);
  double getBalance(std::string holderName) const;
};
