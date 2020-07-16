/**
 * @file Ex_12_13.h
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Polymorphic banking class hierarchy
 * @version 0.1
 * @date 2020-07-15
 * 
 * Exercise 12-13 Polymorphic Banking Program Using Account Hierarchy
 * 
 * Develop a polymorphic banking program using the Account hierarchy created in Exercise 11.10. Create a vector of
 * Account pointers to SavingsAccount and CheckingAccount objects. For each Account in the vector, allow the user
 * to specify an amount of money to withdraw from the Account using member function debit and an amount of money
 * to deposit into the Account using member function credit. As you process each Account, determine its type. If
 * an Account is a SavingsAccount, calculate the amount of interest owed to the Account using member function
 * calculateInterest, then add the interest to the account balance using member function credit. After processing
 * an Account, print the updated account balance obtained by invoking base-class member function getBalance.
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef EX_12_13_H
#define EX_12_13_H

class Account {

    public:

        /**
         * @brief Construct a new Account object
         * 
         */
        Account(double=0);

        /**
         * @brief Destroy the Account object
         * 
         */
        virtual ~Account() = default;

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
        virtual double getBalance() const {
            return balance;
        }

    private:
        double balance;
};

class SavingsAccount : public Account {

    public:

        /**
         * @brief Construct a new Savings Account object
         * 
         */
        SavingsAccount(double, double);

        /**
         * @brief Destroy the Savings Account object
         * 
         */
        virtual ~SavingsAccount() = default;

        /**
         * @brief Set the Interest Rate
         * 
         */
        void setInterestRate(double);

        /**
         * @brief Get the Interest Rate
         * 
         * @return double 
         */
        double getInterestRate() const {
            return interestRate;
        }

        /**
         * @brief Calculate the interest
         * 
         * @return double 
         */
        double calculateInterest() const {
            return getBalance() * (1 + interestRate / 100.0);
        }

        /**
         * @brief Get the Balance object
         * 
         * @return double 
         */
        virtual double getBalance() const override {
            return calculateInterest();
        }

    private:
        double interestRate; /* interest rate in percent */

};

class CheckingAccount : public Account {

    public:

        /**
         * @brief Construct a new Checking Account object
         * 
         */
        CheckingAccount(double, double);

        /**
         * @brief Destroy the Checking Account object
         * 
         */
        virtual ~CheckingAccount() = default;

        /**
         * @brief Debit money from the account
         * 
         * @return double 
         */
        double debit(double);

        /**
         * @brief Set the Fee object
         * 
         */
        void setFee(double);

        /**
         * @brief Get the Fee object
         * 
         * @return double 
         */
        double getFee() const {
            return fee;
        }

        /**
         * @brief Get the Balance object
         * 
         * @return double 
         */
        virtual double getBalance() const override {
            return Account::getBalance() - getFee();
        }

    private:
        double fee;

};

#endif /* EX_12_13_H */