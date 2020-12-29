/**
 * @file Fig_22_28.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Using atof
 * @version 0.1
 * @date 2020-12-28
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <iostream>
#include <cstdlib> // prototype for atof

using namespace std;

int main(void) {

    double d{atof("99.0")};

    cout << "The string \"99.0\" converted to double is " << d
        << "\nThe converted value divided by 2 is " << d / 2.0 << endl;

    return EXIT_SUCCESS;
}