/**
 * @file Fig_13_6.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Using stream manipulators hex, oct, dec and setbase
 * @version 0.1
 * @date 2020-07-19
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <iostream>
#include <iomanip>

int main() {

    int number;

    std::cout << "Enter a decimal number: ";
    std::cin >> number; // input number

    // use hex stream manipulator to show hexadecimal number
    std::cout << number << " in hexadecimal is: " << std::hex << number << "\n";

    // use oct stream manipulator to show octal number
    std::cout << std::dec << " in octal is: " << std::oct << number << "\n";

    // use setbase stream manipulator to show decimal number
    std::cout << std::setbase(10) << number << " in decimal is: " << number << std::endl;

    return EXIT_SUCCESS;
}