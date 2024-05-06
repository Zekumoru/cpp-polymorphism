#include <iostream>
#include <iomanip>
#include "lib/bank-account.hpp"

int main()
{
  SavingsAccount account("Erea Fotia", 0.04);

  account.deposit(100);

  std::cout << std::fixed << std::setprecision(2);
  std::cout << "Balance: €" << account.checkBalance() << std::endl;

  std::cout << "Applying annual rate..." << std::endl;
  account.applyAnnualInterest();

  std::cout << "Balance: €" << account.checkBalance() << std::endl;

  return 0;
}
