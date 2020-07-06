/**
 * @file Ex_11_3.h
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Composition version of ComissionEmployee and BasePlusComissionEmployee definitions
 * @version 0.1
 * @date 2020-07-06
 * 
 * Exercise 11-3 Composition as an Alternative to Inheritance
 * 
 * Many programs written with inheritance can be written with composition instead, and vice versa.
 * Rewrite class BasePlusCommissionEmployee of the ComissionEmployee-BasePlusComissionEmployee
 * hierarchy to use composition rather than inheritance. After you do this, asses the relative merits
 * of the two approaches for designing classes CommissionEmployee and BasePlusComissionEmployee, as
 * well as for object-oriented programs in general. Which approach is more natural? Why?
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef EX_11_3_H
#define EX_11_3_H

#include <string>

#define MAX_INPUT_LENGTH 10
#define SSN_LENGTH       9

class CommissionEmployee {

    public:

        /**
         * @brief Construct a new Commission Employee object
         * 
         */
        CommissionEmployee(const std::string&, const std::string&, 
        const std::string&, double = 0.0, double = 0.0);

        /**
         * @brief Set the First Name
         * 
         */
        void setFirstName(const std::string&);

        /**
         * @brief Get the First Name
         * 
         * @return std::string 
         */
        std::string getFirstName() const;

        /**
         * @brief Set the Last Name
         * 
         */
        void setLastName(const std::string&);

        /**
         * @brief Get the Last Name
         * 
         * @return std::string 
         */
        std::string getLastName() const;

        /**
         * @brief Set the Social Security Number
         * 
         */
        void setSocialSecurityNumber(const std::string&);

        /**
         * @brief Get the Social Security Number
         * 
         * @return std::string 
         */
        std::string getSocialSecurityNumber() const;

        /**
         * @brief Set the Gross Sales
         * 
         */
        void setGrossSales(double);

        /**
         * @brief Get the Gross Sales
         * 
         * @return double 
         */
        double getGrossSales() const;

        /**
         * @brief Set the Commission Rate
         * 
         */
        void setCommissionRate(double);

        /**
         * @brief Get the Commission Rate
         * 
         * @return double 
         */
        double getCommissionRate() const;

        /**
         * @brief Get the total earnings
         * 
         * @return double 
         */
        double earnings() const;


        /**
         * @brief Output the employee information to a string
         * 
         * @return std::string 
         */
        std::string toString() const;
    
    private:
        std::string firstName;
        std::string lastName;
        std::string socialSecurityNumber;
        double grossSales;
        double commissionRate;
};

class BasePlusCommissionEmployee {

    public:

        /**
         * @brief Construct a new Commission Employee object
         * 
         */
        BasePlusCommissionEmployee(const std::string&, const std::string&, 
        const std::string&, double = 0.0, double = 0.0, double = 0.0);

        /**
         * @brief Set the First Name
         * 
         */
        void setFirstName(const std::string&);

        /**
         * @brief Get the First Name
         * 
         * @return std::string 
         */
        std::string getFirstName() const;

        /**
         * @brief Set the Last Name
         * 
         */
        void setLastName(const std::string&);

        /**
         * @brief Get the Last Name
         * 
         * @return std::string 
         */
        std::string getLastName() const;

        /**
         * @brief Set the Social Security Number
         * 
         */
        void setSocialSecurityNumber(const std::string&);

        /**
         * @brief Get the Social Security Number
         * 
         * @return std::string 
         */
        std::string getSocialSecurityNumber() const;

        /**
         * @brief Set the Gross Sales
         * 
         */
        void setGrossSales(double);

        /**
         * @brief Get the Gross Sales
         * 
         * @return double 
         */
        double getGrossSales() const;

        /**
         * @brief Set the Commission Rate
         * 
         */
        void setCommissionRate(double);

        /**
         * @brief Get the Commission Rate
         * 
         * @return double 
         */
        double getCommissionRate() const;

        /**
         * @brief Set the Base Salary
         * 
         */
        void setBaseSalary(double);

        /**
         * @brief Get the Base Salary
         * 
         * @return double 
         */
        double getBaseSalary() const;

        /**
         * @brief Get the total earnings
         * 
         * @return double 
         */
        double earnings() const;

        /**
         * @brief Output the employee information to a string
         * 
         * @return std::string 
         */
        std::string toString() const;
    
    private:
        std::string firstName;
        std::string lastName;
        std::string socialSecurityNumber;
        double grossSales;
        double commissionRate;
        double baseSalary;
};

#endif
