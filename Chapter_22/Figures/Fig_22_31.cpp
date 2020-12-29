/**
 * @file Fig_22_31.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Using strtod.
 * @version 0.1
 * @date 2020-12-28
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <iostream>
#include <cstdlib> // prototype for strtod

using namespace std;

int main(void) {

    const char * str1{"51.2% are admitted"};
    char * strPtr{nullptr};

    double d{strtod(str1, &strPtr)}; // convert to double

    cout << "The string \"" << str1
        << "\"  is converted to the\ndouble value " << d
        << " and the string \"" << strPtr << "\"" << endl;

    return EXIT_SUCCESS;
}