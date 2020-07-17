/**
 * @file Fig_12_1.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Aiming base-class and derived-class pointers at base-class and derived objects, respectively
 * @version 0.1
 * @date 2020-07-14
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <iostream>
#include <iomanip>
#include "CommissionEmployee.h"
#include "BasePlusCommissionEmployee.h"

/**
 * @brief Construct a new Commission Employee:: Commission Employee object
 * 
 * @param first first name of employee
 * @param last  last name of employee
 * @param ssn   social security number of employee
 * @param sales the gross sales amount
 * @param rate  the commission rate
 */
CommissionEmployee::CommissionEmployee(const std::string& first,
    const std::string&last, const std::string& ssn, double sales, double rate) {
        setFirstName(first);
        setLastName(last);
        setSocialSecurityNumber(ssn);
        setGrossSales(sales);
        setCommissionRate(rate);
}

/**
 * @brief Set the first name of the employee
 * 
 * @param first first name of employee
 */
void CommissionEmployee::setFirstName(const std::string& first) {
    if (!first.length())
        throw std::invalid_argument("empty first name");
    else if (first.length() > MAX_INPUT_LENGTH)
        firstName = first.substr(0, MAX_INPUT_LENGTH);
    else
        firstName = first;
}

/**
 * @brief Get the first name of the employee
 * 
 * @return std::string first name of the employee
 */
std::string CommissionEmployee::getFirstName() const {
    return firstName;
}

/**
 * @brief Set the last name of the employee
 * 
 * @param last last name of employee
 */
void CommissionEmployee::setLastName(const std::string& last) {
    if (!last.length())
        throw std::invalid_argument("empty last name");
    else if (last.length() > MAX_INPUT_LENGTH)
        lastName = last.substr(0, MAX_INPUT_LENGTH);
    else
        lastName = last;
}

/**
 * @brief Get the last name of the employee
 * 
 * @return std::string last name of the employee
 */
std::string CommissionEmployee::getLastName() const {
    return lastName;
}

/**
 * @brief Set the social security number of the employee
 * 
 * @param ssn 9 digit social security number
 */
void CommissionEmployee::setSocialSecurityNumber(const std::string &ssn) {
    if (ssn.length() != SSN_LENGTH) {
        throw std::invalid_argument("invalid ssn, must be nine digits");
    }
    else {
        for (size_t index{0}; index < SSN_LENGTH; ++index)
            if (!std::isdigit(ssn.at(index))) {
                throw std::invalid_argument("invalid ssn, must be nine digits");
            }
    }
    socialSecurityNumber = ssn;
}

/**
 * @brief Get the social security number of the employee
 * 
 * @return std::string 9-digit social secutity number
 */
std::string CommissionEmployee::getSocialSecurityNumber() const {
    return socialSecurityNumber;
}

/**
 * @brief Set the employee's commission rate
 * 
 * @param rate Employee commission rate (%)
 */
void CommissionEmployee::setCommissionRate(double rate) {
    if (rate <= 0.0 || rate >= 1.0)
        throw std::invalid_argument("commission rate must be > 0.0 and < 1.0");
    commissionRate = rate;
}

/**
 * @brief Get the employee's commission rate
 * 
 * @return double Employee commission rate (%)
 */
double CommissionEmployee::getCommissionRate() const {
    return commissionRate;
}

/**
 * @brief Set the gross sales in dollars
 * 
 * @param sales Gross sales in dollars
 */
void CommissionEmployee::setGrossSales(double sales) {
    if (sales < 0.0)
        throw std::invalid_argument("gross sales must be >= 0.0");
    grossSales = sales;
}

/**
 * @brief Get the gross sales of the employee
 * 
 * @return double Gross sales in dollars
 */
double CommissionEmployee::getGrossSales() const {
    return grossSales;
}

/**
 * @brief Output the employee information
 * 
 * @return std::string 
 */
std::string CommissionEmployee::toString() const {
    std::ostringstream output;
    output << std::fixed << std::setprecision(2);
    output << "commission employee: " << firstName << " " << lastName
        << "\nsocial security number: " << socialSecurityNumber
        << "\ngross sales: " << grossSales
        << "\ncommission rate: " << commissionRate;
    return output.str();
}

/**
 * @brief Total earnings of the employee
 * 
 * @return double earnings in dollars
 */
double CommissionEmployee::earnings() const {
    return grossSales * commissionRate;
}

/**
 * @brief Construct a new Commission Employee:: Commission Employee object
 * 
 * @param first first name of employee
 * @param last  last name of employee
 * @param ssn   social security number of employee
 * @param sales the gross sales amount
 * @param rate  the commission rate
 * @param base  the base salary of the employee
 */
BasePlusCommissionEmployee::BasePlusCommissionEmployee(const std::string& first,
    const std::string&last, const std::string& ssn, double sales, double rate, double base) 
        : CommissionEmployee(first, last, ssn, sales, rate) {
        setBaseSalary(base);
}

/**
 * @brief Output the employee information
 * 
 * @return std::string 
 */
std::string BasePlusCommissionEmployee::toString() const {
    std::ostringstream output;
    output << CommissionEmployee::toString()
        << "\nbase salary: " << baseSalary;
    return output.str();
}

/**
 * @brief Total earnings of the employee
 * 
 * @return double earnings in dollars
 */
double BasePlusCommissionEmployee::earnings() const {
    return baseSalary + CommissionEmployee::earnings();
}

/**
 * @brief Set the base salary of the employee
 * 
 * @param base Base salary in dollars
 */
void BasePlusCommissionEmployee::setBaseSalary(double base) {
    if (base <= 0.0)
        throw std::invalid_argument("base salary must be >= 0.0");
    baseSalary = base;
}

/**
 * @brief Get the base salary of the employee
 * 
 * @return double base salary in dollars
 */
double BasePlusCommissionEmployee::getBaseSalary() const {
    return baseSalary;
}

int main() {
    CommissionEmployee commissionEmployee{"Sue", "Jones", "222222222", 10000, .06};

    BasePlusCommissionEmployee basePlusCommissionEmployee{"Bob", "Lewis", "333333333", 5000, .04, 300};

    std::cout << std::fixed << std::setprecision(2) << "\n";

    std::cout << "DISPLAY BASE-CLASS AND DERIVED-CLASS OBJECTS:\n"
        << commissionEmployee.toString()
        << "\n\n"
        << basePlusCommissionEmployee.toString();

    /* natural: aim base-class pointer at base-class object */
    CommissionEmployee *commissionEmployeePtr{&commissionEmployee};
    std::cout << "\n\nCALLING TOSTRING WITH BASE-CLASS POINTER TO "
        << "\nBASE-CLASS OBJECT INVOKES BASE-CLASS TOSTRING FUNCTION:\n"
        << commissionEmployeePtr->toString();

    /* natural: aim derived-class pointer to derived-class object */
    BasePlusCommissionEmployee *basePlusCommissionEmployeePtr{&basePlusCommissionEmployee};
    std::cout << "\n\nCALLING TOSTRING WITH DERIVED-CLASS POINTER TO "
        << "\nDERIVED-CLASS OBJECT INVOKES DERIVED-CLASS TOSTRING FUNCTION:\n"
        << basePlusCommissionEmployeePtr->toString();
    
    /* aim base-class pointer to derived-class object */
    commissionEmployeePtr = &basePlusCommissionEmployee;

    /* natural: aim base-class pointer at base-class object */
    std::cout << "\n\nCALLING TOSTRING WITH BASE-CLASS POINTER TO "
        << "\nDERIVED-CLASS OBJECT\nINVOKES BASE-CLASS TOSTRING FUNCTION ON THAT DERIVED-CLASS OBJECT:\n"
        << commissionEmployeePtr->toString()
        << "\n" << std::endl;

    return EXIT_SUCCESS;
}