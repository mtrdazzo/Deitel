/**
 * @file tst_Ex_13_15.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Test the Point class
 * @version 0.1
 * @date 2020-08-01
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <fstream>
#include <gtest/gtest.h>
#include <Ex_13_15.h>

class TestPointClass : public testing::Test {

    protected:

        void StreamToPoint(std::string numberStr) {
            outputFile.open(fileName);
            outputFile << numberStr;
            outputFile.close();

            inputFile.open(fileName);
            try {
                inputFile >> examplePoint;
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
        Point examplePoint;

};

TEST_F(TestPointClass, validPoints) {

    StreamToPoint("34 34");
    EXPECT_EQ(examplePoint.toString(), "xCoordinate: 34\nyCoordinate: 34");

    StreamToPoint("0 0");
    EXPECT_EQ(examplePoint.toString(), "xCoordinate: 0\nyCoordinate: 0");

    StreamToPoint("2147483647 2147483647");
    EXPECT_EQ(examplePoint.toString(), "xCoordinate: 2147483647\nyCoordinate: 2147483647");

    StreamToPoint("32768 32768");
    EXPECT_EQ(examplePoint.toString(), "xCoordinate: 32768\nyCoordinate: 32768");

    StreamToPoint("-1 -1");
    EXPECT_EQ(examplePoint.toString(), "xCoordinate: -1\nyCoordinate: -1");

    StreamToPoint("-34 -34");
    EXPECT_EQ(examplePoint.toString(), "xCoordinate: -34\nyCoordinate: -34");

    StreamToPoint("-32768 -32768");
    EXPECT_EQ(examplePoint.toString(), "xCoordinate: -32768\nyCoordinate: -32768");

    StreamToPoint("-2147483648 -2147483648");
    EXPECT_EQ(examplePoint.toString(), "xCoordinate: -2147483648\nyCoordinate: -2147483648");

    StreamToPoint("-1 1");
    EXPECT_EQ(examplePoint.toString(), "xCoordinate: -1\nyCoordinate: 1");

    StreamToPoint("-34 34");
    EXPECT_EQ(examplePoint.toString(), "xCoordinate: -34\nyCoordinate: 34");

    StreamToPoint("-32768 32768");
    EXPECT_EQ(examplePoint.toString(), "xCoordinate: -32768\nyCoordinate: 32768");

    StreamToPoint("-2147483648 2147483647");
    EXPECT_EQ(examplePoint.toString(), "xCoordinate: -2147483648\nyCoordinate: 2147483647");

    StreamToPoint("1 -1");
    EXPECT_EQ(examplePoint.toString(), "xCoordinate: 1\nyCoordinate: -1");

    StreamToPoint("34 -34");
    EXPECT_EQ(examplePoint.toString(), "xCoordinate: 34\nyCoordinate: -34");

    StreamToPoint("32768 -32768");
    EXPECT_EQ(examplePoint.toString(), "xCoordinate: 32768\nyCoordinate: -32768");

    StreamToPoint("2147483647 -2147483648");
    EXPECT_EQ(examplePoint.toString(), "xCoordinate: 2147483647\nyCoordinate: -2147483648");

    /* extra spaces */
    StreamToPoint("2147483647    -2147483648");
    EXPECT_EQ(examplePoint.toString(), "xCoordinate: 2147483647\nyCoordinate: -2147483648");
}

TEST_F(TestPointClass, invalidPoints) {

    std::string inputString;
    EXPECT_THROW(StreamToPoint(inputString), std::invalid_argument);
    try {
        StreamToPoint(inputString);
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid character");
    }

    inputString = "a 0";
    EXPECT_THROW(StreamToPoint(inputString), std::invalid_argument);
    try {
        StreamToPoint(inputString);
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid character");
    }

    inputString = "-1a 0";
    EXPECT_THROW(StreamToPoint(inputString), std::invalid_argument);
    try {
        StreamToPoint(inputString);
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid character");
    }

    inputString = "-12345a6 0";
    EXPECT_THROW(StreamToPoint(inputString), std::invalid_argument);
    try {
        StreamToPoint(inputString);
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid character");
    }

    inputString = "-2147483649 0";
    EXPECT_THROW(StreamToPoint(inputString), std::invalid_argument);
    try {
        StreamToPoint(inputString);
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "value too small");
    }

    inputString = "2147483648 0";
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

    inputString = "0 -12345a6";
    EXPECT_THROW(StreamToPoint(inputString), std::invalid_argument);
    try {
        StreamToPoint(inputString);
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid character");
    }

    inputString = "0 -2147483649";
    EXPECT_THROW(StreamToPoint(inputString), std::invalid_argument);
    try {
        StreamToPoint(inputString);
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "value too small");
    }

    inputString = "0 2147483648";
    EXPECT_THROW(StreamToPoint(inputString), std::invalid_argument);
    try {
        StreamToPoint(inputString);
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "value too large");
    }
}