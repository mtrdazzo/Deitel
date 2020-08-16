/**
 * @file Fig_13_8.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief width member function of classes istream and ostream
 * @version 0.1
 * @date 2020-07-19
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <iostream>

int main() {

    int widthValue{4};
    char sentence[10];

    std::cout << "Enter a sequence:\n";
    std::cin.width(5); // input only 5 characters from sentence

    // set field width, then display characters based on that width
    while (std::cin >> sentence) {
        std::cout.width(widthValue++);
        std::cout << sentence << "\n";
        std::cin.width(5);
    }

    return EXIT_SUCCESS;
}