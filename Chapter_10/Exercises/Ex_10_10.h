/**
 * @file Ex_10_10.h
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Quadratic Class definition
 * 
 * Exercise 10-10 Enhanced Quadratic Class
 * 
 * Enhance the Quadratic Class of Exercise 9.5 by introducing three overloaded operators as follows:
 * 
 *   a) Addition (+): adds two Quadratic objects together.
 *   b) Subtraction (-): subtracts one Quadratic object from another
 *   c) Output operator (<<): displays a Quadratic equation in the form ax^2 + bx + c = 0.
 * 
 * Write a test program to demonstrate the capabilities of the enhanced Quadratic class.
 * 
 * @version 0.1
 * @date 2020-06-16
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <iostream>
#include <gtest/gtest_prod.h>

class Quadratic {

    friend std::ostream& operator<<(std::ostream&, const Quadratic &);
    FRIEND_TEST(QuadraticConstructor, DelegatedConstructor);

    public:

        /**
         * @brief Construct a new Quadratic object (Delegated constructors)
         * 
         */
        Quadratic() : Quadratic(0, 0, 0) {};
        Quadratic(int a) : Quadratic(a, 0, 0) {};
        Quadratic(int a, int b) : Quadratic(a, b, 0) {};
        Quadratic(int a, int b, int c) : m_iQuadratic{a}, m_iLinear{b}, m_iConstant{c} {};

        /**
         * @brief Add two Quadratic objects together
         * 
         * @return Quadratic
         */
        Quadratic operator+(const Quadratic &) const;

        /**
         * @brief Subtract one Quadratic object from another
         * 
         * @return Quadratic
         */
        Quadratic operator-(const Quadratic &) const;

    private:

        int m_iQuadratic{0}; /* ax^2 */
        int m_iLinear{0};    /* bx */
        int m_iConstant{0};  /* c */
};