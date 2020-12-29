/**
 * @file Fig_22_36.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Usiing strcspn
 * @version 0.1
 * @date 2020-12-28
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <iostream>
#include <cstring> // prototype for strcspn

using namespace std;

int main(void) {

    const char* string1{"The value is 3.14159"};
    const char* string2{"1234567890"};

    cout << "string1 = " << string1 << "\nstring2 = " << string2
        << "\n\nThe length of the initial segment of string1"
        << "\ncontaining no characters from string2 = "
        << strcspn(string1, string2) << endl;

    return EXIT_SUCCESS;
}