/**
 * @file Ex_22_18.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Search for substring
 * @version 0.1
 * @date 2020-12-31
 * 
 * Exercise 22-18 Searching for Substrings
 * 
 * Write a program based on Exercise 22.17 (it's identical, oops) that inputs a line of text
 * and a search string, then uses function subStr to determine the number of occurrences of
 * the string in the line of text. Print the result.
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <iostream>
#include <cstring>

/**
 * @brief Find and print the substring from a line of text
 * 
 * @return unsigned Number of times substring was found in the line of text
 */

/**
 * @brief Return the number of times the substring is found in line
 * 
 * @param line Line of text to be searched
 * @param substring Text to be searched for in the line of text
 * @return unsigned Number of times substring is found in the line
 */
unsigned findPrintSubstring(const char *line, const char *substring) {

    const char *linePtr{line};
    unsigned numSubstringFound{0};
    size_t substringLength{strlen(substring)};

    while ((linePtr = strstr(linePtr, substring)) != nullptr) {
        linePtr += substringLength;
        ++numSubstringFound;
    }
    return numSubstringFound;
}