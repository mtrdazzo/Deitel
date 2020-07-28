/**
 * @file Fig_13_18.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Stream manipulators boolalpha and nonboolalpha
 * @version 0.1
 * @date 2020-07-20
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <iostream>

int main() {

    bool booleanValue{true};

    // display default true boolean value
    std::cout << "booleanValue is " << booleanValue;

    // display booleanValue after using boolAlpha
    std::cout << "\nbooleanValue (after using boolalpha) is "
        << std::boolalpha << booleanValue;

    std::cout << "\n\nswitch booleanValue and use noboolalpha\n";
    booleanValue = false;
    std::cout << std::noboolalpha;

    // display default false booleanValue after using noboolAlpha
    std::cout << "\nbooleanValue is " << booleanValue;

    // display booleanValue after using boolalpha again
    std::cout << "\nbooleanalpha (after using boolalpha) is "
        << std::boolalpha << booleanValue << std::endl;

    return EXIT_SUCCESS;
}