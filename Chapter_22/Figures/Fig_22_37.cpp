/**
 * @file Fig_22_37.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Using strpbrk
 * @version 0.1
 * @date 2020-12-28
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <iostream>
#include <cstring> // prototype for strpbrk

using namespace std;

int main(void) {

    const char* string1{"This is a test"};
    const char* string2{"beware"};

    cout << "Of the characters in \"" << string2 << "\"\n'"
        << *strpbrk(string1, string2) << "\' is the first character "
        << "to appear in\n\"" << string1 << '\"' << endl;

    return EXIT_SUCCESS;
}