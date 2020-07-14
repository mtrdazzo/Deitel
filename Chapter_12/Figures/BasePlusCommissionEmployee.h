/**
 * @file BasePlusCommissionEmployee.h
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief BasePlusCommissionEmployee class definition
 * @version 0.1
 * @date 2020-07-14
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef BASEPLUS_H
#define BASEPLUS_H

#include <string>
#include "CommissionEmployee.h"

class BasePlusCommissionEmployee : public CommissionEmployee {

    public:

        /**
         * @brief Construct a new Commission Employee object
         * 
         */
        BasePlusCommissionEmployee(const std::string&, const std::string&, 
        const std::string&, double = 0.0, double = 0.0, double = 0.0);

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
        double baseSalary;
};

#endif