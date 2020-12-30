/**
 * @file tst_Ex_22_9.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Tests for displayBits method
 * @version 0.1
 * @date 2020-12-30
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <gtest/gtest.h>
#include <cstdlib> // srand(), rand(), atoi() prototypes
#include <ctime> // time() prototype
#include "Ex_22_9.h"

class TestDisplayBits : public testing::Test {

    protected:

        void SetUp() {
            srand(static_cast<size_t>(time(nullptr))); // random seed
        }

        std::string expectedStr{"0b"};
        const size_t numRandomIterations{10000};
};

/**
 * @brief Display bits for an unsigned integer of value 0
 * 
 */
TEST_F(TestDisplayBits, Zero) {
    expectedStr.append(std::string(sizeof(unsigned) * 8, '0'));
    EXPECT_EQ(displayBits(0U), expectedStr);
}

/**
 * @brief Display bits for maximum value unsigned integer
 * 
 */
TEST_F(TestDisplayBits, MaxUnsignedInt) {
    expectedStr.append(std::string(sizeof(unsigned) * 8, '1'));
    EXPECT_EQ(displayBits(~0U), expectedStr);
}

/**
 * @brief Display bits for random integers
 * 
 */
TEST_F(TestDisplayBits, RandomUnsignedInt) {
    unsigned randInt;
    for (size_t run{0}; run < numRandomIterations; ++run) {
        randInt = rand() % ~0U;
        std::string bitString = displayBits(randInt).substr(2, sizeof(unsigned) * 8 + 2);
        EXPECT_EQ(static_cast<unsigned>(stoi(bitString, nullptr, 2)),
                  randInt);
    }
}