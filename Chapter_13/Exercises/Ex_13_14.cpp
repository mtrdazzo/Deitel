/**
 * @file Ex_13_14.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Class member function definitions for PhoneNumber class
 * @version 0.1
 * @date 2020-08-01
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <iostream>
#include <iomanip>
#include <stdexcept>
#include "Ex_13_14.h"

std::ostream& operator<<(std::ostream& output, const PhoneNumber& number) {
    output << "(" << number.areaCode << ") " << number.exchange << "-"
    << number.line << "\n";
    return output;
}



/**
 * @brief Input 14-character stream to phone number class
 * 
 * @param input Input stream
 * @param number PhoneNumber object
 * @return std::istream& Input stream for cascading calls
 */
std::istream& operator>>(std::istream& input, PhoneNumber& number) {

    static char inputStr[PHONENUMBER_LENGTH];

    input.get(inputStr, PHONENUMBER_LENGTH, '\n');

    for (size_t index{0}; index < PHONENUMBER_LENGTH; index++) {
        switch (index)
        {
        case 0:
            if (inputStr[index] != '(')
                throw std::invalid_argument("Missing '(', must enter phone number in the format: (###) ###-####");
            break;
        case 1:
        case 2:
        case 3:
            if (!std::isdigit(inputStr[index]))
                throw std::invalid_argument("Invalid symbol, must enter phone number in the format: (###) ###-####");
            if (index == 1) {
                if (inputStr[index] <= '1') {
                    throw std::invalid_argument("Invalid area code, cannot begin with 0 or 1");
                    input.clear();
                }
            }
            else if (index == 2) {
                if (inputStr[index] > '1') {
                    throw std::invalid_argument("Invalid area code, must be a 0 or 1");
                    input.clear();
                }
            }
            else
                number.areaCode = std::string(inputStr + 1, inputStr + 4);
            break;
        case 4:
            if (inputStr[index] != ')')
                throw std::invalid_argument("Missing ')', must enter phone number in the format: (###) ###-####");
            break;
        case 5:
            if (inputStr[index] != ' ')
                throw std::invalid_argument("Missing ' ', must enter phone number in the format: (###) ###-####");
            break;
        case 6:
        case 7:
        case 8:
            if (!std::isdigit(inputStr[index]))
                throw std::invalid_argument("Invalid symbol, must enter phone number in the format: (###) ###-####");
            if (index == 8)
                number.exchange = std::string(inputStr + 6, inputStr + 9);
            break;
        case 9:
            if (inputStr[index] != '-')
                throw std::invalid_argument("Missing '-', must enter phone number in the format: (###) ###-####");
            break;
        case 10:
        case 11:
        case 12:
        case 13:
            if (!std::isdigit(inputStr[index]))
                throw std::invalid_argument("Invalid symbol, must enter phone number in the format: (###) ###-####");
            if (index == 13)
                number.line = std::string(inputStr + 10, inputStr + 14);
            break;
        case 14:
            if (inputStr[index] != '\0')
                throw std::invalid_argument("Invalid phone number length, must enter phone number in the format: (###) ###-####");
            break;
        default:
            break;
        }
    }

    return input;
}