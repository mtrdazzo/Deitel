/**
 * @file tst_Ex_22_18.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Test findPrintSubstring
 * @version 0.1
 * @date 2020-12-31
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <gtest/gtest.h>
#include <iostream>
#include <fstream>
#include <string>

#include "Ex_22_18.h"

/**
 * @brief Find substring in null line of text
 * 
 */
TEST(FindSubstring, NullLineOfText) {
    EXPECT_EQ(findPrintSubstring("", "non empty substring"), 0U);
}

/**
 * @brief Substring not in line of text
 * 
 */
TEST(FindSubstring, NotFoundSubstring) {
    EXPECT_EQ(findPrintSubstring("This line is full", "empty"), 0U);
}

/**
 * @brief Find substring at the beginning of the line of text
 * 
 */
TEST(FindSubstring, FindSubstringBeginning) {
    EXPECT_EQ(findPrintSubstring("empty, this line is full", "empty"), 1U);
}

/**
 * @brief Find substring at the end of the line of text
 * 
 */
TEST(FindSubstring, FindSubstringEnd) {
    EXPECT_EQ(findPrintSubstring("this line is full or is it empty", "empty"), 1U);
}

/**
 * @brief Find substring in the middle of the line of text
 * 
 */
TEST(FindSubstring, FindSubstringMiddle) {
    EXPECT_EQ(findPrintSubstring("this line is empty/full ", "empty"), 1U);
}

/**
 * @brief Find substring multiple times int the of the line of text
 * 
 */
TEST(FindSubstring, FindSubstringMultipleTimes) {
    EXPECT_EQ(findPrintSubstring("empty this empty line emptyis empty orfull empty", "empty"), 5U);
}

/**
 * @brief Line is substring
 * 
 */
TEST(FindSubstring, LineSubstringEqual) {
    EXPECT_EQ(findPrintSubstring("empty", "empty"), 1U);
}