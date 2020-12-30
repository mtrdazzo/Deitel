/**
 * @file tst_Ex_22_10.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Test for checkEndianness
 * @version 0.1
 * @date 2020-12-30
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <gtest/gtest.h>
#include "Ex_22_10.h"

/**
 * @brief Determine if computer is big/little endian
 * 
 */
TEST(CheckEndinness, IsBigOrLittleEndian) {
    EXPECT_NO_FATAL_FAILURE(checkEndianness());
}