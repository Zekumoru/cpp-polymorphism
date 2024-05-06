#include <iostream>
#include <iomanip>
#include "lib/bank-system.hpp"
#include "lib/bank-account.hpp"

int main()
{
  std::cout << std::fixed << std::setprecision(2);

  auto a1 = new CheckingAccount("Alpha", 100);
  auto a2 = new SavingsAccount("Bravo", 0.04);

  BankSystem bank;
  bank.addAccount(a1);
  bank.addAccount(a2);

  bank.withdraw("Alpha", 100);
  std::cout << "Alpha's checkings account balance: " << bank.getBalance("Alpha") << std::endl;

  bank.deposit("Bravo", 100);
  a2->applyAnnualInterest();
  std::cout << "Bravo's savings account balance: " << bank.getBalance("Bravo") << std::endl;

  return 0;
}
