#include <iostream>
#include <iomanip>
#include "lib/bank-account.hpp"

int main()
{
  CheckingAccount account("Erea Fotia", 100);

  account.deposit(0);

  if (account.withdraw(100))
  {
    std::cout << "[ERR] You cannot withdraw that much amount!" << std::endl;
  }

  std::cout << std::fixed << std::setprecision(2);
  std::cout << "Balance: €" << account.checkBalance() << std::endl;

  std::cout << "Deducting acount fees..." << std::endl;
  account.deductFees(10);

  std::cout << "Balance: €" << account.checkBalance() << std::endl;
  if (account.isOverdrawn())
  {
    std::cout << "[INFO] Bank account is overdrawn!" << std::endl;
  }

  return 0;
}
