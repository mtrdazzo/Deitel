/**
 * @file tst_Ex_22_13.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Test mystery function
 * @version 0.1
 * @date 2020-12-30
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <gtest/gtest.h>
#include "Ex_22_13.h"

#include <cstdlib>

/**
 * @brief Test mystery function
 * 
 */
TEST(MysterFunction, WhatDoesItDo) {
    mystery(rand() % ~0U);
}