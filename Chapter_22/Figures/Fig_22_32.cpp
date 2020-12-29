/**
 * @file Fig_22_32.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Using strtol
 * @version 0.1
 * @date 2020-12-28
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <iostream>
#include <cstdlib> // prototype for strtol

using namespace std;

int main(void) {

    const char * string1{"-1234567abc"};
    char * remainderPtr{nullptr};

    long x{strtol(string1, &remainderPtr, 0)}; // convert to long

    cout << "The original string is \"" << string1
        << "\"\nThe converted value is " << x
        << "\nThe remainder of the original string is \"" << remainderPtr
        << "\"\nThe converted value plus 567 is " << x + 567 << endl;

    return EXIT_SUCCESS;
}