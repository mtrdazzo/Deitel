/**
 * @file tst_Ex_12_14.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Testing composition of Employee class hierarchy
 * @version 0.1
 * @date 2020-07-15
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <gtest/gtest.h>
#include <Ex_12_14.h>

TEST(CommissionEmployee, Constructor) {

    /* Sunny Day scenario */
    CommissionEmployee ce{"Jon", "Doe", "123456789", 4, 8, 1989, 5000, 0.25};

    /* empty first name */
    try {
        CommissionEmployee ce{"", "Doe", "123456789", 4, 8, 1989, 1.0, 0.25};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid first name");
    }

    /* empty last name */
    try {
        CommissionEmployee ce{"Jon", "", "123456789", 4, 8, 1989, 1.0, 0.25};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid last name");
    }

    /* invalid ssn */
    try {
        CommissionEmployee ce{"Jon", "Doe", "12345678", 4, 8, 1989, 1.0, 0.25};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid ssn, must be nine digits");
    }

    try {
        CommissionEmployee ce{"Jon", "Doe", "1234567890", 4, 8, 1989, 1.0, 0.25};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid ssn, must be nine digits");
    }

    try {
        CommissionEmployee ce{"Jon", "Doe", "12-456789", 4, 8, 1989, 1.0, 0.25};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid ssn, must be nine digits");
    }

    /* Invalid gross sales */
    try {
        CommissionEmployee ce{"Jon", "Doe", "123456789", 4, 8, 1989, 0.0, 0.25};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "gross sales must be >= 0.0");
    }

    try {
        CommissionEmployee ce{"Jon", "Doe", "123456789", 4, 8, 1989, -0.1, 0.25};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "gross sales must be >= 0.0");
    }

    /* Invalid rate */
    try {
        CommissionEmployee ce{"Jon", "Doe", "123456789", 4, 8, 1989, 1000, 0.0};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid commission rate, must be > 0.0 and < 1.0");
    }

    try {
        CommissionEmployee ce{"Jon", "Doe", "123456789", 4, 8, 1989, 1000, 1.0};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "commission rate must be > 0.0 and < 1.0");
    }
}

TEST(CommissionEmployee, GettersSetters) {

    std::string firstName{"JonNameThatsTooLong"};

    CommissionEmployee ce{"Jon", "Doe", "123456789", 4, 8, 1989, 1000, 0.5};
    EXPECT_EQ(ce.getFirstName(), "Jon");

    /* First Name too long */
    ce.setFirstName(firstName);
    EXPECT_EQ(ce.getFirstName(), firstName);

    /* Last Name too long */
    EXPECT_EQ(ce.getLastName(), "Doe");
    ce.setLastName(firstName);
    EXPECT_EQ(ce.getLastName(), firstName);

    /* Getters */
    EXPECT_EQ(ce.getSocialSecurityNumber(), "123456789");
    EXPECT_EQ(ce.getGrossSales(), 1000);
    EXPECT_EQ(ce.getCommissionRate(), 0.5);

    EXPECT_EQ(ce.earnings(), 1000 * 0.5);

    std::ostringstream outputExepected;
    outputExepected << std::fixed << std::setprecision(2);
    outputExepected << "commission employee: " + ce.getFirstName() + " " + ce.getLastName() + '\n';
    outputExepected << "social security number: " << ce.getSocialSecurityNumber() << '\n';
    outputExepected << "gross sales: " << ce.getGrossSales() << '\n';
    outputExepected << "commission rate: " << ce.getCommissionRate();

    EXPECT_EQ(outputExepected.str(), ce.toString());
}

TEST(BasePlusCommissionEmployee, Constructor) {

    /* Sunny Day scenario */
    BasePlusCommissionEmployee ce{"Jon", "Doe", "123456789", 4, 8, 1989, 5000, 0.25, 1000};

    /* empty first name */
    try {
        BasePlusCommissionEmployee ce{"", "Doe", "123456789", 4, 8, 1989, 1.0, 0.25, 1000};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid first name");
    }

    /* empty last name */
    try {
        BasePlusCommissionEmployee ce{"Jon", "", "123456789", 4, 8, 1989, 1.0, 0.25, 1000};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid last name");
    }

    /* invalid ssn */
    try {
        BasePlusCommissionEmployee ce{"Jon", "Doe", "12345678", 4, 8, 1989, 1.0, 0.25, 1000};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid ssn, must be nine digits");
    }

    try {
        BasePlusCommissionEmployee ce{"Jon", "Doe", "1234567890", 4, 8, 1989, 1.0, 0.25, 1000};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid ssn, must be nine digits");
    }

    try {
        BasePlusCommissionEmployee ce{"Jon", "Doe", "12-456789", 4, 8, 1989, 1.0, 0.25, 1000};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid ssn, must be nine digits");
    }

    /* Invalid gross sales */
    try {
        BasePlusCommissionEmployee ce{"Jon", "Doe", "123456789", 4, 8, 1989, 0.0, 0.25, 1000};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "gross sales must be >= 0.0");
    }

    try {
        BasePlusCommissionEmployee ce{"Jon", "Doe", "123456789", 4, 8, 1989, -0.1, 0.25, 1000};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "gross sales must be >= 0.0");
    }

    /* Invalid rate */
    try {
        BasePlusCommissionEmployee ce{"Jon", "Doe", "123456789", 4, 8, 1989, 1000, 0.0, 1000};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid commission rate, must be > 0.0 and < 1.0");
    }

    try {
        BasePlusCommissionEmployee ce{"Jon", "Doe", "123456789", 4, 8, 1989, 1000, 1.0, 1000};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid commission rate, must be > 0.0 and < 1.0");
    }

    /* Invalid base pay */
    try {
        BasePlusCommissionEmployee ce{"Jon", "Doe", "123456789", 4, 8, 1989, 1000, 0.5, 0};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid base salary");
    }
}

TEST(BasePlusCommissionEmployee, GettersSetters) {

    std::string firstName{"JonNameThatsTooLong"};
    BasePlusCommissionEmployee ce{"Jon", "Doe", "123456789", 4, 8, 1989, 1000, 0.5, 1000};
    EXPECT_EQ(ce.getFirstName(), "Jon");

    /* First Name too long */
    ce.setFirstName(firstName);
    EXPECT_EQ(ce.getFirstName(), firstName);

    /* Last Name too long */
    EXPECT_EQ(ce.getLastName(), "Doe");
    ce.setLastName(firstName);
    EXPECT_EQ(ce.getLastName(), firstName);

    /* Getters */
    EXPECT_EQ(ce.getSocialSecurityNumber(), "123456789");
    EXPECT_EQ(ce.getGrossSales(), 1000);
    EXPECT_EQ(ce.getCommissionRate(), 0.5);
    EXPECT_EQ(ce.getBaseSalary(), 1000);
    EXPECT_EQ(ce.earnings(), 1000 * 0.5 + 1000);

    std::ostringstream outputExepected;
    outputExepected << std::fixed << std::setprecision(2);
    outputExepected << "base-salaried commission employee: " + ce.getFirstName() + " " + ce.getLastName() + '\n';
    outputExepected << "social security number: " << ce.getSocialSecurityNumber() << '\n';
    outputExepected << "gross sales: " << ce.getGrossSales() << '\n';
    outputExepected << "commission rate: " << ce.getCommissionRate() << '\n';
    outputExepected << "base salary: " << ce.getBaseSalary();

    EXPECT_EQ(outputExepected.str(), ce.toString());
}