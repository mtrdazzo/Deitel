/**
 * @file Ex_22_10.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Check Endianness
 * @version 0.1
 * @date 2020-12-30
 * 
 * Exercise 22-10 Determining a computer's byte ordering
 * 
 * When it comes to storing multibyte integers, such as short, int, and long, computers fall
 * into two categories, big-endian and little endian computers. In big-endian computers, the
 * high order byte is stored at the lowest address, whereas, in little-endian machines, the low
 * order byte is stored at the lowest address. Write a small program to test the endianness
 * of your computer.
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <cstdint>

/**
 * @brief Check endianness of computer.
 * 
 * @return int Returns 1 for big-endian, 0 for little endian.
 */
int checkEndianness(void) {

    uint16_t val;
    char *ptr = reinterpret_cast<char *>(&val);

    return ptr < (ptr + 1);
}