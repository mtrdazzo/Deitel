/**
 * @file Fig_22_29.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Using atoi
 * @version 0.1
 * @date 2020-12-28
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <iostream>
#include <cstdlib> // prototype for atoi

using namespace std;

int main(void) {

    int i{atoi("2593")};

    cout << "The string \"2593\" converted to int is " << i
        << "\nThe converted value minus 593 is " << i - 593 << endl;

    return EXIT_SUCCESS;
}