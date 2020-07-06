/**
 * @file tst_Ex_11_3.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Testing composition of CommissionEmployee and BasePlusCommissionEmployee classes
 * @version 0.1
 * @date 2020-07-06
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <gtest/gtest.h>
#include <Ex_11_3.h>

TEST(CommissionEmployee, Constructor) {

    /* Sunny Day scenario */
    CommissionEmployee ce{"Jon", "Doe", "123456789", 5000, 0.25};

    /* empty first name */
    try {
        CommissionEmployee ce{"", "Doe", "123456789", 1.0, 0.25};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "empty first name");
    }

    /* empty last name */
    try {
        CommissionEmployee ce{"Jon", "", "123456789", 1.0, 0.25};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "empty last name");
    }

    /* invalid ssn */
    try {
        CommissionEmployee ce{"Jon", "Doe", "12345678", 1.0, 0.25};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid ssn, must be nine digits");
    }

    try {
        CommissionEmployee ce{"Jon", "Doe", "1234567890", 1.0, 0.25};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid ssn, must be nine digits");
    }

    try {
        CommissionEmployee ce{"Jon", "Doe", "12-456789", 1.0, 0.25};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid ssn, must be nine digits");
    }

    /* Invalid gross sales */
    try {
        CommissionEmployee ce{"Jon", "Doe", "123456789", 0.0, 0.25};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "gross sales must be >= 0.0");
    }

    try {
        CommissionEmployee ce{"Jon", "Doe", "123456789", -0.1, 0.25};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "gross sales must be >= 0.0");
    }

}