/**
 * @file tst_Ex_22_17.cpp
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

#include "Ex_22_17.h"

class TestFindPrintSubstring : public testing::Test {

    protected:

        /**
         * @brief Write to temporary file to test without stdin
         * 
         * @param line Line of text to be searched
         * @param substring Substring to search for within line of text
         */
        void WriteToTmpFile(std::string line, std::string substring) {
            if (in.is_open())
                in.close();
            
            out.open(fileName, std::ios::out);
            out << line << '\n' << substring;
            out.close();

            in.open(fileName, std::ios::in);
            std::cin.rdbuf(in.rdbuf());
        }

        /**
         * @brief Remove tmp file and close file streams
         * 
         */
        void TearDown(void) {
            remove(fileName);
            in.close();
            out.close();
        }

        std::ifstream in;
        std::ofstream out;
        const char *fileName{"file.tmp"};

};

/**
 * @brief Find substring in null line of text
 * 
 */
TEST_F(TestFindPrintSubstring, NullLineOfText) {
    WriteToTmpFile(std::string{""}, std::string{"non empty substring"});
    EXPECT_EQ(findPrintSubstring(), 0U);
}

/**
 * @brief Substring not in line of text
 * 
 */
TEST_F(TestFindPrintSubstring, NotFoundSubstring) {
    WriteToTmpFile(std::string{"This line is full"}, std::string{"empty"});
    EXPECT_EQ(findPrintSubstring(), 0U);
}

/**
 * @brief Find substring at the beginning of the line of text
 * 
 */
TEST_F(TestFindPrintSubstring, FindSubstringBeginning) {
    WriteToTmpFile(std::string{"empty, this line is full"}, std::string{"empty"});
    EXPECT_EQ(findPrintSubstring(), 1U);
}

/**
 * @brief Find substring at the end of the line of text
 * 
 */
TEST_F(TestFindPrintSubstring, FindSubstringEnd) {
    WriteToTmpFile(std::string{"this line is full or is it empty"}, std::string{"empty"});
    EXPECT_EQ(findPrintSubstring(), 1U);
}

/**
 * @brief Find substring in the middle of the line of text
 * 
 */
TEST_F(TestFindPrintSubstring, FindSubstringMiddle) {
    WriteToTmpFile(std::string{"this line is empty/full "}, std::string{"empty"});
    EXPECT_EQ(findPrintSubstring(), 1U);
}

/**
 * @brief Find substring multiple times int the of the line of text
 * 
 */
TEST_F(TestFindPrintSubstring, FindSubstringMultipleTimes) {
    WriteToTmpFile(std::string{"empty this empty line emptyis empty/full empty"}, std::string{"empty"});
    EXPECT_EQ(findPrintSubstring(), 5U);
}

/**
 * @brief Line is substring
 * 
 */
TEST_F(TestFindPrintSubstring, LineSubstringEqual) {
    WriteToTmpFile(std::string{"empty"}, std::string{"empty"});
    EXPECT_EQ(findPrintSubstring(), 1U);
}