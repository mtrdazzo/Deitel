/**
 * @file Fig_22_39.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Using strspn
 * @version 0.1
 * @date 2020-12-28
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <iostream>
#include <cstring> // prototype for strspn

using namespace std;

int main(void) {

    const char* string1{"The value is 3.14159"};
    const char* string2{"aehils Tuv"};

    cout << "string1 = " << string1 << "\nstring2 = " << string2
        << "\n\nThe length of the initial segments of string1\n"
        << "containing only characters from string2 = "
        << strspn(string1, string2) << endl;

    return EXIT_SUCCESS;
}