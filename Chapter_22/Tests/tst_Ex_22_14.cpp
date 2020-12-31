/**
 * @file tst_Ex_22_14.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Test CalculatePercentages
 * @version 0.1
 * @date 2020-12-30
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <gtest/gtest.h>
#include <cstdlib>
#include <fstream>
#include <string>
#include "Ex_22_14.h"

class TestingCalculatePercentages : public testing::Test {

    protected:

        /**
         * @brief Write data to file, set input stream to file stream
         * 
         * @param data 
         */
        void WriteToFile(std::string data) {
            if (in.is_open()) {
                in.close();
            }

            out.open(fileName, std::ios::out);
            out << data;
            out.close();

            in.open(fileName, std::ios::in);
            std::cin.rdbuf(in.rdbuf());
        }

        /**
         * @brief Close in/out streams and remove temporary file
         * 
         */
        void TearDown() {
            in.close();
            out.close();
            remove(fileName);
        }

        /**
         * @brief Set the random seed
         * 
         */
        void SetUp(void) {
            srand(static_cast<size_t>(time(nullptr)));
        }

        std::ifstream in;
        std::ofstream out;
        const char* fileName{"input.tmp"};
        const size_t maxNumChars{80};
};

/**
 * @brief Test empty input
 * 
 */
TEST_F(TestingCalculatePercentages, EmptyString) {
    WriteToFile(std::string{""});
    Percentage results = CalculatePercentages();
    EXPECT_DOUBLE_EQ(results.percentAlpha, 0.0);
    EXPECT_DOUBLE_EQ(results.percentNum, 0.0);
}

/**
 * @brief Test all numbers
 * 
 */
TEST_F(TestingCalculatePercentages, AllNumbers) {
    WriteToFile(std::string{"123456789"});
    Percentage results = CalculatePercentages();
    EXPECT_DOUBLE_EQ(results.percentAlpha, 0.0);
    EXPECT_DOUBLE_EQ(results.percentNum, 100.0);
}

/**
 * @brief More data than CalculatePercentage buffer can handle
 * 
 */
TEST_F(TestingCalculatePercentages, BufferOverflow) {
    WriteToFile(std::string(maxNumChars + 1, 'M'));
    Percentage results = CalculatePercentages();
    EXPECT_DOUBLE_EQ(results.percentAlpha, 100.0);
    EXPECT_DOUBLE_EQ(results.percentNum, 0.0);
}

/**
 * @brief Test all alpha
 * 
 */
TEST_F(TestingCalculatePercentages, AllAlphabetical) {
    WriteToFile(std::string{"abcdefghi"});
    Percentage results = CalculatePercentages();
    EXPECT_DOUBLE_EQ(results.percentAlpha, 100.0);
    EXPECT_DOUBLE_EQ(results.percentNum, 0.0);
}

/**
 * @brief Test random string
 * 
 */
TEST_F(TestingCalculatePercentages, RandomNumberAlphabetical) {

    std::string randomString;
    size_t numInt;
    size_t numAlpha;
    size_t numChars;
    size_t randInt;

    for (size_t numRun{0}; numRun < 1000; ++numRun) {
        numInt = 0;
        numAlpha = 0;
        numChars = rand() % maxNumChars;
        for (size_t index{0}; index < numChars; ++index) {
            randInt = rand() % 10;
            if (randInt == 0)
                randomString += '#';
            else if (randInt % 2) {
                randomString += rand() % 9 + '0';
                ++numInt;
            }
            else {
                randomString += rand() % 25 + 'a';
                ++numAlpha;
            }
        }
        WriteToFile(randomString);
        Percentage results = CalculatePercentages();
        EXPECT_DOUBLE_EQ(results.percentAlpha,
                         (numChars == 0) ? 0 : (numAlpha * 100.0) / numChars);
        EXPECT_DOUBLE_EQ(results.percentNum, 
                        (numChars == 0) ? 0 : (numInt * 100.0) / numChars);
        randomString.erase();
    }
}

/**
 * @brief Test max length string
 * 
 */
TEST_F(TestingCalculatePercentages, MaxLengthString) {

    std::string randomString;
    size_t numInt = 0;
    size_t numAlpha = 0;

    for (size_t index{0}; index < maxNumChars; ++index)
        if (rand() % 2) {
            randomString += rand() % 9 + '0';
            ++numInt;
        }
        else {
            randomString += rand() % 25 + 'a';
            ++numAlpha;
        }
    WriteToFile(randomString);
    Percentage results = CalculatePercentages();

    /* denominator is maxNumChars - 1, account for null termination by removing last entry in string */
    isalpha(randomString.at(maxNumChars-1)) ? --numAlpha : --numInt;
    EXPECT_DOUBLE_EQ(results.percentAlpha, (numAlpha *  100.0) / (maxNumChars - 1));
    EXPECT_DOUBLE_EQ(results.percentNum, (numInt * 100.0) / (maxNumChars - 1));
}