/**
 * @file tst_Ex_11_10.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Test classes Account, CheckingAccount, and SavingsAccount
 * @version 0.1
 * @date 2020-07-09
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <gtest/gtest.h>
#include <Ex_11_10.h>

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