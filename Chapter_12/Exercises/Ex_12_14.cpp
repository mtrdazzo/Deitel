/**
 * @file Ex_12_14.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Class method definitions for Pieceworker and HourlyWorker
 * @version 0.1
 * @date 2020-07-15
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <iomanip>
#include <sstream>
#include <stdexcept>
#include "Ex_12_14.h"

const int daysOfMonths[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

/**
 * @brief Construct a new Date::Date object
 * 
 * @param month 
 * @param day
 * @param year 
 */
Date::Date(int month, int day, int year) {
    setMonth(month);
    setYear(year);
    setDay(day);
}

/**
 * @brief Output to Date string e.g. August 29, 1992
 * 
 * @return std::string 
 */
std::string Date::toString() const {

    static const char *monthNames[] = {"", "January", "February", "March", "April", "May",
                                       "June", "July", "August", "September", "October",
                                       "November", "December"};

    std::ostringstream output;

    output << monthNames[month];
    output << " " << day << ", ";
    output << year;

    return output.str();
}

/**
 * @brief Is year a leap year
 * 
 * @return true 
 * @return false 
 */
bool Date::isLeapYear() const {
    return (year % 4 == 0  && year % 100 != 0) || (year % 400 == 0);
}

/**
 * @brief Set the Date day for Student
 * 
 * @param _day 
 */
void Date::setDay(int _day) {
    if (_day <= 0)
        throw std::invalid_argument("day must be a positive integer");
    else if (month == 2 && isLeapYear()) {
        if (_day > daysOfMonths[month] + 1) {
            throw std::invalid_argument("invalid day of month");
        }
    }
    else if (_day > daysOfMonths[month])
        throw std::invalid_argument("invalid day of month");
    day = _day;
};

/**
 * @brief Set the Date month for Student
 * 
 * @param _month 
 */
void Date::setMonth(int _month) {
    if (_month <= 0 || static_cast<unsigned int>(_month) >= sizeof(daysOfMonths))
        throw std::invalid_argument("invalid month");
    month = _month;
}

/**
 * @brief Set the Date year for Student
 * 
 * @param _year 
 */
void Date::setYear(int _year) {
    if (_year <= 0)
        throw std::invalid_argument("invalid year");
    year = _year;
}

/**
 * @brief Construct a new Employee:: Employee object
 * 
 * @param firstName 
 * @param lastName 
 * @param ssn 
 * @param month 
 * @param day 
 * @param year 
 */
Employee::Employee(const std::string &firstName, const std::string &lastName, const std::string &ssn, int month, int day, int year)
    : birthDate{month, day, year} {
        setFirstName(firstName);
        setLastName(lastName);
        setSocialSecurityNumber(ssn);
}

/**
 * @brief Set the first name
 * 
 * @param _firstName 
 */
void Employee::setFirstName(const std::string &_firstName) {
    if (_firstName.length() == 0)
        throw std::invalid_argument("invalid first name");
    firstName = _firstName;
}

/**
 * @brief Set the last name
 * 
 * @param _lastName 
 */
void Employee::setLastName(const std::string &_lastName) {
    if (_lastName.length() == 0)
        throw std::invalid_argument("invalid last name");
    lastName = _lastName;
}

/**
 * @brief Set the social security number
 * 
 * @param ssn 
 */
void Employee::setSocialSecurityNumber(const std::string &ssn) {
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
 * @brief Output the employee's information to a string
 * 
 * @return std::string 
 */
std::string Employee::toString() const {
    return getFirstName() + " " + getLastName() +
        "\nsocial security number: " + getSocialSecurityNumber();
}

/**
 * @brief Construct a new Salaried Employee:: Salaried Employee object
 * 
 * @param firstName 
 * @param lastName 
 * @param ssn 
 * @param month 
 * @param day 
 * @param year 
 * @param salary 
 */
SalariedEmployee::SalariedEmployee(const std::string &firstName, const std::string &lastName, const std::string &ssn,
    int month, int day, int year, double salary) 
    : Employee(firstName, lastName, ssn, month, day, year) {
    setWeeklySalary(salary);
}

/**
 * @brief Set the weekly salary
 * 
 * @param salary 
 */
void SalariedEmployee::setWeeklySalary(double salary) {
    if (salary <= 0.0)
        throw std::invalid_argument("invalid salary, must be greater than 0.0");
    weeklySalary = salary;
}

/**
 * @brief Output the salaried employee information to a string
 * 
 * @return std::string 
 */
std::string SalariedEmployee::toString() const {
    std::ostringstream output;

    output << std::fixed << std::setprecision(2);
    output << "salaried employee: ";
    output << Employee::toString();
    output << "\nweekly salary: " << getWeeklySalary();
    return output.str();
}

/**
 * @brief Get the weekly earnings
 * 
 * @return double 
 */
double SalariedEmployee::earnings() const {
    return getWeeklySalary();
}

/**
 * @brief Construct a new Commission Employee:: Commission Employee object
 * 
 * @param firstName 
 * @param lastName 
 * @param ssn 
 * @param month 
 * @param day 
 * @param year 
 * @param sales 
 * @param rate 
 */
CommissionEmployee::CommissionEmployee(const std::string &firstName, const std::string &lastName, const std::string &ssn,
    int month, int day, int year, double sales, double rate)
    : Employee(firstName, lastName, ssn, month, day, year) {
        setGrossSales(sales);
        setCommissionRate(rate);
}

/**
 * @brief Set the gross sales
 * 
 * @param sales 
 */
void CommissionEmployee::setGrossSales(double sales) {
    if (sales <= 0.0)
        throw std::invalid_argument("gross sales must be >= 0.0");
     grossSales = sales;
}

/**
 * @brief Set the gross sales
 * 
 * @param sales 
 */
void CommissionEmployee::setCommissionRate(double rate) {
    if (rate <= 0.0 || rate > 1.0)
        throw std::invalid_argument("invalid commission rate, must be > 0.0 and < 1.0");
     commissionRate = rate;
}

/**
 * @brief Return the earnings for the Commission Employee
 * 
 * @return double 
 */
double CommissionEmployee::earnings() const {
    return getGrossSales() * getCommissionRate();
}

/**
 * @brief Output the Commission Employee information to a string
 * 
 * @return std::string 
 */
std::string CommissionEmployee::toString() const {
    std::ostringstream output;

    output << std::fixed << std::setprecision(2);
    output << "commission employee: ";
    output << Employee::toString();
    output << "\ngross sales: " << getGrossSales();
    output << "\ncommission rate: " << getCommissionRate();
    
    return output.str();
}

/**
 * @brief Construct a new Base Plus Commission Employee:: Base Plus Commission Employee object
 * 
 * @param firstName 
 * @param lastName 
 * @param ssn 
 * @param month 
 * @param day 
 * @param year 
 * @param sales 
 * @param rate 
 * @param baseSalary 
 */
BasePlusCommissionEmployee::BasePlusCommissionEmployee(const std::string &firstName, const std::string &lastName, const std::string &ssn,
    int month, int day, int year, double sales, double rate, double baseSalary)
    : CommissionEmployee(firstName, lastName, ssn, month, day, year, sales, rate) {
        setBaseSalary(baseSalary);
}

/**
 * @brief Set the base salary
 * 
 * @param _baseSalary 
 */
void BasePlusCommissionEmployee::setBaseSalary(double _baseSalary) {
    if (_baseSalary <= 0.0)
        throw std::invalid_argument("invalid base salary");
     baseSalary = _baseSalary;
}

/**
 * @brief Calculate the earnings
 * 
 * @return double 
 */
double BasePlusCommissionEmployee::earnings() const {
    return getBaseSalary() + CommissionEmployee::earnings();
}

/**
 * @brief Output the base plus commission employee information to a string
 * 
 * @return std::string 
 */
std::string BasePlusCommissionEmployee::toString() const {
    std::ostringstream output;
    
    output << std::fixed << std::setprecision(2);
    output << "base-salaried " << CommissionEmployee::toString()
        << "\nbase salary: " << getBaseSalary();
    return output.str();
}

/**
 * @brief Construct a new Piece Worker:: Piece Worker object
 * 
 * @param firstName 
 * @param lastName 
 * @param ssn 
 * @param month 
 * @param day 
 * @param year 
 * @param wage 
 * @param pieces 
 */
PieceWorker::PieceWorker(const std::string & firstName, const std::string & lastName, const std::string & ssn,
                        int month, int day, int year, double wage, int pieces)
    : Employee(firstName, lastName, ssn, month, day, year) {
        setWage(wage);
        setPieces(pieces);
}

/**
 * @brief Set the wage of the piece worker
 * 
 * @param wage 
 */
void PieceWorker::setWage(double wage) {
    if (wage <= 0.0)
        throw std::invalid_argument("inavlid wage, must be >= 0.0");
    this->wage = wage;
}

/**
 * @brief Set the number of pieces for the piece worker
 * 
 * @param pieces 
 */
void PieceWorker::setPieces(int pieces) {
    if (pieces < 0)
        throw std::invalid_argument("invalid number of pieces");
    this->pieces = pieces;
}

/**
 * @brief Output the piece worker information to a string
 * 
 * @return std::string 
 */
std::string PieceWorker::toString() const {
    std::ostringstream output;
    
    output << std::fixed << std::setprecision(2);
    output << "piece-salaried: " << Employee::toString()
        << "piece wage: " << getWage()
        << "\nnumber of pieces: " << getPieces();
    return output.str();
}

/**
 * @brief Return the total earnings for the piece worker
 * 
 * @return double 
 */
double PieceWorker::earnings() const {
    return getWage() * getPieces();
}