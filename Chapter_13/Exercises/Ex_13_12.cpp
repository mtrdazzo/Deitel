/**
 * @file Ex_13_12.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief decimal to octal and hexadecimal
 * @version 0.1
 * @date 2020-07-28
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "Ex_13_12.h"
#include <algorithm>

/**
 * @brief Convert decimal to octal string
 * 
 * @param decimal 32-bit integer
 * @return std::string Octal string representation
 */
std::string dec2octal(uint32_t decimal) {

    std::string octalString;

    while (decimal > 0)  {
        octalString += decimal % 8 + '0';

        decimal /= 8;
    }

    octalString += "0";

    std::reverse(octalString.begin(), octalString.end());

    return octalString;
}

/**
 * @brief Convert decimal to hexadecimal string
 * 
 * @param decimal 32-bit integer
 * @return std::string Hexadecimal string representation
 */
std::string dec2hex(uint32_t decimal) {

    std::string hexString;
    uint8_t remainder;

    while (decimal > 0)  {
        remainder = decimal % 16;
        hexString += remainder + ((remainder) >= 10 ? 'A' - 10 : '0');

        decimal /= 16;
    }

    for (size_t padding{0}; padding < hexString.length() - 8; ++padding)
        hexString += "0";

    hexString += "x0";

    std::reverse(hexString.begin(), hexString.end());

    return hexString;
}