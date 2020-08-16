/**
 * @file Fig_13_3.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Contrasting input of a string via cin and cin.get.
 * @version 0.1
 * @date 2020-07-19
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <iostream>

int main() {

    const int SIZE{80};
    char buffer1[SIZE];
    char buffer2[SIZE];

    /* use cin to input characters into buffer1 */
    std::cout << "Enter a sequence:\n";
    std::cin >> buffer1;

    // display buffer1 contents
    std::cout << "\nThe string read with cin was:\n" << buffer1 << "\n\n";

    std::cin.get(buffer2, SIZE);

    // display buffer2 contents
    std::cout << "The string read with cin.get was:\n" << buffer2 << std::endl;

    return EXIT_SUCCESS;
}