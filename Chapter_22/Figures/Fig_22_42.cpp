/**
 * @file Fig_22_42.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Using memcpy.
 * @version 0.1
 * @date 2020-12-28
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <iostream>
#include <cstring> // memcpy prototype

using namespace std;

int main(void) {

    char s1[17]{};
    char s2[]{"Copy this string"};

    memcpy(s1, s2, 17); // copy 17 characters from s2 to s1

    cout << "After s2 is copied into s1 with memcpy, \n"
        << "s1 contains \"" << s1 << '\"' << endl;

    return EXIT_SUCCESS;
}