/**
 * @file Fig_22_43.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Using memmove
 * @version 0.1
 * @date 2020-12-28
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <iostream>
#include <cstring> // memmove prototype

using namespace std;

int main(void) {

    char x[]{"Home Sweet Home"};
    cout << "The string in array x before memmove is: " << x
        << "\nThe string in array x after memmove is: "
        << static_cast<char*>(memmove(x, &x[5], 10)) << endl; // can be used on the same object, unlike memcpy

    return EXIT_SUCCESS;
}