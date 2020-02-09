/**
 * @file Ex_9_5.h
 * 
 * @brief Interface to the Rational to represent a rational number made of a numerator and a denominator.
 *        The class also includes methods for arithemetic including addition, subtraction, multiplication,
 *        and division.
 * 
 * @mainpage Exercise 9-6
 *
 * Create a class called Rational for performing arithmetic with fractions. Write a program to test your
 * class. Use integer variables to represent the private data of the class - the numerator and the
 * denominator. Provide a constructor that enbales an object of this class to be initialized when it's
 * declared. The constructor shuold contain default values in case no initializers are provided and should
 * store the fraction in the reduced form. For example, the fraction 2/4 would be store in the object as
 * 1 as the numerator and 2 as the denominator. Provide public member functions that perform each of the
 * following tasks:
 *
 * a) add - Adds two rational numbers. The result should be stored in reduced form.
 * b) subtract - Subtracts two rational numbers. The result should be stored in reduced form.
 * c) multiply - Multiplies two rational numbers. The result should be store in reduced form.
 * d) divide - Divides two rational numbers. The result should be store in reduced form.
 * e) toRationalString - Returns a string representation of a Rational number in the form a/b, where a is the
 *    numerator and b is the denominator.
 * f) toDouble - Returns the Rational number as a double.
 *
 * @author Matt Randazzo
 */

#ifndef EX_9_6_H
#define EX_9_6_H

#include <iostream>

class Rational {

    public:

        /* Default constructor */
        explicit Rational(int, int);

        /* Function Prototypes */
        Rational add(Rational &);
        Rational subtract(Rational &);
        Rational multiply(Rational &);
        Rational divide(Rational &);
        std::string toRationalString(void);
        double toDouble(void);

        int32_t getNumerator(void) const { return m_iNumerator; }
        int32_t getDenominator(void) const { return m_iDenominator; }

    private:

        int32_t gcd(int, int);
        void simplifyRational(void);

        int32_t m_iNumerator;
        int32_t m_iDenominator;

};

#endif