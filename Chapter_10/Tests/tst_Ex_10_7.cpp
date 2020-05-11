/**
 * @file tst_Ex_10_7.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2020-05-11
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <gtest/gtest.h>
#include "Ex_10_7.h"

/**
 * @brief Construct a new DoubleSubscriptedArray object
 * 
 */
TEST(Constructor, InstantiateArray) {

    DoubleSubscriptedArray dsa(3,2);

    EXPECT_EQ(dsa.getSize(), 3 * 2u);

    try {
        DoubleSubscriptedArray dsa(0, 4);
    }
    catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "row and column must be greater than 0");
    }

    try {
        DoubleSubscriptedArray dsa(4, 0);
    }
    catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "row and column must be greater than 0");
    }

    try {
        DoubleSubscriptedArray dsa(0, 0);
    }
    catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "row and column must be greater than 0");
    }
}

/**
 * @brief Get the lvalue of a non-const DoubleSubscriptedArray object.
 * 
 */
TEST(SubscriptedOverload, NonConstantObject) {

    const int testInt{5};
    int testOut{0};
    const int row{10};
    const int col{5};

    DoubleSubscriptedArray dArray(row, col);

    try {
        dArray(row, col - 1) = testInt;
    }
    catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid row");
    }

    try {
        dArray(row - 1, col) = testInt;
    }
    catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid column");
    }

    dArray(row - 1, col - 1) = testInt;

    try {
        testOut = dArray(row, col - 1);
    }
    catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid row");
    }

    try {
        testOut = dArray(row - 1, col);
    }
    catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid column");
    }

    EXPECT_EQ(testOut, 0);
    EXPECT_EQ(dArray(row - 1, col - 1), testInt);
}