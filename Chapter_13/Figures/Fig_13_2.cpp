/**
 * @file Fig_13_2.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief get, put and eof member functions
 * @version 0.1
 * @date 2020-07-19
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <iostream>

int main() {

    int character; /* use int, because char cannot represent EOF */

    /* prompt user to enter line of text */
    std::cout << "Before input, cin.eof() is " << std::cin.eof()
        << "\nEnter a sequence followed by Enter and end-of-file:\n";
    
    while ((character = std::cin.get()) != EOF) {
        std::cout.put(character);
    }

    std::cout << "\nEOF in this system is: " << character
        << "\nAfter input of EOF, cin.eof() is " << std::cin.eof() << std::endl;

    return EXIT_SUCCESS;
}