/**
 * @file Fig_22_45.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Using memchr
 * @version 0.1
 * @date 2020-12-28
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <iostream>
#include <cstring> // memchr prototype

using namespace std;

int main(void) {

    char s[]{"This is a string"};

    cout << "s = " << s << "\n" << endl;
    cout << "The remainder of s after character 'r' is found is \""
        << static_cast<char*>(memchr(s, 'r', 16)) << '\"' << endl;

    return EXIT_SUCCESS;
}