/**
 * @file tst_Ex_22_15.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Test CommandLineArgsToInt
 * @version 0.1
 * @date 2020-12-30
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <gtest/gtest.h>
#include <iostream>
#include <cstdlib>
#include <cstdint>
#include <fstream>
#include <string>

#include "Ex_22_15.h"

class TestCommandLineArgsToInt : public testing::Test {

    protected:

        /**
         * @brief Write the command line args the temp file
         * 
         * @param args 
         */
        void WriteCommandLineArgs(std::string args) {

            if (in.is_open())
                in.close();
            
            out.open(fileName, std::ios::out);
            out << args;
            out.close();

            in.open(fileName, std::ios::in);
            std::cin.rdbuf(in.rdbuf());
        }

        /**
         * @brief Set random seed
         * 
         */
        void SetUp() {
            srand(static_cast<size_t>(time(nullptr)));
        }

        /**
         * @brief Remove tmp file and close streams
         * 
         */
        void TearDown() {
            out.close();
            in.close();
            remove(fileName);
        }

        /**
         * @brief Get the Random Integer
         * 
         * @return int Random integer
         */
        int GetRandomInteger(void) {
            return rand() % INTMAX_MAX + INTMAX_MIN;
        }

        int randInt;
        size_t numIterations{100};
        std::ofstream out; // output stream
        std::ifstream in;  // input stream
        const char * fileName{"file.tmp"}; // temporary file name

};

/**
 * @brief Write a zero integers as command line arguments
 * 
 */
TEST_F(TestCommandLineArgsToInt, ZeroIntegers) {

    WriteCommandLineArgs(std::string{""});
    EXPECT_EQ(CommandLineArgsToInt(), 0);
}

/**
 * @brief Write a single integer as a command line argument
 * 
 */
TEST_F(TestCommandLineArgsToInt, SingleInteger) {
    for (size_t i{0}; i < numIterations; ++i) {
        randInt = GetRandomInteger();
        WriteCommandLineArgs(std::to_string(randInt));
        EXPECT_EQ(CommandLineArgsToInt(), randInt);
    }
}

/**
 * @brief Write a random number of integers (2 - 4) as command line arguments
 * 
 */
TEST_F(TestCommandLineArgsToInt, MultipleIntegers) {
    size_t randNumInts;
    std::string randomString;
    int sum;

    for (size_t i{0}; i < numIterations; ++i) {
        sum = 0;
        randNumInts = rand() % 3 + 2;
        for (size_t num{0}; num < randNumInts; ++num) {
            // try not to overflow sum
            randInt = GetRandomInteger() / randNumInts; 
            sum += randInt;
            randomString += std::to_string(randInt);

            if (num + 1 < randNumInts)
                randomString += ' ';
        }
        WriteCommandLineArgs(randomString);
        EXPECT_EQ(CommandLineArgsToInt(), sum);
        randomString.erase();
    }
}

