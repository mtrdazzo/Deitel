/**
 * @file Fig_13_19.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Flags member function
 * @version 0.1
 * @date 2020-07-20
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <iostream>

int main() {

    int integerValue{1000};
    double doubleValue{0.0947628};

    // display flags value, int and double values (original format)
    std::cout << "The value of the flags variable is: " << std::cout.flags()
        << "\nPrint int and double in original format:\n"
        << integerValue << '\t' << doubleValue;

    // use cout flags function to save original format
    std::ios_base::fmtflags originalFormat{std::cout.flags()};
    std::cout << std::showbase << std::oct << std::scientific; // change format

    // display flags value, int and double values (new format)
    std::cout << "\n\nThe value of the flags variable is: " << std::cout.flags()
        << "\nPrint int and double in new format:\n"
        << integerValue << '\t' << doubleValue;

    std::cout.flags(originalFormat); // restore format

    // display flags value, int and double values (original format)
    std::cout << "\n\nThe value of the flags variable is: " << std::cout.flags()
        << "\nPrint int and double in original format agin:\n"
        << integerValue << '\t' << doubleValue << std::endl;

    return EXIT_SUCCESS;
}