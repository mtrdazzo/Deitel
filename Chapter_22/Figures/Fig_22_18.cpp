/**
 * @file Fig_22_18.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Character-handling functions isdigit, isalpha, isalnum and isxdigit
 * @version 0.1
 * @date 2020-12-28
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <iostream>
#include <cctype>

using namespace std;

int main() {

    cout << "According to isdigit:\n"
        << (isdigit('8') ? "8 is a" : "8 is not a") << " digit\n"
        << (isdigit('#') ? "# is a" : "# is not a") << " digit\n";

    cout << "\nAccording to isalpha:\n"
        << (isalpha('A') ? "A is a" : "A is not a") << " letter\n"
        << (isalpha('b') ? "b is a" : "b is not a") << " letter\n"
        << (isalpha('&') ? "& is a" : "& is not a") << " letter\n"
        << (isalpha('4') ? "8 is a" : "8 is not a") << " letter\n";
    
    cout << "\nAccording to isalnum:\n"
        << (isalnum('A') ? "A is a" : "A is not a") << " digit or a letter\n"
        << (isalnum('8') ? "8 is a" : "8 is not a") << " digit or a letter\n"
        << (isalnum('#') ? "# is a" : "# is not a") << " digit or a letter\n";

    cout << "\nAccording to isxdigit:\n"
        << (isxdigit('F') ? "F is a" : "F is not a ") << " hexadecimal digit\n"
        << (isxdigit('J') ? "J is a" : "J is not a ") << " hexadecimal digit\n"
        << (isxdigit('7') ? "7 is a" : "7 is not a ") << " hexadecimal digit\n"
        << (isxdigit('$') ? "$ is a" : "$ is not a ") << " hexadecimal digit\n"
        << (isxdigit('f') ? "f is a" : "f is not a ") << " hexadecimal digit\n";

    return EXIT_SUCCESS;
}