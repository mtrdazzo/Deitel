/**
 * @file tst_Ex_10_12.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Test DollarAmount class functionality
 * @version 0.1
 * @date 2020-07-03
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <gtest/gtest.h>
#include "Ex_10_12.h"

/**
 * @brief Test functionality of the Addition operator
 * 
 */
TEST(DollarAmountOperators, Addition){
    DollarAmount dAmount1{100};
    DollarAmount dAmount2{100};

    EXPECT_EQ((dAmount1 + dAmount2).toString(), "2.00");

    DollarAmount dAmount3{901};
    EXPECT_EQ((dAmount1 + dAmount3).toString(), "10.01");

    /* Negative cents */
    DollarAmount dAmount4{-101};
    EXPECT_EQ((dAmount1 + dAmount4).toString(), "-0.01");

    /* Negative dollars */
    DollarAmount dAmount5{-200};
    EXPECT_EQ((dAmount1 + dAmount5).toString(), "-1.00");

    /* Negative dollars and cents */
    DollarAmount dAmount6{-201};
    EXPECT_EQ((dAmount1 + dAmount6).toString(), "-1.01");

    /* Adding zero */
    DollarAmount dAmount7{0};
    EXPECT_EQ((dAmount1 + dAmount7).toString(), dAmount1.toString());

    /* Positive integers */
    EXPECT_EQ((dAmount1 + 100).toString(), "2.00");

    /* Cents and dollars */
    EXPECT_EQ((dAmount1 + 901).toString(), "10.01");

    /* Negative cents */
    EXPECT_EQ((dAmount1 + -101).toString(), "-0.01");

    /* Negative dollars */
    EXPECT_EQ((dAmount1 + -200).toString(), "-1.00");

    /* Negative dollars and cents */
    EXPECT_EQ((dAmount1 + -201).toString(), "-1.01");

    /* Adding zero */
    EXPECT_EQ((dAmount1 + 0).toString(), dAmount1.toString());
}

/**
 * @brief Test functionality of the Subtraction operator
 * 
 */
TEST(DollarAmountOperators, Subtraction){
    DollarAmount dAmount1{100};
    DollarAmount dAmount2{100};

    DollarAmount dAmount3{901};
    EXPECT_EQ((dAmount1 - dAmount3).toString(), "-8.01");

    /* Negative cents */
    DollarAmount dAmount4{101};
    EXPECT_EQ((dAmount1 - dAmount4).toString(), "-0.01");

    /* Negative dollars */
    DollarAmount dAmount5{200};
    EXPECT_EQ((dAmount1 - dAmount5).toString(), "-1.00");

    /* Negative dollars and cents */
    DollarAmount dAmount6{201};
    EXPECT_EQ((dAmount1 - dAmount6).toString(), "-1.01");

    /* Adding zero */
    DollarAmount dAmount7{0};
    EXPECT_EQ((dAmount1 - dAmount7).toString(), dAmount1.toString());

    /* Positive integers */
    EXPECT_EQ((dAmount1 - -100).toString(), "2.00");

    /* Cents and dollars */
    EXPECT_EQ((dAmount1 - -901).toString(), "10.01");

    /* Negative cents */
    EXPECT_EQ((dAmount1 - 101).toString(), "-0.01");

    /* Negative dollars */
    EXPECT_EQ((dAmount1 - 200).toString(), "-1.00");

    /* Negative dollars and cents */
    EXPECT_EQ((dAmount1 - 201).toString(), "-1.01");

    /* Adding zero */
    EXPECT_EQ((dAmount1 - 0).toString(), dAmount1.toString());
}

/**
 * @brief Test functionality of the Division operator
 * 
 */
TEST(DollarAmountOperators, Division){

    DollarAmount dAmount1{100};
    DollarAmount dAmount2{100};
    
    /* Identity */
    EXPECT_EQ(dAmount1 / dAmount2, 1);

    /* Same magnitude */
    DollarAmount dAmount4{101};
    EXPECT_EQ(dAmount4 / dAmount1, 1);
    EXPECT_EQ(dAmount1 / dAmount4, 0);

    /* Different magnitude */
    DollarAmount dAmount5{11};
    EXPECT_EQ(dAmount5 / dAmount1, 0);
    EXPECT_EQ(dAmount1 / dAmount5, 9);

    /* Divide by zero */
    DollarAmount dAmount6{0};
    try {
        dAmount1 / dAmount6;
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "cannot divide by zero");
    }

        /* Identity */
    int64_t iAmount2{100};
    EXPECT_EQ(dAmount1 / iAmount2, 1);

    /* Same magnitude */
    int64_t iAmount4{101};
    EXPECT_EQ(dAmount1 / iAmount4, 0);

    /* Different magnitude */
    int64_t iAmount5{11};
    EXPECT_EQ(dAmount1 / iAmount5, 9);

    /* Divide by zero */
    int64_t iAmount6{0};
    try {
        dAmount1 / iAmount6;
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "cannot divide by zero");
    }
}