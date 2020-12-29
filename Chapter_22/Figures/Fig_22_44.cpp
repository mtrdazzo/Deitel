/**
 * @file Fig_22_44.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Using memcmp
 * @version 0.1
 * @date 2020-12-28
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <iostream>
#include <iomanip>
#include <cstring> // memcmp prototype

using namespace std;

int main(void) {

    char s1[]{"ABCDEFG"};
    char s2[]{"ABCDXYZ"};

    cout << "s1 = " << s1 << "\ns2 = " << s2 << endl
        << "\nmemcmp(s1, s2, 4) = " << setw(3) << memcmp(s1, s2, 4)
        << "\nmemcmp(s1, s2, 7) = " << setw(3) << memcmp(s1, s2, 7)
        << "\nmemcmp(s2, s1, 7) = " << setw(3) << memcmp(s2, s1, 7)
        << endl;

    return EXIT_SUCCESS;
}