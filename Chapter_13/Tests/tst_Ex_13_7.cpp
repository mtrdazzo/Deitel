/**
 * @file tst_Ex_13_7.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2020-07-27
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <gtest/gtest.h>
#include <Ex_13_7.h>
#include <fstream>

class NumberClass : public ::testing::Test {

    protected:

        void SetUp(const std::string & input) {

            /* open file, write to file */
            outFile.open(fileName);
            outFile << input;
            outFile.close();

            /* open file, write to Number object */
            inFile.open(fileName);
            inFile >> testNum;
        }

        void TearDown() {
            inFile.close();
            std::remove(fileName);
        }

        const char *fileName{"tempFile.txt"};
        std::ofstream outFile;
        std::ifstream inFile;
        std::string tempStr;
        Number testNum;
};

/**
 * @brief Test hex representations
 * 
 */
TEST_F(NumberClass, HexValues) {

    SetUp("0xFF");
    EXPECT_EQ(testNum.getValue(), 255);
    inFile.close();

    SetUp("0xfe");
    EXPECT_EQ(testNum.getValue(), 254);
    inFile.close();

    SetUp("0xfD");
    EXPECT_EQ(testNum.getValue(), 253);
    inFile.close();

    SetUp("0x00");
    EXPECT_EQ(testNum.getValue(), 0);
    inFile.close();

    SetUp("0x01");
    EXPECT_EQ(testNum.getValue(), 1);
    inFile.close();

    SetUp("0x1");
    EXPECT_EQ(testNum.getValue(), 1);
    inFile.close();

    SetUp("0xabcdef");
    EXPECT_EQ(testNum.getValue(), 11259375);
    inFile.close();

    SetUp("0x00000001");
    EXPECT_EQ(testNum.getValue(), 1);
    inFile.close();

    SetUp("0xffffffff");
    EXPECT_EQ(static_cast<uint32_t>(testNum.getValue()), 4294967295u);
    inFile.close();

    try {
        SetUp("0x0g");
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid hex character");
    }

    try {
        SetUp("0xg0");
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid hex character");
    }

    try {
        SetUp("0x01234567g");
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid hex character");
    }
}

/**
 * @brief Test octal representations
 * 
 */
TEST_F(NumberClass, OctalValues) {

    SetUp("01");
    EXPECT_EQ(testNum.getValue(), 1);
    inFile.close();

    SetUp("00");
    EXPECT_EQ(testNum.getValue(), 0);
    inFile.close();

    SetUp("0000000000");
    EXPECT_EQ(testNum.getValue(), 0);
    inFile.close();


    SetUp("0000000001");
    EXPECT_EQ(testNum.getValue(), 1);
    inFile.close();

    SetUp("011");
    EXPECT_EQ(testNum.getValue(), 9);
    inFile.close();

    SetUp("0377777777");
    EXPECT_EQ(static_cast<uint32_t>(testNum.getValue()), 67108863u);
    inFile.close();

    try {
        SetUp("0200F00001");
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid octal character");
    }

    try {
        SetUp("000000000FF");
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid octal character");
    }

    try {
        SetUp("000000000h");
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid octal character");
    }
}

