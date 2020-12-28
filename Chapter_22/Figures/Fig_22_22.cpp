/**
 * @file Fig_22_22.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Demonstrating functionality of strcpy and strncpy.
 * @version 0.1
 * @date 2020-12-28
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <iostream>
#include <cstring> // prototypes for strcpy and strncpy

int main(void) {

    char x[]{"Happy Birthday to You"}; // string length 21
    char y[25];
    char z[15];

    strcpy(y, x); // copy contents of x into y

    std::cout << "The string in array x is: " << x
        << "\nThe string in array y is: " << y << '\n';
    
    strncpy(z, x, 14); // copy first 14 characters x into z
    z[14] = '\0'; // append terminating NULL character

    std::cout << "The string in array z is: " << z << std::endl;

    return EXIT_SUCCESS;
}