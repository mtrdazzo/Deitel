/**
 * @file Fig_13_4.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Inputting characters using cin member function getline
 * @version 0.1
 * @date 2020-07-19
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <iostream>

int main() {

    const int SIZE{80};
    char buffer[SIZE];

    // input characters in buffer via cin function getline
    std::cout << "Enter a sentence:\n";
    std::cin.getline(buffer, SIZE);

    // display buffer contents
    std::cout << "\nThe sentence entered is:\n" << buffer << std::endl;

    return EXIT_SUCCESS;
}