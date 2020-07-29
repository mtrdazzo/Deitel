/**
 * @file Ex_13_12.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Test converting decimal to octal and hexadecimal formats
 * @version 0.1
 * @date 2020-07-28
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <gtest/gtest.h>
#include <Ex_13_12.h>

/**
 * @brief Test octal representation of decimal
 * 
 */
TEST(DifferentBases, OctalRepresentation) {

    EXPECT_EQ(dec2octal(0), "0");

    EXPECT_EQ(dec2octal(5), "05");

    EXPECT_EQ(dec2octal(4294967295), "037777777777");

    EXPECT_EQ(dec2octal(268435455), "01777777777");
}

/**
 * @brief Test hex representation of decimal
 * 
 */
TEST(DifferentBases, HexRepresentation) {

    EXPECT_EQ(dec2hex(0), "0x00000000");

    EXPECT_EQ(dec2hex(10), "0x0000000A");

    EXPECT_EQ(dec2hex(11259375), "0x00ABCDEF");

    EXPECT_EQ(dec2hex(4294967295), "0xFFFFFFFF");

    EXPECT_EQ(dec2hex(268435455), "0x0FFFFFFF");
}