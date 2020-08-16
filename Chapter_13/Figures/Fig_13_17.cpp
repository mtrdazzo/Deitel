/**
 * @file Fig_13_17.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Stream manipulator uppercase
 * @version 0.1
 * @date 2020-07-20
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <iostream>

int main() {

    std::cout << "Printing uppercase letters in scientific\n"
        << "notation and exponents and values:\n";
    
    std::cout << std::uppercase << 4.345e10 << "\n"
        << std::hex << std::showbase << 123456789 << std::endl;

    return EXIT_SUCCESS;
}