/**
 * @file tst_Ex_13_18.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Testing next character in stream input when using getline and get
 * @version 0.1
 * @date 2020-08-15
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <fstream>
#include <string>
#include <gtest/gtest.h>
#include <Ex_13_18.h>

class TestGetCharactersFromGet : public testing::Test {

    protected:

        void StreamToGet(std::string numberStr) {
            outputFile.open(fileName);
            outputFile << numberStr;
            outputFile.close();

            inputFile.open(fileName);
            inputFile >> example;
        }

        void TearDown() {
            inputFile.close();
            std::remove(fileName);
        }

        std::ifstream inputFile;
        std::ofstream outputFile;
        const char * fileName{"testFile.txt"};
        GetCharactersFromGet example;
};

class TestGetCharactersFromGetline : public testing::Test {

    protected:

        void StreamToGetline(std::string numberStr) {
            outputFile.open(fileName);
            outputFile << numberStr;
            outputFile.close();

            inputFile.open(fileName);
            inputFile >> example;
        }

        void TearDown() {
            inputFile.close();
            std::remove(fileName);
        }

        std::ifstream inputFile;
        std::ofstream outputFile;
        const char * fileName{"testFile.txt"};
        GetCharactersFromGetline example;
};

/**
 * @brief Test for next character on file stream
 * 
 */
TEST_F(TestGetCharactersFromGet, peekNextChar) {

    std::string inputString{"hello there\n blah"};
    StreamToGet(inputString);

    /* verify example extracts all characters up to newline */
    EXPECT_EQ("hello there", example.toString());

    /* verify newline character is still on the stream */
    EXPECT_EQ('\n', inputFile.peek());

    /* get newline character */
    inputFile.get();

    /* verify remaining characters still remain in the stream */
    inputFile >> example;
    EXPECT_EQ(" blah", example.toString());
}

/**
 * @brief Test for next character on file stream
 * 
 */
TEST_F(TestGetCharactersFromGetline, peekNextChar) {

    std::string inputString{"hello there\n blah"};
    StreamToGetline(inputString);

    /* verify example extracts all characters up to newline */
    EXPECT_EQ("hello there", example.toString());

    /* verify newline character is not on the stream */
    EXPECT_EQ(' ', inputFile.peek());

    /* verify remaining characters still remain in the stream */
    inputFile >> example;
    EXPECT_EQ(" blah", example.toString());
}