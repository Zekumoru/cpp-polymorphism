#pragma once

#include <string>

/**
 * @brief Represents a generic bank account.
 */
class BankAccount
{
protected:
  std::string holderName; /**< The name of the account holder. */
  double balance;         /**< The current balance of the account. */

public:
  /**
   * @brief Constructs a BankAccount object with the specified holder name and a zero balance.
   * @param holderName The name of the account holder.
   */
  BankAccount(std::string holderName);

  /**
   * @brief Constructs a BankAccount object with the specified holder name and initial balance.
   * @param holderName The name of the account holder.
   * @param balance The initial balance of the account.
   */
  BankAccount(std::string holderName, double balance);

  /**
   * @brief Deposits the specified amount into the account.
   * @param amount The amount to deposit.
   * @return An integer indicating the success or failure of the deposit operation.
   */
  virtual int deposit(double amount);

  /**
   * @brief Withdraws the specified amount from the account.
   * @param amount The amount to withdraw.
   * @return An integer indicating the success or failure of the withdrawal operation.
   */
  virtual int withdraw(double amount);

  /**
   * @brief Retrieves the current balance of the account.
   * @return The current balance of the account.
   */
  double checkBalance() const;

  /**
   * @brief Retrieves the name of the account holder.
   * @return The name of the account holder.
   */
  std::string getHolderName() const;
};

/**
 * @brief Represents a checking account, derived from BankAccount.
 */
class CheckingAccount : public BankAccount
{
private:
  double overdrawnLimit; /**< The maximum amount that can be overdrawn. */

public:
  /**
   * @brief Constructs a CheckingAccount object with the specified holder name and overdrawn limit.
   * @param holderName The name of the account holder.
   * @param overdrawnLimit The maximum amount that can be overdrawn.
   */
  CheckingAccount(std::string holderName, double overdrawnLimit);

  /**
   * @brief Constructs a CheckingAccount object with the specified holder name, overdrawn limit, and initial balance.
   * @param holderName The name of the account holder.
   * @param overdrawnLimit The maximum amount that can be overdrawn.
   * @param balance The initial balance of the account.
   */
  CheckingAccount(std::string holderName, double overdrawnLimit, double balance);

  /**
   * @brief Deducts fees from the account.
   * @param amount The amount of fees to deduct.
   * @return An integer indicating the success or failure of the fee deduction operation.
   */
  int deductFees(double amount);

  /**
   * @brief Overrides the withdraw method to allow for overdrawing within the specified limit.
   * @param amount The amount to withdraw.
   * @return An integer indicating the success or failure of the withdrawal operation.
   */
  int withdraw(double amount) override;

  /**
   * @brief Checks if the account is currently overdrawn.
   * @return True if the account is overdrawn, false otherwise.
   */
  bool isOverdrawn() const;

  /**
   * @brief Retrieves the overdrawn limit of the account.
   * @return The overdrawn limit of the account.
   */
  double getOverdrawnLimit() const;
};

/**
 * @brief Represents a savings account, derived from BankAccount.
 */
class SavingsAccount : public BankAccount
{
private:
  double annualInterestRate; /**< The annual interest rate of the account. */

public:
  /**
   * @brief Constructs a SavingsAccount object with the specified holder name and annual interest rate.
   * @param holderName The name of the account holder.
   * @param annualInterestRate The annual interest rate of the account.
   */
  SavingsAccount(std::string holderName, double annualInterestRate);

  /**
   * @brief Constructs a SavingsAccount object with the specified holder name, annual interest rate, and initial balance.
   * @param holderName The name of the account holder.
   * @param annualInterestRate The annual interest rate of the account.
   * @param balance The initial balance of the account.
   */
  SavingsAccount(std::string holderName, double annualInterestRate, double balance);

  /**
   * @brief Applies annual interest to the account balance.
   */
  void applyAnnualInterest();

  /**
   * @brief Retrieves the annual interest rate of the account.
   * @return The annual interest rate of the account.
   */
  double getAnnualInterestRate() const;

  /**
   * @brief Sets the annual interest rate of the account.
   * @param rate The new annual interest rate.
   * @throws std::invalid_argument if the rate given is negative.
   */
  void setAnnualInterestRate(double rate);
};
