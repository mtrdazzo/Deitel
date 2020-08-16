/**
 * @file tst_Ex_13_14.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Test the extraction stream operator of the PhoneNumber class
 * @version 0.1
 * @date 2020-08-01
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <sstream>
#include <fstream>
#include <gtest/gtest.h>
#include <Ex_13_14.h>

class TestPhoneNumber : public testing::Test {

    protected:

        void InputPhoneNumber(const std::string &phoneNumber) {
            outputStream.open(testFileName);
            outputStream << phoneNumber;
            outputStream.close();

            inputStream.open(testFileName);
            try {
                inputStream >> sampleNumber;
            } catch(std::invalid_argument & err) {
                inputStream.close();
                throw;
            }
        }

        void TearDown() {
            inputStream.close();
            std::remove(testFileName);
        }
        const char *testFileName{"testFile.txt"};
        std::ifstream inputStream;
        std::ofstream outputStream;
        PhoneNumber sampleNumber;
};

TEST_F(TestPhoneNumber, NumberFormat) {

    std::string samplePhoneNumber{"213-456-7890"};
    EXPECT_THROW(InputPhoneNumber(samplePhoneNumber), std::invalid_argument);
    try {
        InputPhoneNumber(samplePhoneNumber);
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "Missing '(', must enter phone number in the format: (###) ###-####");
    }

    samplePhoneNumber = "(213-456-7890";
    EXPECT_THROW(InputPhoneNumber(samplePhoneNumber), std::invalid_argument);
    try {
        InputPhoneNumber(samplePhoneNumber);
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "Missing ')', must enter phone number in the format: (###) ###-####");
    }

    samplePhoneNumber = "(213)-456-7890";
    EXPECT_THROW(InputPhoneNumber(samplePhoneNumber), std::invalid_argument);
    try {
        InputPhoneNumber(samplePhoneNumber);
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "Missing ' ', must enter phone number in the format: (###) ###-####");
    }

    samplePhoneNumber = "(213)  456-7890";
    EXPECT_THROW(InputPhoneNumber(samplePhoneNumber), std::invalid_argument);
    try {
        InputPhoneNumber(samplePhoneNumber);
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "Invalid symbol, must enter phone number in the format: (###) ###-####");
    }

    samplePhoneNumber = "(21e) 436-7890";
    EXPECT_THROW(InputPhoneNumber(samplePhoneNumber), std::invalid_argument);
    try {
        InputPhoneNumber(samplePhoneNumber);
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "Invalid symbol, must enter phone number in the format: (###) ###-####");
    }

    samplePhoneNumber = "(213) 4e6-7890";
    EXPECT_THROW(InputPhoneNumber(samplePhoneNumber), std::invalid_argument);
    try {
        InputPhoneNumber(samplePhoneNumber);
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "Invalid symbol, must enter phone number in the format: (###) ###-####");
    }

    samplePhoneNumber = "(213) 456 7890";
    EXPECT_THROW(InputPhoneNumber(samplePhoneNumber), std::invalid_argument);
    try {
        InputPhoneNumber(samplePhoneNumber);
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "Missing '-', must enter phone number in the format: (###) ###-####");
    }

    samplePhoneNumber = "(213) 456-78f0";
    EXPECT_THROW(InputPhoneNumber(samplePhoneNumber), std::invalid_argument);
    try {
        InputPhoneNumber(samplePhoneNumber);
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "Invalid symbol, must enter phone number in the format: (###) ###-####");
    }

    samplePhoneNumber = "(213) 456-78990";
    EXPECT_THROW(InputPhoneNumber(samplePhoneNumber), std::invalid_argument);
    try {
        InputPhoneNumber(samplePhoneNumber);
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "Invalid phone number length, must enter phone number in the format: (###) ###-####");
    }

    samplePhoneNumber = "(913) 456-7890";
    InputPhoneNumber(samplePhoneNumber);
}

TEST_F(TestPhoneNumber, NumberContents) {

    std::string samplePhoneNumber{"(113) 456-7890"};
    EXPECT_THROW(InputPhoneNumber(samplePhoneNumber), std::invalid_argument);
    try {
        InputPhoneNumber(samplePhoneNumber);
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "Invalid area code, cannot begin with 0 or 1");
    }

    samplePhoneNumber = "(013) 456-7890";
    EXPECT_THROW(InputPhoneNumber(samplePhoneNumber), std::invalid_argument);
    try {
        InputPhoneNumber(samplePhoneNumber);
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "Invalid area code, cannot begin with 0 or 1");
    }

    samplePhoneNumber = "(223) 456-7890";
    EXPECT_THROW(InputPhoneNumber(samplePhoneNumber), std::invalid_argument);
    try {
        InputPhoneNumber(samplePhoneNumber);
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "Invalid area code, must be a 0 or 1");
    }

    samplePhoneNumber = "(903) 456-7890";
    InputPhoneNumber(samplePhoneNumber);
}