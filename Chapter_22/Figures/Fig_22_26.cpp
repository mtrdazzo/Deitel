/**
 * @file Fig_22_26.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Demonstrating strlen
 * @version 0.1
 * @date 2020-12-28
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <iostream>
#include <cstring>

using namespace std;

int main(void) {

    const char* string1{"abcdefghijklmnopqrstuvwxyz"};
    const char* string2{"four"};
    const char* string3{"Boston"};

    cout << "The length of \"" << string1 << "\" is " << strlen(string1)
        << "\nThe length of \"" << string2 << "\" is " << strlen(string2)
        << "\nThe length of \"" << string3 << "\" is " << strlen(string3)
        << endl;

    return EXIT_SUCCESS;
}