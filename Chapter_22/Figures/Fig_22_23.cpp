/**
 * @file Fig_22_23.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Using strcat and strncat
 * @version 0.1
 * @date 2020-12-28
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <iostream>
#include <cstring>

int main(void) {

    char s1[20]{"Happy "}; // length 6
    char s2[]{"New Year "}; // length 9
    char s3[40]{""}; // initialize because strcat appends after finding \0 character

    std::cout << "s1 = " << s1 << "\ns2 = " << s2;

    strcat(s1, s2); // concatenate s2 to s1

    std::cout << "\n\nAfter strcat(s1, s2):\ns1 = " << s1 << "\ns2 = " << s2;

    // concatenate first 6 characters of s1 to s3
    strncat(s3, s1, 6); // places '\0' after last character

    std::cout << "\n\nAfter strncat(s3, s1, 6):\ns1 = " << s1
        << "\ns3 = " << s3 << std::endl;

    strcat(s3, s1); // concatenate s1 to s3
    std::cout << "\n\nAfter strcat(s3, s1):\ns1 = " << s1
        << "\ns3 = " << s3 << std::endl;

    return EXIT_SUCCESS;
}