/**
 * @file Ex_13_13.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2020-08-01
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <iostream>
#include <limits>
#include "Ex_13_13.h"

/**
 * @brief Function does not account for extra input characters after first and last name.
 * 
 * @return std::string ${firstName} ${lastName} ${birthYear}
 */
std::string uncorrectedInput(void) {

    std::string firstName;
    std::string lastName;
    int birthYear;

    std::cin >> firstName;
    std::cin >> lastName;
    std::cin >> birthYear;

    return firstName + " " + lastName + " " + std::to_string(birthYear);
}

/**
 * @brief Function takes accounts for extra input characters after first and last name.
 * 
 * @return std::string ${firstName} ${lastName} ${birthYear}
 */
std::string correctedInput(void) {

    std::string firstName;
    std::string lastName;
    int birthYear;

    std::cin >> firstName >> lastName;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cin >> birthYear;
    std::cin.clear();

    return firstName + " " + lastName + " " + std::to_string(birthYear);
}
