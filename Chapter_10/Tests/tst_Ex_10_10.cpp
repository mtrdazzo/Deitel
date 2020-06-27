#include <gtest/gtest.h>
#include "Ex_10_10.h"

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