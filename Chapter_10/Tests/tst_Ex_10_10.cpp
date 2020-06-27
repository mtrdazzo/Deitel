#include <gtest/gtest.h>
#include "Ex_10_10.h"
#include <sstream>

/**
 * @brief Construct a Quadratic object
 * 
 */
TEST(QuadraticConstructor, DelegatedConstructor) {

    Quadratic noArgs;
    EXPECT_EQ(noArgs.m_iConstant, 0);
    EXPECT_EQ(noArgs.m_iLinear, 0);
    EXPECT_EQ(noArgs.m_iQuadratic, 0);

    Quadratic singleArg(1);
    EXPECT_EQ(singleArg.m_iConstant, 0);
    EXPECT_EQ(singleArg.m_iLinear, 0);
    EXPECT_EQ(singleArg.m_iQuadratic, 1);

    Quadratic doubleArgs(1, 2);
    EXPECT_EQ(doubleArgs.m_iConstant, 0);
    EXPECT_EQ(doubleArgs.m_iLinear, 2);
    EXPECT_EQ(doubleArgs.m_iQuadratic, 1);

    Quadratic tripleArgs(1, 2, 3);
    EXPECT_EQ(tripleArgs.m_iConstant, 3);
    EXPECT_EQ(tripleArgs.m_iLinear, 2);
    EXPECT_EQ(tripleArgs.m_iQuadratic, 1);
}

/**
 * @brief Add two Quadratic objects together.
 * 
 */
TEST(QuadraticOperators, Addition) {

    /* Add two quadratic objects with all positive constants */
    Quadratic quad1(1, 2, 3);
    Quadratic quad2 = quad1 + quad1;
    EXPECT_EQ(quad2.str(), "2x^2 + 4x + 6");

    /* Add one all positive one all negative that cancel out */
    Quadratic quad3(-1, -2, -3);
    Quadratic quad4 = quad1 + quad3;
    EXPECT_EQ(quad4.str(), "");

    /* Add one positive one negative with all negative one values */
    Quadratic quad5(-2, -3, -4);
    Quadratic quad6 = quad1 + quad5;
    EXPECT_EQ(quad6.str(), "-x^2 - x - 1");

    /* Add one positive one negative with all negative values less than -1 */
    Quadratic quad7(-3, -4, -5);
    Quadratic quad8 = quad1 + quad7;
    EXPECT_EQ(quad8.str(), "-2x^2 - 2x - 2");

    /* Addition with all positive one values */
    Quadratic quad9(0, -1, -2);
    Quadratic quad10 = quad1 + quad9;
    EXPECT_EQ(quad10.str(), "x^2 + x + 1");
}