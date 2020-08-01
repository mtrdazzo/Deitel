/**
 * @file tst_Ex_13_13.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2020-08-01
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <gtest/gtest.h>
#include <Ex_13_13.h>

/**
 * @brief To Fail enter "Jon Doe" in the first entry with any desired extra input.
 * 
 */
TEST(UncorrectedInput, DISABLED_findExtraChars) {
    EXPECT_EQ(uncorrectedInput(), "John Doe 2020");
}

/**
 * @brief To Pass enter "Jon Doe" in the first entry with any desired extra input
 *        without entering a newline. Then enter "2020" on the next line.
 * 
 */
TEST(CorrectedInput, DISABLED_findExtraChars) {
    EXPECT_EQ(correctedInput(), "John Doe 2020");
}