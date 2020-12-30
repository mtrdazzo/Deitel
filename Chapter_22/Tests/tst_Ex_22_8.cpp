/**
 * @file tst_Ex_22_8.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Test power2 and divide2
 * @version 0.1
 * @date 2020-12-29
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <cstdlib>
#include <gtest/gtest.h>
#include "Ex_22_8.h"

class TimesTwoTests : public testing::Test {

    protected:
        void SetUp(void) {
            srand(static_cast<size_t>(time(nullptr)));
        }
        size_t numberRuns{10000};
};

class Power2Tests : public TimesTwoTests {};

class Divide2Tests : public TimesTwoTests {};

/**
 * @brief Expect any integer raised to the first power is itself.
 * 
 */
TEST_F(Power2Tests, ZeroExponent) {
    EXPECT_EQ(power2(UINT64_MAX, 0), UINT64_MAX);
    EXPECT_EQ(power2(1, 0), 1U);
    EXPECT_EQ(power2(0, 0), 0U);
    uint64_t randInt{rand() % UINT64_MAX};
    EXPECT_EQ(power2(randInt, 0), randInt);
}

/**
 * @brief Expect any integer raised to the first power is itself.
 * 
 */
TEST_F(Divide2Tests, ZeroExponent) {
    EXPECT_EQ(divide2(UINT64_MAX, 0), UINT64_MAX);
    EXPECT_EQ(divide2(1, 0), 1U);
    EXPECT_EQ(divide2(0, 0), 0U);
    uint64_t randInt{rand() % UINT64_MAX};
    EXPECT_EQ(divide2(randInt, 0), randInt);
}

/**
 * @brief Expect any integer with a positive shift is the same as multiplying by 2^n that integer.
 *        Overflow is undefined, only test for underflow calculations.
 * 
 */
TEST_F(Power2Tests, PositiveExponents) {

    uint64_t randInt;
    uint8_t randShift;

    // zero shifted is still zero
    EXPECT_EQ(power2(0, rand() % SIZE_MAX), 0U);

    // random shift of 1
    randShift = static_cast<uint8_t>(rand() % UINT64_WIDTH);
    EXPECT_EQ(power2(1, randShift), static_cast<uint64_t>(1UL << randShift));

    // shift of 1 out of bounds of 64-bits, undefined behavior
    EXPECT_NO_FATAL_FAILURE(power2(1, UINT64_WIDTH));

    // random values
    for (size_t randNum{0}; randNum < numberRuns; ++randNum) {

        /* pick random integer and shift that do not overflow variable memory space */
        randInt = rand() % UINT64_MAX;
        randShift = static_cast<uint8_t>(rand() % UINT64_WIDTH);
        while (randInt << randShift < randInt)
            randShift = static_cast<uint8_t>(rand() % UINT64_WIDTH);
        EXPECT_EQ(power2(randInt, randShift), randInt * (1UL << randShift));
    }
}

/**
 * @brief Expect any integer with a positive shift is the same as dividing by 2^n that integer.
 *        Overflow is undefined, only test for underflow calculations.
 * 
 */
TEST_F(Divide2Tests, PositiveExponents) {

    uint64_t randInt;
    uint8_t randShift;

    // zero shifted is still zero
    EXPECT_EQ(divide2(0, rand() % SIZE_MAX), 0U);

    // random shift of 1
    EXPECT_EQ(divide2(UINT64_MAX, 1), UINT64_MAX / 2);

    // shift of UINT64_MAX out of bounds of 64-bits, undefined behavior
    EXPECT_NO_FATAL_FAILURE(divide2(UINT64_MAX, UINT64_WIDTH));

    // random values
    for (size_t randNum{0}; randNum < numberRuns; ++randNum) {

        /* pick random integer and shift that do not overflow variable memory space */
        randInt = rand() % UINT64_MAX;
        randShift = static_cast<uint8_t>(rand() % UINT64_WIDTH);
        while (randInt >> randShift < randInt)
            randShift = static_cast<uint8_t>(rand() % UINT64_WIDTH);
        EXPECT_EQ(divide2(randInt, randShift), randInt / (1UL << randShift));
    }
}

/**
 * @brief Expect any integer with a negative shift to be equivalent to multiplying by 2^-n.
 *        Overflow is undefined, only test for underflow calculations.
 * 
 */
TEST_F(Power2Tests, NegativeExponents) {

    uint64_t randInt;
    uint8_t randShift;

    // random shift of -1
    randInt = rand() % UINT64_MAX + 1;
    EXPECT_EQ(power2(randInt, -1), randInt / 2);

    // shift out of bounds of 64-bits, undefined behavior
    EXPECT_NO_FATAL_FAILURE(power2(UINT64_MAX, -UINT64_WIDTH));

    // random values
    for (size_t randNum{0}; randNum < numberRuns; ++randNum) {

        /* pick random integer and shift that do not overflow variable memory space */
        randInt = rand() % UINT64_MAX;
        randShift = static_cast<uint8_t>(rand() % UINT64_WIDTH);
        while (randInt >> randShift > 0)
            randShift = static_cast<uint8_t>(rand() % UINT64_WIDTH);
        EXPECT_EQ(power2(randInt, -randShift), randInt / (1UL << randShift));
    }

    EXPECT_EQ(power2(UINT64_MAX, -(UINT64_WIDTH - 1)), 1UL);
}

/**
 * @brief Expect any integer with a negative shift to be equivalent to multiplying by 2^n.
 *        Overflow is undefined, only test for underflow calculations.
 * 
 */
TEST_F(Divide2Tests, NegativeExponents) {

    uint64_t randInt;
    uint8_t randShift;

    // random int shift of -1
    randInt = rand() % UINT64_MAX / 2;
    EXPECT_EQ(divide2(randInt, -1), randInt * 2);

    // shift out of bounds of 64-bits, undefined behavior
    EXPECT_NO_FATAL_FAILURE(divide2(1UL, -UINT64_WIDTH));

    // random values
    for (size_t randNum{0}; randNum < numberRuns; ++randNum) {

        /* pick random integer and shift that do not overflow variable memory space */
        randInt = rand() % UINT64_MAX;
        randShift = static_cast<uint8_t>(rand() % UINT64_WIDTH);
        while (randInt << randShift > randInt)
            randShift = static_cast<uint8_t>(rand() % UINT64_WIDTH);
        EXPECT_EQ(divide2(randInt, -randShift), randInt * (1UL << randShift));
    }

    EXPECT_EQ(divide2(1UL, -(UINT64_WIDTH - 1)), UINT64_MAX / 2 + 1);
}