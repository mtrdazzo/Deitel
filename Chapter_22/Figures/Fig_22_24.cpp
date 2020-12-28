/**
 * @file Fig_22_24.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Using strcmp and strncmp
 * @version 0.1
 * @date 2020-12-28
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

int main(void) {

    const char * s1{"Happy New Year"};
    const char * s2{"Happy New Year"};
    const char * s3{"Happy Holidays"};

    cout << "s1 = " << s1 << "\ns2 = " << s2 << "\ns3 = " << s3
        << "\n\nstrcmp(s1, s2)" << setw(2) << strcmp(s1, s2)
        << "\nstrcmp(s1, s3) = " << setw(2) << strcmp(s1, s3)
        << "\nstrncmp(s3, s1) = " << setw(2) << strcmp(s3, s1);
    
    cout << "\n\nstrncmp(s1, s3, 6) = " << setw(2) << strncmp(s1, s3, 6)
        << "\nstrncmp(s1, s3, 7) = " << setw(2) << strncmp(s1, s3, 7)
        << "\nstrncmp(s3, s1, 7) = " << setw(2) << strncmp(s3, s1, 7);

    cout << endl;

    return EXIT_SUCCESS;
}