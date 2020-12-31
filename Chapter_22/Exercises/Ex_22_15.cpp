/**
 * @file Ex_22_15.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Command-line arguments from strings to integers
 * @version 0.1
 * @date 2020-12-30
 * 
 * Exercise 22-15 Converting Strings to Integers
 * 
 * Write a program that inputs as command-line arguments four strings that represent
 * integers, converts the strings to integers, sums the values and prints the total
 * of the four values. Use only the C string-processing techniques discussed in this
 * chapter.
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <iostream>
#include <cstdint>
#include <cstring>

/**
 * @brief Convert command line integers to strings, and calculate the sum
 * 
 * @return int 
 */
int CommandLineArgsToInt(void) {

    const size_t bufferSize{100};
    char buffer[bufferSize]{0};
    char *bufferPtr;
    int sum{0};

    std::cin.getline(buffer, bufferSize);

    bufferPtr = strtok(buffer, " ");

    if (bufferPtr != nullptr) {
        sum += atoi(bufferPtr);

        while (bufferPtr != nullptr) {
            bufferPtr = strtok(nullptr, " ");
            if (bufferPtr != nullptr)
                sum += atoi(bufferPtr);
        }
    }

    return sum;
}