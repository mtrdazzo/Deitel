/**
 * @file tst_Ex_22_11.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Test setBit function
 * @version 0.1
 * @date 2020-12-30
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <gtest/gtest.h>
#include <cstdlib>
#include "Ex_22_11.h"

class SetBitTest : public testing::Test {
    protected:

        /**
         * @brief Set the Up object with random seed
         * 
         */
        void SetUp(void) {
            srand(static_cast<size_t>(time(nullptr)));
        }

        /**
         * @brief Get the Random Integer
         * 
         * @return unsigned 
         */
        unsigned GetRandomInt() {
            return rand() % ~0U;;
        }

        unsigned GetRandomBit() {
            return rand() % (sizeof(unsigned) - 1);
        }

        unsigned randomInt{0};
        unsigned randomBit{0};

        /**
         * @brief Number of iterations for random numbers
         * 
         */
        const size_t numRandomIterations{10000};
};

/**
 * @brief Set bit for maximum unsigned value
 * 
 */
TEST_F(SetBitTest, MaxUnsignedValue) {
    randomInt = GetRandomBit();
    EXPECT_EQ(setBit(~0U, randomInt), ~0U);
}

/**
 * @brief Set bit for zero
 * 
 */
TEST_F(SetBitTest, Zero) {
    randomInt = GetRandomBit();
    EXPECT_EQ(setBit(0U, randomInt), static_cast<unsigned>(1 << randomInt));
}

/**
 * @brief Set random bit on random number
 * 
 */
TEST_F(SetBitTest, RandomBitRandomInt) {
    randomInt = GetRandomInt();

    for (size_t index{0}; index < numRandomIterations; ++index) {
        randomBit = GetRandomBit();
        EXPECT_GE(setBit(randomInt, randomBit), randomInt);
        EXPECT_EQ(setBit(randomInt, randomBit), randomInt | 1 << randomBit);
    }
}

/**
 * @brief Attempt to set an out of range bit
 * 
 */
TEST_F(SetBitTest, OutOfRange) {
    randomInt = GetRandomInt();
    EXPECT_EQ(setBit(randomInt, sizeof(unsigned) * 8 + 1), randomInt);
}