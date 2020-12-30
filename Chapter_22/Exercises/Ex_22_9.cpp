/**
 * @file Ex_22_9.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Changing bit mask
 * @version 0.1
 * @date 2020-12-30
 * 
 * Exercise 22-9 Printing a Binary Representation of an Integer Value
 * 
 * Modify Fig. 22.6 by moving the set bit in the mask instead of moving bits on the
 * value to be printed in binary.
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "Ex_22_9.h"

/**
 * @brief Convert an unsigned integer to bit representation
 * 
 * @param value Unsigned integert to be converted
 * @return std::string Bit representation
 */
std::string displayBits(const unsigned value) {
    const unsigned SHIFT{8 * sizeof(unsigned) - 1};
    unsigned MASK{static_cast<unsigned>(1 << SHIFT)};
    std::string bitString{"0b"};

    for (unsigned i{1}; i <= SHIFT + 1; ++i) {
        bitString += (value & MASK) ? '1' : '0';
        MASK >>= 1;
    }

    return bitString;
}