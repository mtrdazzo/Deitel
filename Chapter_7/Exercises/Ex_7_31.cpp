/*
 * Exercise 7-31 Print a String Backwards
 *
 * Write a recursive function stringReverse that takes an string, and a starting
 * subscript as arguments, returns nothing and prints the array. The function
 * should stop processing and return when the end of the string is encountered. Note
 * that like an array the square brackets ([]) operator can be used to iterate
 * through the characters in a string.
 *
 */

#include <iostream>
#include "Ex_7_31.h"

/**
 * Recursively prints the elements of a string in reverse.
 *
 * @param str   Input string
 * @param index Starting subscript of the array
 * @return void
 */
void printString(std::string& str, const size_t index) {
    /* empty string */
    if (str.size() == 0)
        return;

    if (index < str.size() - 1)
        printString(str, index + 1);
    std::cout << str[index];
}