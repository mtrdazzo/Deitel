/**
 * Exercise 9-14 HugeInteger Class
 *
 * Create a class HugeInteger that uses a 40-element array of digits to store integers as large
 * as 40 digits each. Provide member functions input, output, isNotEqualTo, isGreaterThan,
 * isLessThan, isGreaterThanOrEqualTo, and is LessThanOrEqualTo - each of these is a "predicate"
 * function that simply returns true if the relationship between the two HugeIntegers and returns
 * false if the relationship does not hold. Also, provide a predicate function isZero. If you feel
 * ambitious, provide member functions multiply, divide, and remainder. In Chapter 10, you'll learn
 * how to overload input, output, arithmetic, equality, and rational operators so you can write
 * expressions containing HugeInteger objects, rather than explicitly calling member functions.
 *
 */

#ifndef EX_9_14_H
#define EX_9_14_H

#include <iostream>

class HugeInteger {

    public:

        HugeInteger(std::string digits);

        void input(const std::string);
        std::string output(void) const;

        bool isNotEqualTo(const HugeInteger &) const;
        bool isGreaterThan(const HugeInteger &) const;
        bool isLessThan(const HugeInteger &) const;
        bool isGreaterThanOrEqualTo(const HugeInteger &) const;
        bool isLessThanOrEqualTo(const HugeInteger &) const;
        bool isZero(void) const;

        void multiply(const HugeInteger &);
        void divide(const HugeInteger &);
        void remainder(const HugeInteger &);

        size_t getNumDigits(void) const { return numDigits; }

    private:

        void _storeDigits(const std::string &);
        uint8_t digits[40] = {0};
        size_t numDigits{0};
        static const size_t maxDigits{sizeof(digits) / sizeof(digits[0])};

};

#endif