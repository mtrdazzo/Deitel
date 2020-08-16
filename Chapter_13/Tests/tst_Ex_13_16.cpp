/**
 * @file tst_Ex_13_16.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Test the Point class
 * @version 0.1
 * @date 2020-08-07
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <fstream>
#include <string>
#include <gtest/gtest.h>
#include <Ex_13_16.h>

class TestComplexClass : public testing::Test {

    protected:

        void StreamToPoint(std::string numberStr) {
            outputFile.open(fileName);
            outputFile << numberStr;
            outputFile.close();

            inputFile.open(fileName);
            try {
                inputFile >> exampleComplex;
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
        Complex exampleComplex;

};

/**
 * @brief Test valid complex numbers
 * 
 */
TEST_F(TestComplexClass, validComplex) {

    std::string inputString{"3 + 8i"};
    StreamToPoint(inputString);
    EXPECT_EQ(exampleComplex.toString(), inputString);

    StreamToPoint("3+ 8i");
    EXPECT_EQ(exampleComplex.toString(), inputString);

    StreamToPoint("3 +8i");
    EXPECT_EQ(exampleComplex.toString(), inputString);

    StreamToPoint("3 +  8i");
    EXPECT_EQ(exampleComplex.toString(), inputString);

    StreamToPoint("3   + 8i");
    EXPECT_EQ(exampleComplex.toString(), inputString);

    StreamToPoint("3   +  8i");
    EXPECT_EQ(exampleComplex.toString(), inputString);

    inputString = "3 - 8i";
    StreamToPoint(inputString);
    EXPECT_EQ(exampleComplex.toString(), inputString);

    StreamToPoint("3- 8i");
    EXPECT_EQ(exampleComplex.toString(), inputString);

    StreamToPoint("3 -8i");
    EXPECT_EQ(exampleComplex.toString(), inputString);

    StreamToPoint("3 -  8i");
    EXPECT_EQ(exampleComplex.toString(), inputString);

    StreamToPoint("3   - 8i");
    EXPECT_EQ(exampleComplex.toString(), inputString);

    StreamToPoint("3   -  8i");
    EXPECT_EQ(exampleComplex.toString(), inputString);

    inputString = "2147483647 + 2147483647i";
    StreamToPoint(inputString);
    EXPECT_EQ(exampleComplex.toString(), inputString);

    StreamToPoint("2147483647  +  2147483647i");
    EXPECT_EQ(exampleComplex.toString(), inputString);

    inputString = "-2147483648 - 2147483648i";
    StreamToPoint(inputString);
    EXPECT_EQ(exampleComplex.toString(), inputString);

    StreamToPoint("-2147483648   -   2147483648i");
    EXPECT_EQ(exampleComplex.toString(), inputString);

    inputString = "-2147483648 + 2147483647i";
    StreamToPoint(inputString);
    EXPECT_EQ(exampleComplex.toString(), inputString);

    inputString = "0 + 0i";
    StreamToPoint(inputString);
    EXPECT_EQ(exampleComplex.toString(), "");

    inputString = "0 + 5i";
    StreamToPoint(inputString);
    EXPECT_EQ(exampleComplex.toString(), "5i");

    inputString = "0 - 5i";
    StreamToPoint(inputString);
    EXPECT_EQ(exampleComplex.toString(), "-5i");

    inputString = "0";
    StreamToPoint(inputString);
    EXPECT_EQ(exampleComplex.toString(), "");

    inputString = "0 + 10i       ";
    StreamToPoint(inputString);
    EXPECT_EQ(exampleComplex.toString(), "10i");
}

/**
 * @brief Test invalid complex numbers
 * 
 */
TEST_F(TestComplexClass, invalidComplex) {

    std::string inputString = "0j + 6i";
    EXPECT_THROW(StreamToPoint(inputString), std::invalid_argument);
    try {
        StreamToPoint(inputString);
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid character");
    }

    inputString = "-1a";
    EXPECT_THROW(StreamToPoint(inputString), std::invalid_argument);
    try {
        StreamToPoint(inputString);
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid character");
    }

    inputString = "-123456 * 0i";
    EXPECT_THROW(StreamToPoint(inputString), std::invalid_argument);
    try {
        StreamToPoint(inputString);
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid character");
    }

    inputString = "-123456 +a";
    EXPECT_THROW(StreamToPoint(inputString), std::invalid_argument);
    try {
        StreamToPoint(inputString);
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid character");
    }

    inputString = "-2147483649";
    EXPECT_THROW(StreamToPoint(inputString), std::invalid_argument);
    try {
        StreamToPoint(inputString);
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "value too small");
    }

    inputString = "2147483648";
    EXPECT_THROW(StreamToPoint(inputString), std::invalid_argument);
    try {
        StreamToPoint(inputString);
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "value too large");
    }

    inputString = "0 a";
    EXPECT_THROW(StreamToPoint(inputString), std::invalid_argument);
    try {
        StreamToPoint(inputString);
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid character");
    }

    inputString = "0 -1a";
    EXPECT_THROW(StreamToPoint(inputString), std::invalid_argument);
    try {
        StreamToPoint(inputString);
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid character");
    }

    inputString = "0 -123456ij";
    EXPECT_THROW(StreamToPoint(inputString), std::invalid_argument);
    try {
        StreamToPoint(inputString);
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid character");
    }

    inputString = "0 -2147483649i";
    EXPECT_THROW(StreamToPoint(inputString), std::invalid_argument);
    try {
        StreamToPoint(inputString);
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "value too small");
    }

    inputString = "0 + 2147483648i";
    EXPECT_THROW(StreamToPoint(inputString), std::invalid_argument);
    try {
        StreamToPoint(inputString);
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "value too large");
    }

    inputString = "0 + 2147483647il";
    EXPECT_THROW(StreamToPoint(inputString), std::invalid_argument);
    try {
        StreamToPoint(inputString);
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid character");
    }
}