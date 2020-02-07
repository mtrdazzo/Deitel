/**
 * @file tst_Ex_9_25.cpp
 *
 * @brief Tests the arithemetic and solving of quadratic equations.
 *
 * @author Matt Randazzo
 */

#include <Ex_9_5.h>
#include <gtest/gtest.h>

/**
 * @brief Verifies quadratic function with no arguments.
 */
TEST(ClassConstructor, NoArguments){

    Quadratic q1;

    EXPECT_DOUBLE_EQ(q1.getA(), 1.0);
    EXPECT_DOUBLE_EQ(q1.getB(), 0.0);
    EXPECT_DOUBLE_EQ(q1.getC(), 0.0);
}

/**
 * @brief Verifies quadratic function with a single zero value argument.
 */
TEST(ClassConstructor, SingleArgumentZero){

    double firstArg{0.0};
    Quadratic q1{firstArg};

    EXPECT_DOUBLE_EQ(q1.getA(), 1.0);
    EXPECT_DOUBLE_EQ(q1.getB(), 0.0);
    EXPECT_DOUBLE_EQ(q1.getC(), 0.0);
}

/**
 * @brief Verifies quadratic function with a single non-zero value argument.
 */
TEST(ClassConstructor, SingleArgumentNonZero){

    double firstArg{-2.0};
    Quadratic q1{firstArg};

    EXPECT_DOUBLE_EQ(q1.getA(), firstArg);
    EXPECT_DOUBLE_EQ(q1.getB(), 0.0);
    EXPECT_DOUBLE_EQ(q1.getC(), 0.0);
}

/**
 * @brief Verifies quadratic function with two arguments.
 */
TEST(ClassConstructor, TwoArguments){

    double firstArg{-1.0};
    double secondArg{3.0};
    Quadratic q1{firstArg,  secondArg};

    EXPECT_DOUBLE_EQ(q1.getA(), firstArg);
    EXPECT_DOUBLE_EQ(q1.getB(), secondArg);
    EXPECT_DOUBLE_EQ(q1.getC(), 0.0);
}

/**
 * @brief Verifies quadratic function with three arguments.
 */
TEST(ClassConstructor, ThreeArguments){

    double firstArg{10.0};
    double secondArg{4.6};
    double thirdArg{7.2};
    Quadratic q1{firstArg, secondArg, thirdArg};

    EXPECT_DOUBLE_EQ(q1.getA(), firstArg);
    EXPECT_DOUBLE_EQ(q1.getB(), secondArg);
    EXPECT_DOUBLE_EQ(q1.getC(), thirdArg);
}
