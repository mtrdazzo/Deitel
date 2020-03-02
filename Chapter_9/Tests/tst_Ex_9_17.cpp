#include <Ex_9_17.h>
#include <gtest/gtest.h>

/**
 * @brief Cosntruct Time object with no arguments.
 */
TEST(Constructor, NoArguments) {

    Time test;

    EXPECT_EQ(1, test.getHour());
    EXPECT_EQ(2, test.getMinute());
    EXPECT_EQ(3, test.getSeconds());
}

/**
 * @brief Construct Time object with only an hour argument.
 */
TEST(Constructor, SingleArgument) {

    Time test{2};

    EXPECT_EQ(2, test.getHour());
    EXPECT_EQ(2, test.getMinute());
    EXPECT_EQ(3, test.getSeconds());
}

/**
 * @brief Construct a Time argument with hour and minute arguments.
 */
TEST(Constructor, TwoArguments) {

    Time test{2, 1};

    EXPECT_EQ(2, test.getHour());
    EXPECT_EQ(1, test.getMinute());
    EXPECT_EQ(3, test.getSeconds());
}

/**
 * @brief Construct a Time argument with hour, minute, and second.
 */
TEST(Constructor, ThreeArguments) {

    Time test{3, 2, 1};

    EXPECT_EQ(3, test.getHour());
    EXPECT_EQ(2, test.getMinute());
    EXPECT_EQ(1, test.getSeconds());
}