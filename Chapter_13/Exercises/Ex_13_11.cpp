/**
 * @file Ex_13_11.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2020-07-28
 * 
 * Exercise 13-11 Length of a string
 * 
 * Write a program that inputs a string from the keyboard and determines the length of the
 * string. Print the string in a field width that is twice the length of the string.
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "Ex_13_11.h"

/**
 * @brief Input string from keyboard, print the string in a field twice that length.
 * 
 */
void printStringFromKeyboard() {

    char buffer[BUFFER_SIZE];

    std::cin.get(buffer, BUFFER_SIZE);

    std::cout.width(std::cin.gcount() * 2);
    std::cout << buffer << std::endl;
}