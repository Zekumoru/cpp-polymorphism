/**
 * Implementazione di una Simulazione di un Sistema Bancario
 * Maggio 6, 2024
 *
 * Traccia:
 *
 *    Definisci una classe base `ContoBancario` con sottoclassi
 *    come `ContoCorrente`, `ContoRisparmio`, `ContoInvestimento`, ecc.
 *
 *    Implementa metodi per gestire transazioni bancarie e utilizza il
 *    polimorfismo per gestire diversi tipi di conti all'interno di un
 *    sistema bancario.
 *
 */
#include <iostream>
#include <iomanip>
#include "lib/bank-system.hpp"
#include "lib/bank-account.hpp"

int main()
{
  // Impostare l'output dei double a due decimali.
  std::cout << std::fixed << std::setprecision(2);

  // Creare due tipi di conti bancarie
  auto a1 = new CheckingAccount("Alpha", 100);
  auto a2 = new SavingsAccount("Bravo", 0.04);

  // Creare la banca
  BankSystem bank;

  // Aggiungere i conti alla banca
  bank.addAccount(a1);
  bank.addAccount(a2);

  // Prelevare €100 con il conto corrente di Alpha
  bank.withdraw("Alpha", 100);
  std::cout << "Alpha's checkings account balance: €" << bank.getBalance("Alpha") << std::endl;

  // Depositare €100 al conto risparmio di Bravo ed applicare l'interessa annuale
  bank.deposit("Bravo", 100);
  a2->applyAnnualInterest();
  std::cout << "Bravo's savings account balance: €" << bank.getBalance("Bravo") << std::endl;

  return 0;
}
