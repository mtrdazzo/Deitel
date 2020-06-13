/**
 * @file   Ex_10_9.h
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief  HugeInteger class interface
 * 
 * Exercise 10-9 HugeInteger class
 * 
 * A machine with 32-bit integers can represent integers in the range of approximately - 2 billion to + 2 billion. This
 * fixed-size restriction is rarely troublesome, but there are applications in which we would like to be able to use a
 * much wider range of integers. This is what c++ was built to do, create powerful new data types. Consider class
 * HugeInteger of Figs. 10.17-10.19, which is similar to the HugeInteger class in Exercise 9.14. Study the class
 * carefully, then respond to the following:
 * 
 * a) Descripe precisely how it operates
 *    - Converts either a long or an integer string into an array of integers with integers[digts-1] being the least
 *      significant digit
 * 
 * b) What restrictions does the class have?
 *    - Original implementation only enables positive integers
 *    - Digit overflow is no accounted for on most significant digit
 * 
 * c) Overload the * multiplication operator.
 * 
 * d) Overload the / division operator.
 * 
 * e) Overload all the relational and equality operators.
 * 
 * Note: There is no assignment operator or copy operator for the class HugeInteger, because the assingment operator and
 * copy operator provided by the compiler are capable of copying the entire array data member properly.
 * 
 * @version 0.1
 * @date 2020-05-23
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef EX_10_9_H
#define EX_10_9_H

#include <array>
#include <iostream>
#include <string>
#include <sstream>

class HugeInteger {

    friend std::ostream& operator<<(std::ostream&, const HugeInteger&);

    public:

        static const int digits{40}; // maximum digits in a HugeInteger

        HugeInteger(); // explicit default constructor
        HugeInteger(long); // conversion/default constructor
        HugeInteger(const std::string&); // conversion constructor

        HugeInteger& operator=(const HugeInteger &);

        HugeInteger& operator=(const int);

        /**
         * @brief Addition of two HugeIntegers
         * 
         * @return HugeInteger 
         */
        HugeInteger operator+(const HugeInteger&) const;

        /**
         * @brief Addition of HugeInteger and an integer
         * 
         * @return HugeInteger 
         */
        HugeInteger operator+(int) const;

        /**
         * @brief Addition of HugeInteger and an integer string
         * 
         * @return HugeInteger
         */
        HugeInteger operator+(const std::string &) const;

        /**
         * @brief Multiplication of HugeInteger and another HugeInteger
         * 
         * @return HugeInteger
         */
        HugeInteger operator*(const HugeInteger &) const;

        /**
         * @brief Multiplication of HugeInteger and integer
         * 
         * @return HugeInteger 
         */
        HugeInteger operator*(const int &) const;

        /**
         * @brief Multiplication of HugeInteger and string
         * 
         * @return HugeInteger 
         */
        HugeInteger operator*(const std::string &) const;

        /**
         * @brief Return the string representation of the HugeInteger
         * 
         * @return std::string 
         */
        std::string str() const;

    private:
        std::array<short, digits> integer{}; //defautl init to 0s

};

#endif