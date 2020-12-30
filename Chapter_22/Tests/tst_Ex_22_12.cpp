/**
 * @file tst_Ex_22_12.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief test for multiple
 * @version 0.1
 * @date 2020-12-30
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <gtest/gtest.h>
#include <cstdlib>
#include <iostream>
#include "Ex_22_12.h"

class FindXTest : public testing::Test {

    protected:

        void SetUp(void) {
            srand(static_cast<size_t>(time(nullptr)));
        }

        int X{1024};
        int minInteger{(1 << (sizeof(int) * 8 - 1))};
        int maxInteger{~minInteger};
        int randInt;
};

/**
 * @brief Test all possible multiples of X
 * 
 */
TEST_F(FindXTest, AllMultiples) {
    
    int minMultiple{minInteger / X};
    int maxMultiple{maxInteger / X};

    for (size_t run{0}; run < 10000; ++run) {
        randInt = rand() % maxMultiple + minMultiple;
        EXPECT_TRUE(multiple(X * randInt));
    }
}

/**
 * @brief Test all non multiples of X
 * 
 */
TEST_F(FindXTest, AllNonMultiples) {
    for (size_t run{0}; run < 10000; ++run) {
        randInt = (rand() % maxInteger - minInteger) & (X - 1);
        if (randInt) { // check only non-zero values
            EXPECT_FALSE(multiple(randInt));
        }
    }
}