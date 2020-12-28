/**
 * @file Fig_22_8.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Bitwise AND, inclusive OR, exclusive OR and complement operators.
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
    unsigned number1{2179876355};
    unsigned mask{1};

    // demonstrate bitwise AND
    std::cout << "The result of combining the following\n";
    displayBits(number1);
    displayBits(mask);
    std::cout << "using the bitwise AND operator & is\n";
    displayBits(number1 & mask);
    std::cout << std::endl;

    // demonstrate bitwise OR
    number1 = 15;
    unsigned setBits{241};
    std::cout << "The result of combining the following\n";
    displayBits(number1);
    displayBits(setBits);
    std::cout << "using the bitwise OR operator | is\n";
    displayBits(number1 | setBits);
    std::cout << std::endl;

    // demonstrate bitwise exclusive OR
    number1 = 139;
    unsigned number2{199};
    std::cout << "The result of combining the following\n";
    displayBits(number1);
    displayBits(number2);
    std::cout << "using the bitwise exclusive OR operator ^ is\n";
    displayBits(number1 ^ number2);
    std::cout << std::endl;

    // demonstrate bitwise complement
    number1 = 21845;
    std::cout << "\nThe one's complement of \n";
    displayBits(number1);
    std::cout << "is" << std::endl;
    displayBits(~number1);
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