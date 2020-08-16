/**
 * @file Fig_13_5.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Unformatted I/O  using read, gcount and write
 * @version 0.1
 * @date 2020-07-19
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <iostream>

int main() {

    const int SIZE{80};
    char buffer[SIZE]; // create array of 80 characters

    // use function read to input characters into buffer
    std::cout << "Enter a sequence:\n";
    std::cin.get(buffer, 20);

    // use functions write and gcount to display buffer characters
    std::cout << "\nThe sentence entered was:\n";
    std::cout.write(buffer, std::cin.gcount());
    std::cout << std::endl;

    return EXIT_SUCCESS;
}