/**
 * @file Ex_11_10.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Class method definitions for Account, CheckingAccount, SavingsAccount
 * @version 0.1
 * @date 2020-07-09
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <stdexcept>
#include "Ex_11_10.h"
#include <iostream>

/**
 * @brief Construct a new Account:: Account object
 * 
 * @param _balance 
 */
Account::Account(double _balance) {
    if (_balance < 0.0)
        throw std::invalid_argument("invalid balance");
    balance = _balance;
}

/**
 * @brief Withdraw amount from account
 * 
 * @param debit 
 */
double Account::debit(double amount) {
    if (amount <= 0.0) {
        throw std::invalid_argument("invalid debit amount");
    }
    else if (amount > balance) {
        throw std::invalid_argument("Debit amount exceeded account balance");
    }
    else {
        balance -= amount;
        return amount;
    }
}

/**
 * @brief Add money to the account
 * 
 */
void Account::credit(double credit) {
    if (credit <= 0.0)
        throw std::invalid_argument("invalid amount being credited");
    balance += credit;
}

/**
 * @brief Construct a new Savings Account:: Savings Account object
 * 
 * @param balance 
 * @param interestRate 
 */
SavingsAccount::SavingsAccount(double balance, double interestRate) :
    Account(balance) {
        setInterestRate(interestRate);
}

/**
 * @brief Set the interest rate
 * 
 * @param _interestRate 
 */
void SavingsAccount::setInterestRate(double _interestRate) {
    if (_interestRate <= 0.0)
        throw std::invalid_argument("invalid interest rate");
    interestRate = _interestRate;
}

/**
 * @brief Construct a new Checking Account:: Checking Account object
 * 
 * @param balance 
 * @param fee 
 */
CheckingAccount::CheckingAccount(double balance, double fee) :
    Account::Account(balance) {
        setFee(fee);
}

/**
 * @brief Debit amount and fee from account
 * 
 * @param amount 
 * @return double 
 */
double CheckingAccount::debit(double amount) {
    if (amount <= 0)
        throw std::invalid_argument("invalid debit amount");
    return Account::debit(amount + fee);
}

/**
 * @brief Set the fee for the account
 * 
 * @param _fee 
 */
void CheckingAccount::setFee(double _fee) {
    if (_fee < 0)
        throw std::invalid_argument("invalid fee");
    fee = _fee;
}