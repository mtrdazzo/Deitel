/**
 * @file Ex_22_14.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Percentage digits and letters
 * @version 0.1
 * @date 2020-12-30
 * 
 * Exercise 21-14
 * 
 * Write a program that inputs a line of text using the cin member function getline into a
 * character array str[80] and outputs the percentage of digits and letters present in a string.
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <iostream>
#include <cstring>

#include "Ex_22_14.h"

/**
 * @brief Calculate the percentage of numbers and letters
 * 
 * @return Percentage 
 */
Percentage CalculatePercentages(void) {

    const size_t bufferLength{80};
    char str[bufferLength]{0};
    size_t length{0};
    Percentage results;

    std::cin.getline(str, bufferLength);
    length = strlen(str);

    for (size_t index{0}; str[index] != '\0'; ++index) {
        if (isdigit(str[index]))
            results.percentNum += 1.0;
        else if (isalpha(str[index]))
            results.percentAlpha += 1.0;
        else
            continue;
    }

    if (length) {
        results.percentNum *= (100.0 / length);
        results.percentAlpha *= (100.0 / length);
    }

    return results;
}