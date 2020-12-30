/**
 * @file Ex_22_13.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Mystery program
 * @version 0.1
 * @date 2020-12-30
 * 
 * Exercise 22-13
 * 
 * What does the following program do?
 * 
 * Returns true if the number has an even number of bits.
 * 
 * @copyright Copyright (c) 2020
 * 
 */

/**
 * @brief Mystery function, what does it do??
 * 
 * @param bits 
 * @return true 
 * @return false 
 */
bool mystery(unsigned bits) {

    const int SHIFT{8 * sizeof(unsigned) -1};
    const unsigned MASK{static_cast<unsigned>(1 << SHIFT)};
    unsigned total{0};

    for (int i{0}; i < SHIFT + 1; ++i, bits <<= 1) {
        if ((bits & MASK) == MASK)
            ++total;
    }
    return !(total % 2);
}