/**
 * @file tst_Ex_10_6.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Test Memory Allocation and Deallocation Operators
 * @version 0.1
 * @date 2020-05-07
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <gtest/gtest.h>
#include "Ex_10_6.h"

TEST(AllocateMemory, SingleVariable) {

    EXPECT_EQ(allocateMemoryArray(10), STACK_SIZE);
}