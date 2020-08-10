/**
 * @file tst_Ex_13_17.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Test the Statistics class
 * @version 0.1
 * @date 2020-08-09
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <fstream>
#include <string>
#include <gtest/gtest.h>
#include <Ex_13_17.h>

class TestStatisticsClass : public testing::Test {

    protected:

        void StreamToStats(std::string numberStr) {
            outputFile.open(fileName);
            outputFile << numberStr;
            outputFile.close();

            inputFile.open(fileName);
            try {
                inputFile >> exampleStatistics;
            } catch (std::invalid_argument & err) {
                inputFile.close();
                throw;
            }

            inputFile.close();
        }

        void TearDown() {
            std::remove(fileName);
        }

        std::ifstream inputFile;
        std::ofstream outputFile;
        const char * fileName{"testFile.txt"};
        Statistics exampleStatistics;

};

/**
 * @brief Test valid entries for the Statistics class
 * 
 */
TEST_F(TestStatisticsClass, validEntries) {

    /* single digit */
    std::string inputString{"3"};
    StreamToStats(inputString);
    EXPECT_EQ(exampleStatistics.max(), 3);
    EXPECT_EQ(exampleStatistics.min(), 3);
    EXPECT_EQ(exampleStatistics.mean(), 3);
    EXPECT_EQ(exampleStatistics.median(), 3);

    /* two digits */
    inputString = "8 3";
    StreamToStats(inputString);
    EXPECT_EQ(exampleStatistics.max(), 8);
    EXPECT_EQ(exampleStatistics.min(), 3);
    EXPECT_EQ(exampleStatistics.mean(), 5.5);
    EXPECT_EQ(exampleStatistics.median(), 5.5);

    /* multiple digits */
    inputString = "8 3 1";
    StreamToStats(inputString);
    EXPECT_EQ(exampleStatistics.max(), 8);
    EXPECT_EQ(exampleStatistics.min(), 1);
    EXPECT_EQ(exampleStatistics.mean(), 4);
    EXPECT_EQ(exampleStatistics.median(), 3);

    /* multiple digits */
    inputString = "8 3 -10 0 5";
    StreamToStats(inputString);
    EXPECT_EQ(exampleStatistics.max(), 8);
    EXPECT_EQ(exampleStatistics.min(), -10);
    EXPECT_EQ(exampleStatistics.mean(), 1.2);
    EXPECT_EQ(exampleStatistics.median(), 3);

    /* multiple digits */
    inputString = "    2147483647 3    -2147483648 0 -5";
    StreamToStats(inputString);
    EXPECT_EQ(exampleStatistics.max(), 2147483647);
    EXPECT_EQ(exampleStatistics.min(), -2147483648);
    EXPECT_EQ(exampleStatistics.mean(), -0.6);
    EXPECT_EQ(exampleStatistics.median(), 0);
}


/**
 * @brief Test empty vector
 * 
 */
TEST_F(TestStatisticsClass, emptyVector) {

    EXPECT_THROW(exampleStatistics.mean(), std::invalid_argument);
    try {
        exampleStatistics.mean();
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "empty vector");
    }

    EXPECT_THROW(exampleStatistics.median(), std::invalid_argument);
    try {
        exampleStatistics.median();
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "empty vector");
    }

    EXPECT_THROW(exampleStatistics.min(), std::invalid_argument);
    try {
        exampleStatistics.min();
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "empty vector");
    }

    EXPECT_THROW(exampleStatistics.max(), std::invalid_argument);
    try {
        exampleStatistics.max();
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "empty vector");
    }
}

/**
 * @brief Test invalid entries for the Statistics class
 * 
 */
TEST_F(TestStatisticsClass, invalidEntries) {

    /* single invalid character */
    std::string inputString{"a"};
    EXPECT_THROW(StreamToStats(inputString), std::invalid_argument);
    try {
        StreamToStats(inputString);
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid character");
    }

    /* invalid character in multi digit */
    inputString = "34a";
    EXPECT_THROW(StreamToStats(inputString), std::invalid_argument);
    try {
        StreamToStats(inputString);
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid character");
    }

    /* invalid character in multiple entry */
    inputString = "34 56a";
    EXPECT_THROW(StreamToStats(inputString), std::invalid_argument);
    try {
        StreamToStats(inputString);
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid character");
    }

    /* invalid character in multiple entry */
    inputString = "34 56b 445";
    EXPECT_THROW(StreamToStats(inputString), std::invalid_argument);
    try {
        StreamToStats(inputString);
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid character");
    }

    /* invalid character in multiple entry */
    inputString = "34 56 --445";
    EXPECT_THROW(StreamToStats(inputString), std::invalid_argument);
    try {
        StreamToStats(inputString);
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid symbol");
    }

    /* invalid character in multiple entry */
    inputString = "34 --56 445";
    EXPECT_THROW(StreamToStats(inputString), std::invalid_argument);
    try {
        StreamToStats(inputString);
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid symbol");
    }

    /* number too big */
    inputString = "2147483648 --56 445";
    EXPECT_THROW(StreamToStats(inputString), std::invalid_argument);
    try {
        StreamToStats(inputString);
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "value too large");
    }

    /* number too big */
    inputString = "2147483647 -56 2147483648";
    EXPECT_THROW(StreamToStats(inputString), std::invalid_argument);
    try {
        StreamToStats(inputString);
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "value too large");
    }

    /* number too small */
    inputString = "2147483647 -56 -2147483649";
    EXPECT_THROW(StreamToStats(inputString), std::invalid_argument);
    try {
        StreamToStats(inputString);
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "value too small");
    }

    /* number too small */
    inputString = "-2147483649 -56 2147483647";
    EXPECT_THROW(StreamToStats(inputString), std::invalid_argument);
    try {
        StreamToStats(inputString);
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "value too small");
    }
}