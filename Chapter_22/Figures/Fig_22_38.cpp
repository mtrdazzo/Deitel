/**
 * @file Fig_22_38.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Using strchr
 * @version 0.1
 * @date 2020-12-28
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <iostream>
#include <cstring> // prototype for strrchr

using namespace std;

int main(void) {

    const char* string1{"A zoo has many animals including zebras"};
    char c{'z'};

    cout << "string1 = " << string1 << "\n" << endl;
    cout << "The remainder of string1 beginning with the \n"
        << "last occurrence of character '"
        << c << "' is: \"" << strrchr(string1, c) << '\"' << endl;

    return EXIT_SUCCESS;
}