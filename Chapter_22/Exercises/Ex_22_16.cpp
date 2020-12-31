/**
 * @file Ex_22_16.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Converting Strings to Floating-Point Numbers
 * @version 0.1
 * @date 2020-12-30
 * 
 * Exercise 22-16 Converting Strings to Floating-Point Numbers
 * 
 * Write a program that inputs as command-line arguments four strings that represent
 * integers, converts the strings to floating-point numbers, sums the values and prints
 * the total of the four values. Use only the C string-processing techniques discussed
 * in this chapter.
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <iostream>
#include <cstdint>
#include <cstring>

/**
 * @brief Convert command line arguments to doubles and return the sum of the numbers
 * 
 * @return double Sum of command line arguments
 */
double CommandLineArgsToDouble(void) {

    double sum{0.0};
    const size_t bufferSize{1000};
    char buffer[bufferSize]{0};
    char *buffPtr;

    std::cin.getline(buffer, bufferSize);

    buffPtr = strtok(buffer, " ");

    if (buffPtr != nullptr) {
        do  {
            sum += atof(buffPtr);
            buffPtr = strtok(nullptr, " ");
        } while (buffPtr != nullptr);
    }

    return sum;
}