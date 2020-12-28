/**
 * @file Fig_22_11.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Demonstrate left-shift and right-shift operators
 * @version 0.1
 * @date 2020-12-27
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <iostream>
#include <iomanip>

void displayBits(unsigned);

int main() {
    unsigned number1{960};

    // demonstrate bitwise left shift
    std::cout << "The result of left shifting\n";
    displayBits(number1);
    std::cout << "8 bit positions using the left-shift operator is\n";
    displayBits(number1 << 8);

    // demonstrate bitwise right shift
    std::cout << "\nThe result of right shifting\n";
    displayBits(number1);
    std::cout << "8 bit positions using the right-shift operator is\n";
    displayBits(number1 >> 8);
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