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

/**
 * @brief Test the Date class
 * 
 */
TEST(Date, SettersGetters) {

    /* invalid month */
    try{
        Date example{0, 22, 1989};
    }
    catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid month");
    }
    try{
        Date example{13, 22, 1989};
    }
    catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid month");
    }

    /* invalid day, 31 day month */
    try{
        Date example{1, 0, 1989};
    }
    catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "day must be a positive integer");
    }
    try{
        Date example{1, 32, 1989};
    }
    catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid day of month");
    }

    /* invalid day, 30 day month */
    try{
        Date example{4, 31, 1989};
    }
    catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid day of month");
    }

    /* invalid year */
    try{
        Date example{4, 30, 0};
    }
    catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid year");
    }

    /* invalid day non-leap year */
    try{
        Date example{2, 29, 2001};
    }
    catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid day of month");
    }

    /* invalid day leap year */
    try{
        Date example{2, 30, 200};
    }
    catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid day of month");
    }

    /* valid day 29th of leap year */
    Date example{2, 29, 2000};
    EXPECT_EQ(example.toString(), "February 29, 2000");
}

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

TEST(SalariedEmployee, Constructor) {

    /* Sunny Day scenario */
    SalariedEmployee ce{"Jon", "Doe", "123456789", 4, 8, 1989, 5000};

    /* empty first name */
    try {
        SalariedEmployee ce{"", "Doe", "123456789", 4, 8, 1989, 1.0};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid first name");
    }

    /* empty last name */
    try {
        SalariedEmployee ce{"Jon", "", "123456789", 4, 8, 1989, 1.0};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid last name");
    }

    /* invalid ssn */
    try {
        SalariedEmployee ce{"Jon", "Doe", "12345678", 4, 8, 1989, 1.0};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid ssn, must be nine digits");
    }

    try {
        SalariedEmployee ce{"Jon", "Doe", "1234567890", 4, 8, 1989, 1.0};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid ssn, must be nine digits");
    }

    try {
        SalariedEmployee ce{"Jon", "Doe", "12-456789", 4, 8, 1989, 1.0};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid ssn, must be nine digits");
    }

    /* Invalid salary */
    try {
        SalariedEmployee ce{"Jon", "Doe", "123456789", 4, 8, 1989, 0.0};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid salary, must be greater than 0.0");
    }

    try {
        SalariedEmployee ce{"Jon", "Doe", "123456789", 4, 8, 1989, -0.1};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid salary, must be greater than 0.0");
    }

    /* Invalid salary */
    try {
        SalariedEmployee ce{"Jon", "Doe", "123456789", 4, 8, 1989, 0.0};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid salary, must be greater than 0.0");
    }

    try {
        SalariedEmployee ce{"Jon", "Doe", "123456789", 4, 8, 1989, -1000};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid salary, must be greater than 0.0");
    }
}

TEST(SalariedEmployee, GettersSetters) {

    std::string firstName{"JonNameThatsTooLong"};

    SalariedEmployee ce{"Jon", "Doe", "123456789", 4, 8, 1989, 1000};
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
    EXPECT_EQ(ce.getWeeklySalary(), 1000);

    EXPECT_EQ(ce.earnings(), 1000);

    std::ostringstream outputExepected;
    outputExepected << std::fixed << std::setprecision(2);
    outputExepected << "salaried employee: " + ce.getFirstName() + " " + ce.getLastName() + '\n';
    outputExepected << "social security number: " << ce.getSocialSecurityNumber() << '\n';
    outputExepected << "weekly salary: " << ce.getWeeklySalary();

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

TEST(PieceWorker, Constructor) {

    /* Sunny Day scenario */
    PieceWorker ce{"Jon", "Doe", "123456789", 4, 8, 1989, 5000, 10};

    /* empty first name */
    try {
        PieceWorker ce{"", "Doe", "123456789", 4, 8, 1989, 1.0, 20};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid first name");
    }

    /* empty last name */
    try {
        PieceWorker ce{"Jon", "", "123456789", 4, 8, 1989, 1.0, 10};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid last name");
    }

    /* invalid ssn */
    try {
        PieceWorker ce{"Jon", "Doe", "12345678", 4, 8, 1989, 1.0, 10};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid ssn, must be nine digits");
    }

    try {
        PieceWorker ce{"Jon", "Doe", "1234567890", 4, 8, 1989, 1.0, 20};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid ssn, must be nine digits");
    }

    try {
        PieceWorker ce{"Jon", "Doe", "12-456789", 4, 8, 1989, 1.0, 25};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid ssn, must be nine digits");
    }

    /* Invalid piece rate */
    try {
        PieceWorker ce{"Jon", "Doe", "123456789", 4, 8, 1989, 0.0, 10};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid wage, must be > 0.0");
    }

    try {
        PieceWorker ce{"Jon", "Doe", "123456789", 4, 8, 1989, -0.1, 1000};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid wage, must be > 0.0");
    }

    /* Invalid pieces */
    try {
        PieceWorker ce{"Jon", "Doe", "123456789", 4, 8, 1989, 10.0, 0};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid number of pieces, must be >= 0");
    }

    try {
        PieceWorker ce{"Jon", "Doe", "123456789", 4, 8, 1989, 10.0, -1};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid number of pieces, must be >= 0");
    }
}

TEST(PieceWorker, GettersSetters) {

    const std::string firstName{"Matt"};
    PieceWorker example{"Jon", "Doe", "123456789", 4, 8, 1989, 98.0, 100};
    EXPECT_EQ(example.getFirstName(), "Jon");

    /* First Name too long */
    example.setFirstName(firstName);
    EXPECT_EQ(example.getFirstName(), firstName);

    /* Last Name too long */
    EXPECT_EQ(example.getLastName(), "Doe");
    example.setLastName(firstName);
    EXPECT_EQ(example.getLastName(), firstName);

    /* Getters */
    EXPECT_EQ(example.getSocialSecurityNumber(), "123456789");
    EXPECT_EQ(example.getPieces(), 100);
    EXPECT_EQ(example.getWage(), 98.0);
    EXPECT_EQ(example.earnings(), 98.0 * 100);

    std::ostringstream outputExepected;
    outputExepected << std::fixed << std::setprecision(2);
    outputExepected << "piece-salaried: " + example.getFirstName() + " " + example.getLastName() + '\n';
    outputExepected << "social security number: " << example.getSocialSecurityNumber() << '\n';
    outputExepected << "piece wage: " << example.getWage() << '\n';
    outputExepected << "number of pieces: " << example.getPieces();

    EXPECT_EQ(outputExepected.str(), example.toString());
}