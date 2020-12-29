/**
 * @file Fig_22_46.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Using memset
 * @version 0.1
 * @date 2020-12-28
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <iostream>
#include <cstring> // memset prototype

using namespace std;

int main(void) {

    char string1[15]{"BBBBBBBBBBBBBB"};

    cout << "string1 = " << string1 << endl;
    cout << "string1 after memset = "
        << static_cast<char*>(memset(string1, 'b', 7)) << endl;

    return EXIT_SUCCESS;
}