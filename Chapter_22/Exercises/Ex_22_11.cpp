/**
 * @file Ex_22_11.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Set bit
 * @version 0.1
 * @date 2020-12-30
 * 
 * Exercise 22-11 Seting bits in an integer
 * 
 * Write a function setBit that sets a specified bit. The function should take two unsigned
 * integers, the number to set the bit as, and the bit position to set. Write a drive program
 * to test your function.
 * 
 * @copyright Copyright (c) 2020
 * 
 */

/**
 * @brief Set bit position in integer
 * 
 * @param number Number
 * @param bitPosition Bit position to be set
 * @return unsigned Number with bit position set
 */
unsigned setBit(unsigned number, unsigned bitPosition) {
    if (bitPosition >= sizeof(unsigned) * 8)
        return number;
    else
        return number | (1 << bitPosition);
}