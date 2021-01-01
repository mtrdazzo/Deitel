/**
 * @file Ex_22_17.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Search for substring
 * @version 0.1
 * @date 2020-12-31
 * 
 * Exercise 22-17 Searching for Substrings
 * 
 * Write a program that inputs a line of text and a search string from the keyboard.
 * Using function strstr, locate the first occurrence of the search string in the
 * line of text, and assign the location to variable searchPtr of type char*. If the
 * search string is found, print the next occurrence of the search string. Then use
 * strstr again to locate the next occurrence of the search string in the line of
 * text. If a second occurrence is found, print the remainder of the line of text
 * beginning with the second occurrence.
 * 
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
unsigned findPrintSubstring(void) {
    char lineOfText[1024]{0};
    char substring[100]{0};
    char *linePtr{lineOfText};
    unsigned numSubstringFound{0};

    std::cin.getline(lineOfText, 1024);
    std::cin.getline(substring, 100);

    size_t substringLength{strlen(substring)};

    while ((linePtr = strstr(linePtr, substring)) != nullptr) {
        // for (size_t index{0}; index < substringLength; ++index)
            // std::cout << *(linePtr + index);
        linePtr += substringLength;
        ++numSubstringFound;
        // std::cout << '\n';
    }
    return numSubstringFound;
}