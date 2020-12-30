/**
 * @file Ex_22_8.h
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Function prototypes for divide2 and power2
 * @version 0.1
 * @date 2020-12-29
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef _EX_22_5_INCLUDE
#define _EX_22_5_INCLUDE

#include <cstdint>
#include <cstdlib>

/**
 * @brief Raise a base number to a power. Can only be used with unsigned integers.
 * 
 * @param number Base
 * @param pow Exponential power
 * @return uint64_t 
 */
uint64_t power2(uint64_t number, int pow);

/**
 * @brief Raise a base number by 1/2^n where n is an integer
 * 
 * @param number Base
 * @param pow Exponential power
 * @return uint64_t 
 */
uint64_t divide2(uint64_t number, int pow);

#endif // _EX_22_5_INCLUDE