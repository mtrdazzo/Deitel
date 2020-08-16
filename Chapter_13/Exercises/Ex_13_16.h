/**
 * @file Ex_13_16.h
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Complex Class definition
 * @version 0.1
 * @date 2020-08-07
 * 
 * Exercise 13-16 Complex Class
 * 
 * Write a program that accomplishes each of the following:
 * 
 * a) Create a user-defined class Complex that contains the private integer data members real and imaginary
 *    and declares stream insertion and stream extraction overloaded operator functions as friends of the
 *    class.
 * 
 * b) Define the stream insertion and stream extraction operator functions. The stream extraction operator
 *    function should determine whether the data entered is valid, and, if not, it should set failbit to
 *    indicate improper input. The input should be of the form: 3 + 8i.
 * 
 * c) The values can be negative or positive, and it's possible that one of the two values is not provided,
 *    in which case the appropriate data member should be set to 0. The stream insertion operator should not
 *    be able to display the point if an input error occurred. For negative imaginary values, a minus sign
 *    should be printed rather than a plus sign.
 * 
 * d) Write a main function that tests input and output of user-defined class Complex, using the overloaded
 *    stream extraction and stream insertion operators.
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef EX_13_16_H
#define EX_13_16_H

#include <iostream>
#include <string>

constexpr int MAX_INPUT_SIZE{100};

class Complex {

    /* stream insertion and stream extraction operators */
    friend std::istream& operator>>(std::istream&, Complex &);
    friend std::ostream& operator<<(std::ostream&, const Complex &);

    public:

        /**
         * @brief Construct a new Complex object
         * 
         */
        Complex(int = 0, int = 0);

        /**
         * @brief Get the real part of the complex number
         * 
         * @return int 
         */
        int getReal() const { return real; }

        /**
         * @brief Set the real part of the complex number
         * 
         * @param real 
         */
        void setReal(int real) { this->real = real; }

        /**
         * @brief Get the Imaginary part of the complex number
         * 
         * @return int 
         */
        int getImaginary() const { return imaginary; }

        /**
         * @brief Set the imaginary part of the complex number
         * 
         * @param real 
         */
        void setImaginary(int imaginary) { this->imaginary = imaginary; }

        /**
         * @brief Return the string representation of the complex number
         * 
         * @return std::string 
         */
        std::string toString() const;

    private:
        int real;
        int imaginary;
};

#endif /* EX_13_16_H */