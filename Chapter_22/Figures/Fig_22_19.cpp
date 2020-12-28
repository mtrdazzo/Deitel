/**
 * @file Fig_22_19.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Demonstrating character-handling functions islower, isupper, tolower, toupper.
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

    cout << "According to islower:\n"
        << (islower('p') ? "p is a" : "p is not a") << " lowercase letter\n"
        << (islower('P') ? "P is a" : "P is not a") << " lowercase letter\n"
        << (islower('5') ? "5 is a" : "5 is not a") << " lowercase letter\n"
        << (islower('!') ? "! is a" : "! is not a") << " lowercase letter\n";
    
    cout << "\nAccording to isupper:\n"
        << (isupper('D') ? "D is an" : "D is not an") << " uppercase letter\n"
        << (isupper('d') ? "d is an" : "d is not an") << " uppercase letter\n"
        << (isupper('8') ? "8 is an" : "8 is not an") << " uppercase letter\n"
        << (isupper('$') ? "$ is an" : "$ is not an") << " uppercase letter\n";
    
    cout << "\nu converted to uppercase is " << static_cast<char>(toupper('u'))
        << "\n7 converted to uppercase is " << static_cast<char>(toupper('7'))
        << "\n$ converted to uppercase is " << static_cast<char>(toupper('$'))
        << "\nL converted to uppercase is " << static_cast<char>(toupper('L'));
    cout << endl;

    return EXIT_SUCCESS;
}