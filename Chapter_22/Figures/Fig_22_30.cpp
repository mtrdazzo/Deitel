/**
 * @file Fig_22_30.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Using atol
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

    long l{atol("1000000")};

    cout << "The string \"1000000\" converted to long is " << l
        << "\nThe converted value divided by 2 is " << l / 2.0 << endl;

    return EXIT_SUCCESS;
}