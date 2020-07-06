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

    /* Invalid rate */
    try {
        CommissionEmployee ce{"Jon", "Doe", "123456789", 1000, 0.0};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "commission rate must be > 0.0 and < 1.0");
    }

    try {
        CommissionEmployee ce{"Jon", "Doe", "123456789", 1000, 1.0};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "commission rate must be > 0.0 and < 1.0");
    }
}

TEST(CommissionEmployee, GettersSetters) {

    /* First Name too long */
    std::string firstName{"JonNameThatsTooLong"};
    CommissionEmployee ce{"Jon", "Doe", "123456789", 1000, 0.5};
    EXPECT_EQ(ce.getFirstName(), "Jon");

    ce.setFirstName(firstName);
    EXPECT_EQ(ce.getFirstName(), firstName.substr(0, MAX_INPUT_LENGTH));

    EXPECT_EQ(ce.getLastName(), "Doe");
    ce.setLastName(firstName);
    EXPECT_EQ(ce.getLastName(), firstName.substr(0, MAX_INPUT_LENGTH));

    EXPECT_EQ(ce.getSocialSecurityNumber(), "123456789");
    EXPECT_EQ(ce.getGrossSales(), 1000);
    EXPECT_EQ(ce.getCommissionRate(), 0.5);
}

TEST(BasePlusCommissionEmployee, Constructor) {

    /* Sunny Day scenario */
    BasePlusCommissionEmployee ce{"Jon", "Doe", "123456789", 5000, 0.25, 1000};

    /* empty first name */
    try {
        BasePlusCommissionEmployee ce{"", "Doe", "123456789", 1.0, 0.25, 1000};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "empty first name");
    }

    /* empty last name */
    try {
        BasePlusCommissionEmployee ce{"Jon", "", "123456789", 1.0, 0.25, 1000};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "empty last name");
    }

    /* invalid ssn */
    try {
        BasePlusCommissionEmployee ce{"Jon", "Doe", "12345678", 1.0, 0.25, 1000};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid ssn, must be nine digits");
    }

    try {
        BasePlusCommissionEmployee ce{"Jon", "Doe", "1234567890", 1.0, 0.25, 1000};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid ssn, must be nine digits");
    }

    // try {
    //     BasePlusCommissionEmployee ce{"Jon", "Doe", "12-456789", 1.0, 0.25, 1000};
    // } catch (std::invalid_argument & err) {
    //     EXPECT_STREQ(err.what(), "invalid ssn, must be nine digits");
    // }

    /* Invalid gross sales */
    try {
        BasePlusCommissionEmployee ce{"Jon", "Doe", "123456789", 0.0, 0.25, 1000};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "gross sales must be >= 0.0");
    }

    try {
        BasePlusCommissionEmployee ce{"Jon", "Doe", "123456789", -0.1, 0.25, 1000};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "gross sales must be >= 0.0");
    }

    /* Invalid rate */
    try {
        BasePlusCommissionEmployee ce{"Jon", "Doe", "123456789", 1000, 0.0, 1000};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "commission rate must be > 0.0 and < 1.0");
    }

    try {
        BasePlusCommissionEmployee ce{"Jon", "Doe", "123456789", 1000, 1.0, 1000};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "commission rate must be > 0.0 and < 1.0");
    }

    /* Invalid base pay */
    try {
        BasePlusCommissionEmployee ce{"Jon", "Doe", "123456789", 1000, 0.5, 0};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "base salary must be >= 0.0");
    }
}

TEST(BasePlusCommissionEmployee, GettersSetters) {

    /* First Name too long */
    std::string firstName{"JonNameThatsTooLong"};
    BasePlusCommissionEmployee ce{"Jon", "Doe", "123456789", 1000, 0.5, 1000};
    EXPECT_EQ(ce.getFirstName(), "Jon");

    ce.setFirstName(firstName);
    EXPECT_EQ(ce.getFirstName(), firstName.substr(0, MAX_INPUT_LENGTH));

    EXPECT_EQ(ce.getLastName(), "Doe");
    ce.setLastName(firstName);
    EXPECT_EQ(ce.getLastName(), firstName.substr(0, MAX_INPUT_LENGTH));

    EXPECT_EQ(ce.getSocialSecurityNumber(), "123456789");
    EXPECT_EQ(ce.getGrossSales(), 1000);
    EXPECT_EQ(ce.getCommissionRate(), 0.5);
}