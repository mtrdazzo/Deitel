/**
 * @file Fig_22_6.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Printing an unsigned integer in bits.
 * @version 0.1
 * @date 2020-12-26
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <iostream>
#include <iomanip>

void displayBits(unsigned);

int main() {
    unsigned inputValue{0};

    std::cout << "Enter an unsigned integer: ";
    std::cin >> inputValue;
    displayBits(inputValue);
}

/**
 * @brief Display the bit representation of value
 * 
 * @param value Unsigned integer to be displayed
 */
void displayBits(unsigned value) {

    const unsigned SHIFT{8 * sizeof(unsigned) - 1};
    const unsigned MASK{static_cast<const unsigned>(1 << SHIFT)};

    std::cout << std::setw(10) << value << " = ";

    for (unsigned place{1}; place <= SHIFT + 1; ++place) {
        std::cout << (value & MASK ? '1' : '0');
        value <<= 1; // shift value left by 1

        if (place % 8 == 0) { // output a space after 8 bits
            std::cout << ' ';
        }
    }

    std::cout << std::endl;
}