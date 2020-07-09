/**
 * @file Ex_11_10.h
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Class definitions for Account, SavingsAccount, and CheckingAccount
 * @version 0.1
 * @date 2020-07-09
 * 
 * Exercise 11-10 Account Inheritance Hierarchy
 * 
 * Create an inheritance hierarchy that a bank might use to represent customers' bank accounts. All customers
 * at this bank can deposit (i.e., credit) money into their accounts and withdraw (i.e., debit) money from
 * their accounts.
 * 
 * Create an inheritance hierarchy containing base-class Account and derived classes SavingsAccount and
 * CheckingAccount that derive from class Account. Base-class Account should provide one data member of type
 * double to represent the account balance. The class should provide a constructor that receives an initial
 * balance and uses it to initialize the data member. The class should provide three member functions. Member
 * functions credit should add an amount to the current balance. Member function debit should withdraw money
 * from the balance. If the amount exceeds the Account's balance, the balance should be left unchanged and the function
 * should print the message "Debit amount exceeded account balance." Member function getBalance should return
 * the current balance.
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef EX_11_10_H
#define EX_11_10_H

class Account {

    public:

        /**
         * @brief Construct a new Account object
         * 
         */
        Account(double=0);

        /**
         * @brief Add money to the account
         * 
         */
        void credit(double);

        /**
         * @brief Withdraw money from the account
         * 
         */
        double debit(double);

        /**
         * @brief Get the Balance of the account
         * 
         * @return double 
         */
        double getBalance() const {
            return balance;
        }

    private:
        double balance;
};

#endif