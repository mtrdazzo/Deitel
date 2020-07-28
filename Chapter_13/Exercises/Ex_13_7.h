/**
 * @file Ex_13_7.h
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Function prototypes for inputting integer values in decimal, octal, and hexadecimal formats.
 * @version 0.1
 * @date 2020-07-27
 * 
 * Exercise 13-7 Inputting Decimal, Octal and Hexadecimal Values
 * 
 * Write a program to test the inputting of integer values in decimal, octal and hexadecimal formats. Output each integer
 * read by the program in all three formats. Test the program with the following input data: 10, 010, 0x10.
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <iostream>
#include <string>

#define INPUT_MAX_LEN 11

class Number {

    friend std::ostream& operator<<(std::ostream&, const Number &);
    friend std::istream& operator>>(std::istream&, Number &);

    public:

        Number() = default;

        /**
         * @brief Get the Value object
         * 
         * @return int 
         */
        int getValue() const;

    private:

        /**
         * @brief Convert hexadecimal representation to decimal
         * 
         */
        void hexToDec(const char *);

        /**
         * @brief Convert octal representation to decimal
         * 
         */
        void octToDec(const char *);

        /**
         * @brief Convert string representation to decimal
         * 
         */
        void stringToDec(const char *);

        uint32_t value{0};

};