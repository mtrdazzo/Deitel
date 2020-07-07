/**
 * @file Ex_11_6.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Inheritance heirarchy for students at a university class-method definitions
 * @version 0.1
 * @date 2020-07-07
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <sstream>
#include <cstdlib>
#include <ctime>
#include "Ex_11_6.h"

const int daysOfMonths[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

/**
 * @brief Construct a new DOB::DOB object
 * 
 * @param day 
 * @param month 
 * @param year 
 */
DOB::DOB(int day, int month, int year) {
    setMonth(month);
    setYear(year);
    setDay(day);
}

/**
 * @brief Output to DOB string e.g. August 29, 1992
 * 
 * @return std::string 
 */
std::string DOB::toString() const {

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
bool DOB::isLeapYear() const {
    return (year % 4 == 0  && year % 100 != 0) || (year % 400 == 0);
}

/**
 * @brief Set the DOB day for Student
 * 
 * @param _day 
 */
void DOB::setDay(int _day) {
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
 * @brief Set the DOB month for Student
 * 
 * @param _month 
 */
void DOB::setMonth(int _month) {
    if (_month <= 0 || static_cast<unsigned int>(_month) >= sizeof(daysOfMonths))
        throw std::invalid_argument("invalid month");
    month = _month;
}

/**
 * @brief Set the DOB year for Student
 * 
 * @param _year 
 */
void DOB::setYear(int _year) {
    if (_year <= 0)
        throw std::invalid_argument("invalid year");
    year = _year;
}

/**
 * @brief Construct a new Student:: Student object
 * 
 * @param firstName 
 * @param lastName 
 * @param day 
 * @param month 
 * @param year 
 */
Student::Student(std::string firstName, std::string lastName, int day, int month, int year) :
    dateOfBirth{day, month, year} {
    setFirstName(firstName);
    setLastName(lastName);
}

/**
 * @brief Set the first name of the student
 * 
 * @param _name 
 */
void Student::setFirstName(std::string _firstName) {
    if (_firstName.length() == 0)
        throw std::invalid_argument("invalid first name");
    firstName = _firstName;
}

/**
 * @brief Set the last name of the student
 * 
 * @param _lastName 
 */
void Student::setLastName(std::string _lastName) {
    if (_lastName.length() == 0)
        throw std::invalid_argument("invalid last name");
    lastName = _lastName;
}

/**
 * @brief Output the student information to a string
 * 
 * @return std::string 
 */
std::string Student::toString() const {
    std::ostringstream output;
    output << firstName + " " + lastName + '\n';
    output << dateOfBirth.toString();

    return output.str();
}

/**
 * @brief Construct a new Undergraduate Student:: Undergraduate Student object
 * 
 * @param firstName 
 * @param lastName 
 * @param day 
 * @param month 
 * @param year 
 */
UndergraduateStudent::UndergraduateStudent(std::string firstName, std::string lastName, int day, int month, int year) :
        Student(firstName, lastName, day, month, year) {
            _createID();
}

/**
 * @brief Create Undergraduate ID
 * 
 */
void UndergraduateStudent::_createID() {
    srand(static_cast<unsigned int>(time(0)));
    id = "U" + std::to_string(10000 + rand() / 10000);
}

/**
 * @brief Output the undergraduate student information to a string
 * 
 * @return std::string 
 */
std::string UndergraduateStudent::toString() const {
    std::ostringstream output;
    output << Student::toString();
    output << "\nUser ID: " + id;
    return output.str();
}