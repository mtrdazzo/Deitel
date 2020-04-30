/**
 * @file tst_Ex_9_5.cpp
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

    EXPECT_STREQ("x^2", q1.toString().c_str());
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

    EXPECT_STREQ("x^2", q1.toString().c_str());
}

/**
 * @brief Verifies quadratic function with a single non-zero value argument.
 */
TEST(ClassConstructor, SingleArgumentNonZero){

    double firstArg{-1.0};
    Quadratic q1{firstArg};

    EXPECT_DOUBLE_EQ(q1.getA(), firstArg);
    EXPECT_DOUBLE_EQ(q1.getB(), 0.0);
    EXPECT_DOUBLE_EQ(q1.getC(), 0.0);

    EXPECT_STREQ("-x^2", q1.toString().c_str());
}

/**
 * @brief Verifies quadratic function with two arguments.
 */
TEST(ClassConstructor, TwoArguments){

    double firstArg{-1.0};
    double secondArg{1.0};
    Quadratic q1{firstArg,  secondArg};

    EXPECT_DOUBLE_EQ(q1.getA(), firstArg);
    EXPECT_DOUBLE_EQ(q1.getB(), secondArg);
    EXPECT_DOUBLE_EQ(q1.getC(), 0.0);

    EXPECT_STREQ("-x^2 + x", q1.toString().c_str());
}

/**
 * @brief Verifies quadratic function with three arguments.
 */
TEST(ClassConstructor, ThreeArguments){

    double firstArg{10.0};
    double secondArg{-1.0};
    double thirdArg{7.2};
    Quadratic q1{firstArg, secondArg, thirdArg};

    EXPECT_DOUBLE_EQ(q1.getA(), firstArg);
    EXPECT_DOUBLE_EQ(q1.getB(), secondArg);
    EXPECT_DOUBLE_EQ(q1.getC(), thirdArg);

    EXPECT_STREQ("10x^2 - x + 7.2", q1.toString().c_str());
}

/**
 * @brief Add two positive Quadratics together.
 */
TEST(Add, AddTwoPositive){

    double firstArg{10.0};
    double secondArg{4.6};
    double thirdArg{-7.2};
    Quadratic q1{firstArg, secondArg, thirdArg};
    Quadratic q2{firstArg, secondArg, thirdArg};

    q1.add(q2);

    EXPECT_DOUBLE_EQ(q1.getA(), 2 * firstArg);
    EXPECT_DOUBLE_EQ(q1.getB(), 2 * secondArg);
    EXPECT_DOUBLE_EQ(q1.getC(), 2 * thirdArg);

    EXPECT_DOUBLE_EQ(q2.getA(), firstArg);
    EXPECT_DOUBLE_EQ(q2.getB(), secondArg);
    EXPECT_DOUBLE_EQ(q2.getC(), thirdArg);

    EXPECT_STREQ("20x^2 + 9.2x - 14.4", q1.toString().c_str());
    EXPECT_STREQ("10x^2 + 4.6x - 7.2", q2.toString().c_str());
}

/**
 * @brief Add two negative Quadratics together.
 */
TEST(Add, AddTwoNegatives){

    double firstArg{-10.0};
    double secondArg{-4.6};
    double thirdArg{-7.2};
    Quadratic q1{firstArg, secondArg, thirdArg};
    Quadratic q2{firstArg, secondArg, thirdArg};

    q1.add(q2);

    EXPECT_DOUBLE_EQ(q1.getA(), 2 * firstArg);
    EXPECT_DOUBLE_EQ(q1.getB(), 2 * secondArg);
    EXPECT_DOUBLE_EQ(q1.getC(), 2 * thirdArg);

    EXPECT_DOUBLE_EQ(q2.getA(), firstArg);
    EXPECT_DOUBLE_EQ(q2.getB(), secondArg);
    EXPECT_DOUBLE_EQ(q2.getC(), thirdArg);

    EXPECT_STREQ("-20x^2 - 9.2x - 14.4", q1.toString().c_str());
    EXPECT_STREQ("-10x^2 - 4.6x - 7.2", q2.toString().c_str());
}

/**
 * @brief Add one negative Quadratic and one positive Quadratic together.
 */
TEST(Add, AddOneNegativeOnePositive){

    double firstArg{-10.0};
    double secondArg{-4.6};
    double thirdArg{-7.2};
    Quadratic q1{-firstArg, -secondArg, -thirdArg};
    Quadratic q2{firstArg, secondArg, thirdArg};

    q1.add(q2);

    EXPECT_DOUBLE_EQ(q1.getA(), 0);
    EXPECT_DOUBLE_EQ(q1.getB(), 0);
    EXPECT_DOUBLE_EQ(q1.getC(), 0);

    EXPECT_DOUBLE_EQ(q2.getA(), firstArg);
    EXPECT_DOUBLE_EQ(q2.getB(), secondArg);
    EXPECT_DOUBLE_EQ(q2.getC(), thirdArg);

    EXPECT_STREQ("", q1.toString().c_str());
    EXPECT_STREQ("-10x^2 - 4.6x - 7.2", q2.toString().c_str());
}

/**
 * @brief Subtract two positive Quadratics.
 */
TEST(Subtract, SubtractTwoPositive){

    double firstArg{10.0};
    double secondArg{4.6};
    double thirdArg{7.2};
    Quadratic q1{firstArg, secondArg, thirdArg};
    Quadratic q2{firstArg, secondArg, thirdArg};

    q1.subtract(q2);

    EXPECT_DOUBLE_EQ(q1.getA(), 0);
    EXPECT_DOUBLE_EQ(q1.getB(), 0);
    EXPECT_DOUBLE_EQ(q1.getC(), 0);

    EXPECT_DOUBLE_EQ(q2.getA(), firstArg);
    EXPECT_DOUBLE_EQ(q2.getB(), secondArg);
    EXPECT_DOUBLE_EQ(q2.getC(), thirdArg);

    EXPECT_STREQ("", q1.toString().c_str());
    EXPECT_STREQ("10x^2 + 4.6x + 7.2", q2.toString().c_str());
}

/**
 * @brief Subtract two negative Quadratics together.
 */
TEST(Subtract, SubtractTwoNegatives){

    double firstArg{-10.0};
    double secondArg{-4.6};
    double thirdArg{-7.2};
    Quadratic q1{firstArg, secondArg, thirdArg};
    Quadratic q2{firstArg, secondArg, thirdArg};

    q1.subtract(q2);

    EXPECT_DOUBLE_EQ(q1.getA(), 0);
    EXPECT_DOUBLE_EQ(q1.getB(), 0);
    EXPECT_DOUBLE_EQ(q1.getC(), 0);

    EXPECT_DOUBLE_EQ(q2.getA(), firstArg);
    EXPECT_DOUBLE_EQ(q2.getB(), secondArg);
    EXPECT_DOUBLE_EQ(q2.getC(), thirdArg);

    EXPECT_STREQ("", q1.toString().c_str());
    EXPECT_STREQ("-10x^2 - 4.6x - 7.2", q2.toString().c_str());
}

/**
 * @brief Subtract one negative Quadratic and one positive Quadratic together.
 */
TEST(Subtract, SubtractOneNegativeOnePositive){

    double firstArg{10.0};
    double secondArg{4.6};
    double thirdArg{7.2};
    Quadratic q1{-firstArg, -secondArg, -thirdArg};
    Quadratic q2{firstArg, secondArg, thirdArg};

    q1.subtract(q2);

    EXPECT_DOUBLE_EQ(q1.getA(), 2 * -firstArg);
    EXPECT_DOUBLE_EQ(q1.getB(), 2 * -secondArg);
    EXPECT_DOUBLE_EQ(q1.getC(), 2 * -thirdArg);

    EXPECT_DOUBLE_EQ(q2.getA(), firstArg);
    EXPECT_DOUBLE_EQ(q2.getB(), secondArg);
    EXPECT_DOUBLE_EQ(q2.getC(), thirdArg);

    EXPECT_STREQ("-20x^2 - 9.2x - 14.4", q1.toString().c_str());
    EXPECT_STREQ("10x^2 + 4.6x + 7.2", q2.toString().c_str());
}