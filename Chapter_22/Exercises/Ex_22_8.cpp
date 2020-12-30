/**
 * @file Ex_22_8.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Power2 and divide2 funtion definitions
 * @version 0.1
 * @date 2020-12-29
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "Ex_22_8.h"

/**
 * @brief Raise a base number to a power. Can only be used with unsigned integers.
 * 
 * @param number Base
 * @param pow Exponential power
 * @return uint64_t 
 */
uint64_t power2(uint64_t number, int pow) {
    if (pow == 0)
        return number;
    else if (pow < 0)
        return divide2(number, -pow);
    else
        return number << pow;
}

/**
 * @brief Raise a base number by 1/2^n where n is an integer. Can only be used with unsigned integers.
 * 
 * @param number Base
 * @param pow Exponential power
 * @return uint64_t 
 */
uint64_t divide2(uint64_t number, int pow) {
    if (pow == 0)
        return number;
    else if (pow < 0)
        return power2(number, -pow);
    else
        return number >> pow;
}