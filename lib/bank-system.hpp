#pragma once

#include <string>
#include <vector>
#include "bank-account.hpp"

/**
 * @brief Represents a system managing bank accounts.
 */
class BankSystem
{
private:
  std::vector<BankAccount *> accounts; /**< The collection of bank accounts managed by the system. */

  /**
   * @brief Finds a bank account by the holder's name.
   * @param holderName The name of the account holder to search for.
   * @return A pointer to the bank account if found, nullptr otherwise.
   */
  BankAccount *findAccount(std::string holderName) const;

public:
  /**
   * @brief Adds a bank account to the system.
   * @param account A pointer to the bank account to add.
   * @return An integer indicating the success or failure of the addition operation.
   */
  int addAccount(BankAccount *account);

  /**
   * @brief Deposits the specified amount into the account of the given holder.
   * @param holderName The name of the account holder.
   * @param amount The amount to deposit.
   * @return An integer indicating the success or failure of the deposit operation.
   */
  int deposit(std::string holderName, double amount);

  /**
   * @brief Withdraws the specified amount from the account of the given holder.
   * @param holderName The name of the account holder.
   * @param amount The amount to withdraw.
   * @return An integer indicating the success or failure of the withdrawal operation.
   */
  int withdraw(std::string holderName, double amount);

  /**
   * @brief Retrieves the balance of the account of the given holder.
   * @param holderName The name of the account holder.
   * @return The balance of the account.
   * @throws std::out_of_range if the account does not exist in the bank system.
   */
  double getBalance(std::string holderName) const;
};
