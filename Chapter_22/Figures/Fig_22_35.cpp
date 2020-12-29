/**
 * @file Fig_22_35.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Using strchr
 * @version 0.1
 * @date 2020-12-28
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <iostream>
#include <cstring> // prototype for strchr

using namespace std;

int main(void) {

    const char* string1{"This is a test"};
    char character1{'a'};
    char character2{'z'};

    // search for character1 in string1
    cout << '\'' << character1 << "' was " 
        << (strchr(string1, character1) != NULL ? "found in " : "not found in ")
        << "\"" << string1 << "\".\n";

    // search for character2 in string1
    cout << '\'' << character2 << "' was " 
        << (strchr(string1, character2) != NULL ? "found in " : "not found in ")
        << "\"" << string1 << "\".\n";

    cout << endl;

    return EXIT_SUCCESS;
}