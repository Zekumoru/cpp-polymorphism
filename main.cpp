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

  return 0;
}
