#pragma once

#include <string>

class BankAccount
{
protected:
  std::string holderName;
  double balance;

public:
  BankAccount(std::string holderName);
  BankAccount(std::string holderName, double balance);

  virtual int deposit(double amount);
  virtual int withdraw(double amount);

  double checkBalance() const;
  std::string getHolderName() const;
};

class CheckingAccount : public BankAccount
{
private:
  double overdrawnLimit; // Maximum amount of money that can be overdrawn.

public:
  CheckingAccount(std::string holderName, double overdrawnLimit);
  CheckingAccount(std::string holderName, double overdrawnLimit, double balance);

  int withdraw(double amount) override;
};
