/**
 * @file tst_Ex_12_13.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Test the Account class hierarchy with Polymorphism
 * @version 0.1
 * @date 2020-07-15
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <vector>
#include <typeinfo>
#include <gtest/gtest.h>
#include <Ex_12_13.h>

/**
 * @brief Test polymorphism in the Account class hierarchy
 * 
 */
TEST(AccountHierarchy, Polymorphism) {

    std::vector<Account*> accounts;
    const int numAccounts{10};
    const double checkingBalance{123.45};
    const double checkingInterest{3.4};
    const double savingsBalance{99.80};
    const double savingsFee{5.00};

    for (size_t num{0}; num < numAccounts; ++num) {
        if (num % 2) {
            accounts.push_back(new CheckingAccount{checkingBalance, checkingInterest});
        }
        else {
            accounts.push_back(new SavingsAccount{savingsBalance, savingsFee});
        }
    }

    const SavingsAccount expectedSavings{savingsBalance, savingsFee};
    const CheckingAccount expectedChecking{checkingBalance, checkingInterest};

    for ( auto & account : accounts ) {
        SavingsAccount * savingsPtr = dynamic_cast<SavingsAccount*>(account);
        CheckingAccount * checkingPtr = dynamic_cast<CheckingAccount*>(account);
        if ( savingsPtr != nullptr) {
            EXPECT_EQ(savingsPtr->getBalance(), expectedSavings.getInterestRate());
            EXPECT_EQ(savingsPtr->getBalance(), expectedSavings.getBalance());
            savingsPtr->credit(savingsPtr->calculateInterest());
            EXPECT_NE(savingsPtr->getBalance(), expectedSavings.getBalance());
        }
        else if (checkingPtr != nullptr) {
            EXPECT_EQ(checkingPtr->getFee(), expectedChecking.getFee());
            EXPECT_EQ(checkingPtr->getBalance(), expectedChecking.getBalance());
            checkingPtr->debit(checkingPtr->getFee());
            EXPECT_NE(checkingPtr->getBalance(), expectedChecking.getBalance());
        }
    }

}

/**
 * @brief Test the Constructor of Account class
 * 
 */
TEST(AccountClass, Constructor) {

    /* invalid initial account balance */
    try {
        Account(-0.1);
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid balance");
    }

    double balance{0.1};
    Account example{balance};

    EXPECT_EQ(example.getBalance(), balance);
}

/**
 * @brief Test the credit and debit methods of the Account class
 * 
 */
TEST(AccountClass, CreditDebit) {

    double initial{5.0};
    Account example{initial};

    /* invalid credit amount */
    try {
        example.credit(0.0);
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid amount being credited");
    }

    try {
        example.credit(-0.1);
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid amount being credited");
    }

    /* valid credit amount */
    double creditAmount{3.3};
    example.credit(creditAmount);
    EXPECT_EQ(example.getBalance(), initial + creditAmount);

    /* invalid debit amount */
    try {
        example.debit(0.0);
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid debit amount");
    }

    try {
        example.debit(-0.1);
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid debit amount");
    }

    try {
        example.debit(example.getBalance() + 0.1);
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "Debit amount exceeded account balance");
    }

    /* valid debit amount */
    double creditAmount2{3.3};
    example.debit(creditAmount2);
    EXPECT_EQ(example.getBalance(), initial + creditAmount - creditAmount2);
}

/**
 * @brief Test the Constructor of SavingsAccount class
 * 
 */
TEST(SavingsAccountClass, Constructor) {

    /* invalid initial account balance */
    try {
        SavingsAccount(-0.1, 5.5);
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid balance");
    }

    /* invalid initial interest rate */
    try {
        SavingsAccount(0.0, -5.5);
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid interest rate");
    }

    double intialBalance{0.0};
    double interestRate{1.0};
    SavingsAccount example{intialBalance, interestRate};
    EXPECT_EQ(example.getBalance(), intialBalance);
    EXPECT_EQ(example.getInterestRate(), interestRate);
}

/**
 * @brief Test the credit and debit methods of the SavingsAccount class
 * 
 */
TEST(SavingsAccountClass, CreditDebit) {

    double initialBalance{5.0};
    double initialInterestRate{2.5};
    SavingsAccount example{initialBalance, initialInterestRate};

    EXPECT_EQ(example.calculateInterest(), 5.0 * (1 + 2.5/100.0));

    /* invalid interest rate */
    try {
        example.setInterestRate(0.0);
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid interest rate");
    }

    try {
        example.setInterestRate(-0.1);
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid interest rate");
    }

    /* invalid credit amount */
    try {
        example.credit(0.0);
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid amount being credited");
    }

    try {
        example.credit(-0.1);
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid amount being credited");
    }

    /* valid credit amount */
    double creditAmount{3.3};
    example.credit(creditAmount);
    EXPECT_EQ(example.getBalance(), initialBalance + creditAmount);

    /* invalid debit amount */
    try {
        example.debit(0.0);
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid debit amount");
    }

    try {
        example.debit(-0.1);
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid debit amount");
    }

    try {
        example.debit(example.getBalance() + 0.1);
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "Debit amount exceeded account balance");
    }

    /* valid debit amount */
    double creditAmount2{3.3};
    example.debit(creditAmount2);
    EXPECT_EQ(example.getBalance(), initialBalance + creditAmount - creditAmount2);
}

/**
 * @brief Test the Constructor of CheckingAccount class
 * 
 */
TEST(CheckingAccountClass, Constructor) {

    /* invalid initial account balance */
    try {
        CheckingAccount(-0.1, 5.5);
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid balance");
    }

    /* invalid initial fee */
    try {
        CheckingAccount(0.0, -0.1);
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid fee");
    }

    double intialBalance{0.0};
    double fee{0.0};
    CheckingAccount example{intialBalance, fee};
    EXPECT_EQ(example.getBalance(), intialBalance);
    EXPECT_EQ(example.getFee(), fee);
}

/**
 * @brief Test the credit and debit methods of the CheckingAccount class
 * 
 */
TEST(CheckingAccountClass, CreditDebit) {

    double initialBalance{5.0};
    double initialFee{2.5};
    CheckingAccount example{initialBalance, initialFee};

    /* invalid fee */
    try {
        example.setFee(-0.1);
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid fee");
    }

    /* invalid credit amount */
    try {
        example.credit(0.0);
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid amount being credited");
    }

    try {
        example.credit(-0.1);
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid amount being credited");
    }

    /* valid credit amount */
    double creditAmount{3.3};
    example.credit(creditAmount);
    EXPECT_EQ(example.getBalance(), initialBalance + creditAmount);

    /* invalid debit amount */
    try {
        example.debit(0.0);
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid debit amount");
    }

    try {
        example.debit(-0.1);
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid debit amount");
    }

    try {
        example.debit(example.getBalance() + 0.1);
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "Debit amount exceeded account balance");
    }

    /* valid debit amount */
    double creditAmount2{3.3};
    example.debit(creditAmount2);
    EXPECT_EQ(example.getBalance(), initialBalance + creditAmount - creditAmount2 - initialFee);
}
