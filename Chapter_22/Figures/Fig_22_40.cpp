/**
 * @file Fig_22_40.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Using strstr
 * @version 0.1
 * @date 2020-12-28
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <iostream>
#include <cstring> // strstr prototype

using namespace std;

int main(void) {

    const char* string1{"abcdefabcdef"};
    const char* string2{"def"};

    cout << "string1 = " << string1 << "\nstring2 = " << string2
        << "\n\nThe remainder of string1 beginning with the \n"
        << "first occurrence of string2 is: "
        << strstr(string1, string2) << endl;

    return EXIT_SUCCESS;
}