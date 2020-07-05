/**
 * @file tst_Ex_10_13.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Testing functionality of DollarAmount with commutative addition, subtraction, multiplication
 * @version 0.1
 * @date 2020-07-05
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <gtest/gtest.h>
#include <Ex_10_13.h>

/**
 * @brief Test functionality of the Addition operator
 * 
 */
TEST(DollarAmountOperators, Addition){
    DollarAmount dAmount1{100};

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

    /* Positive integers */
    EXPECT_EQ((100 + dAmount1).toString(), "2.00");

    /* Cents and dollars */
    EXPECT_EQ((901 + dAmount1).toString(), "10.01");

    /* Negative cents */
    EXPECT_EQ((-101 + dAmount1).toString(), "-0.01");

    /* Negative dollars */
    EXPECT_EQ((-200 + dAmount1).toString(), "-1.00");

    /* Negative dollars and cents */
    EXPECT_EQ((-201 + dAmount1).toString(), "-1.01");

    /* Adding zero */
    EXPECT_EQ((0 + dAmount1).toString(), dAmount1.toString());
}

/**
 * @brief Test functionality of the Subtraction operator
 * 
 */
TEST(DollarAmountOperators, Subtraction){
    DollarAmount dAmount1{100};

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

        /* Positive integers */
    EXPECT_EQ((-100 - dAmount1).toString(), "-2.00");

    /* Cents and dollars */
    EXPECT_EQ((-901 - dAmount1).toString(), "-10.01");

    /* Negative cents */
    EXPECT_EQ((101 - dAmount1).toString(), "0.01");

    /* Negative dollars */
    EXPECT_EQ((200 - dAmount1).toString(), "1.00");

    /* Negative dollars and cents */
    EXPECT_EQ((201 - dAmount1).toString(), "1.01");

    /* Adding zero */
    EXPECT_EQ((0 - dAmount1).toString(), "-1.00");
}

/**
 * @brief Test functionality of the Division operator
 * 
 */
TEST(DollarAmountOperators, Division){

    DollarAmount dAmount1{100};

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

    /* Identity */
    EXPECT_EQ(100 / dAmount1, 1);

    /* Same magnitude */
    EXPECT_EQ(101 / dAmount1, 1);

    /* Different magnitude */
    EXPECT_EQ(11 / dAmount1, 0);

    /* Different magnitude */
    EXPECT_EQ(1100 / dAmount1, 11);

    /* Divide by zero */
    try {
        dAmount1 / 0;
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "cannot divide by zero");
    }
}

/**
 * @brief Test functionality of the Multiplication operator
 * 
 */
TEST(DollarAmountOperators, Multiplication){

    /* Identity */
    EXPECT_EQ((DollarAmount(100) * DollarAmount(1)).toString(), DollarAmount(100).toString());

    /* Same magnitude */
    EXPECT_EQ((DollarAmount(2) * DollarAmount(2)).toString(), DollarAmount(4).toString());

    /* Different magnitude */
    EXPECT_EQ((DollarAmount(8) * DollarAmount(9)).toString(), DollarAmount(72).toString());

    /* Multiply by zero */
    EXPECT_EQ((DollarAmount(100) * DollarAmount(0)).toString(), DollarAmount(0).toString());

    /* Identity */
    EXPECT_EQ((DollarAmount(100) * 1).toString(), DollarAmount(100).toString());

    /* Same magnitude */
    EXPECT_EQ((DollarAmount(2) * 2).toString(), DollarAmount(4).toString());

    /* Different magnitude */
    EXPECT_EQ((DollarAmount(8) * 9).toString(), DollarAmount(72).toString());

    /* Multiply by zero */
    EXPECT_EQ((DollarAmount(100) * 0).toString(), DollarAmount(0).toString());


    /* Identity */
    EXPECT_EQ((1 * DollarAmount(100)).toString(), DollarAmount(100).toString());

    /* Same magnitude */
    EXPECT_EQ((2 * DollarAmount(2)).toString(), DollarAmount(4).toString());

    /* Different magnitude */
    EXPECT_EQ((9 * DollarAmount(8)).toString(), DollarAmount(72).toString());

    /* Multiply by zero */
    EXPECT_EQ((0 * DollarAmount(100)).toString(), DollarAmount(0).toString());
}