/**
 * @file CommissionEmployee2.h
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief CommissionEmployee class with virtual earnings and toString functions
 * @version 0.1
 * @date 2020-07-14
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef COMMISSION2_H
#define COMMISSION2_H

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
        virtual double earnings() const;


        /**
         * @brief Output the employee information to a string
         * 
         * @return std::string 
         */
        virtual std::string toString() const;
    
    private:
        std::string firstName;
        std::string lastName;
        std::string socialSecurityNumber;
        double grossSales;
        double commissionRate;
};

#endif
