/**
 * @file Ex_11_3.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief CommissionEmployee and BasePlusComissionEmployee class-method definitions
 * @version 0.1
 * @date 2020-07-06
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <iomanip>
#include <stdexcept>
#include <sstream>
#include "Ex_11_3.h"

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
    return grossSales * (commissionRate / 100);
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
    const std::string&last, const std::string& ssn, double sales, double rate, double base) {
        setFirstName(first);
        setLastName(last);
        setSocialSecurityNumber(ssn);
        setGrossSales(sales);
        setCommissionRate(rate);
        setBaseSalary(base);
}

/**
 * @brief Set the first name of the employee
 * 
 * @param first first name of employee
 */
void BasePlusCommissionEmployee::setFirstName(const std::string& first) {
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
std::string BasePlusCommissionEmployee::getFirstName() const {
    return firstName;
}

/**
 * @brief Set the last name of the employee
 * 
 * @param last last name of employee
 */
void BasePlusCommissionEmployee::setLastName(const std::string& last) {
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
std::string BasePlusCommissionEmployee::getLastName() const {
    return lastName;
}

/**
 * @brief Set the social security number of the employee
 * 
 * @param ssn 9 digit social security number
 */
void BasePlusCommissionEmployee::setSocialSecurityNumber(const std::string &ssn) {
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
std::string BasePlusCommissionEmployee::getSocialSecurityNumber() const {
    return socialSecurityNumber;
}

/**
 * @brief Set the employee's commission rate
 * 
 * @param rate Employee commission rate (%)
 */
void BasePlusCommissionEmployee::setCommissionRate(double rate) {
    if (rate <= 0.0 || rate >= 1.0)
        throw std::invalid_argument("commission rate must be > 0.0 and < 1.0");
    commissionRate = rate;
}

/**
 * @brief Get the employee's commission rate
 * 
 * @return double Employee commission rate (%)
 */
double BasePlusCommissionEmployee::getCommissionRate() const {
    return commissionRate;
}

/**
 * @brief Set the gross sales in dollars
 * 
 * @param sales Gross sales in dollars
 */
void BasePlusCommissionEmployee::setGrossSales(double sales) {
    if (sales < 0.0)
        throw std::invalid_argument("gross sales must be >= 0.0");
    grossSales = sales;
}

/**
 * @brief Get the gross sales of the employee
 * 
 * @return double Gross sales in dollars
 */
double BasePlusCommissionEmployee::getGrossSales() const {
    return grossSales;
}

/**
 * @brief Output the employee information
 * 
 * @return std::string 
 */
std::string BasePlusCommissionEmployee::toString() const {
    std::ostringstream output;
    output << std::fixed << std::setprecision(2);
    output << "commission employee: " << firstName << " " << lastName
        << "\nsocial security number: " << socialSecurityNumber
        << "\ngross sales: " << grossSales
        << "\ncommission rate: " << commissionRate
        << "\nbase salary: " << baseSalary;
    return output.str();
}

/**
 * @brief Total earnings of the employee
 * 
 * @return double earnings in dollars
 */
double BasePlusCommissionEmployee::earnings() const {
    return baseSalary + grossSales * (commissionRate / 100);
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