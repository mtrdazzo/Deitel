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

/**
 * @brief Test equality operators for single element arrays
 * 
 */
TEST(EqualityOperators, SingleElement) {

    DoubleSubscriptedArray dsa1(1, 1);
    DoubleSubscriptedArray dsa2(1, 1);
    DoubleSubscriptedArray dsa3(1, 1);

    int testInt{5};

    dsa1(0, 0) = testInt;
    dsa2(0, 0) = testInt;
    dsa3(0, 0) = testInt + 1;

    EXPECT_TRUE(dsa1 == dsa2);
    EXPECT_FALSE(dsa1 == dsa3);
    EXPECT_TRUE(dsa1 != dsa3);
}

/**
 * @brief Test Equality Operators for multiple element arrays
 * 
 */
TEST(EqualityOperators, MultipleElements) {

    int testInts[]{2, 3, 4};

    DoubleSubscriptedArray dsa1(1, 3);
    DoubleSubscriptedArray dsa2(1, 3);
    DoubleSubscriptedArray dsa3(1, 4);
    DoubleSubscriptedArray dsa4(1, 3);

    for (size_t index{0}; index < 3; index++) {
        dsa1(0, index) = testInts[index];
        dsa2(0, index) = testInts[index];
        dsa3(0, index) = testInts[index];
        dsa4(0, index) = testInts[index];
    }

    dsa4(0, 2) += 1;

    EXPECT_TRUE(dsa1 == dsa2);
    EXPECT_FALSE(dsa1 == dsa3);
    EXPECT_TRUE(dsa2 != dsa3);
    EXPECT_FALSE(dsa4 == dsa1);
}

/**
 * @brief Test the copy operator for single and multiple sized data arrays.
 * 
 */
TEST(CopyOperator, MultipleElements) {

    int testInts[]{2, 3, 4};
    int testInt{5};
    DoubleSubscriptedArray dsa1(1, 1);
    DoubleSubscriptedArray dsa2(1, 1);
    DoubleSubscriptedArray dsa3(1, 3);
    const DoubleSubscriptedArray dsa4(1, 1);

    dsa1(0, 0) = testInt;
    dsa2(0, 0) = testInt + 1;

    for (size_t index{0}; index < 3; index++) {
        dsa3(0, index) = testInts[index];
    }

    EXPECT_FALSE(dsa1 == dsa2);
    dsa2 = dsa1;
    EXPECT_TRUE(dsa1 == dsa2);

    EXPECT_FALSE(dsa1 == dsa3);
    dsa1 = dsa3;
    EXPECT_TRUE(dsa1 == dsa3);

    EXPECT_FALSE(dsa3 == dsa2);
    dsa3 = dsa2;
    EXPECT_TRUE(dsa3 == dsa2);

    EXPECT_EQ(dsa4(0, 0), 0);

    int tempInt;

    try {
        tempInt = dsa4(0, 1);
        EXPECT_EQ(tempInt, 0);
    }
    catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid column");
    }

    try {
        tempInt = dsa4(1, 0);
        EXPECT_EQ(tempInt, 0);
    }
    catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid row");
    }
}