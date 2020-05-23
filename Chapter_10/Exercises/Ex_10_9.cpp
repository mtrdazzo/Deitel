/**
 * @file Ex_10_9.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief HugeInteger method implementation
 * @version 0.1
 * @date 2020-05-23
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <cctype>
#include <Ex_10_9.h>

/**
 * @brief Construct a new HugeInteger object
 * 
 * @param value Integer value
 */
HugeInteger::HugeInteger(long value) {
    for (int decimal{digits - 1}; value != 0; --decimal) {
        integer[decimal] = value % 10;
        value /= 10;
    }
}

/**
 * @brief Construct a new HugeInteger object from an integer string.
 * 
 * @param number String of integers
 */
HugeInteger::HugeInteger(const std::string& number) {

    size_t length{number.size()};

    for (size_t decimal{digits - length}, k{0}; decimal < digits; ++decimal, ++k )
        if (std::isdigit(number[k]))
            integer[decimal] = number[k] - '0';
        else
        {
            throw std::invalid_argument("must be a string of digits");
        }
}

/**
 * @brief Sum of two HugeIntegers
 * 
 * @param other 
 * @return HugeInteger::HugeInteger 
 */
HugeInteger HugeInteger::operator+(const HugeInteger& other) const {

    HugeInteger temp;
    int carry{0};

    for (int decimal{digits - 1}; decimal >= 0; --decimal) {
        temp.integer[decimal] = carry + this->integer[decimal] + other.integer[decimal];

        if (temp.integer[decimal] > 9) {
            carry = 1;
            temp.integer[decimal] %= 10;
        }
        else {
            carry = 0;
        }
    }

    return temp;
}

/**
 * @brief Add an integer to a HugeInteger
 * 
 * @param other Integer
 * @return HugeInteger Sum of Integer and integer
 */
HugeInteger HugeInteger::operator+(int other) const {

    HugeInteger temp;
    int carry{0};

    for (int decimal{digits -1}; decimal >= 0; --decimal) {
        temp.integer[decimal] = carry + integer[decimal] + other % 10;
        other /= 10;

        if (temp.integer[decimal] > 9) {
            temp.integer[decimal] %= 10;
            carry = 1;
        }
        else {
            carry = 0;
        }
    }


    return temp;
}

/**
 * @brief Output integer value to output stream
 * 
 * @param output Output stream
 * @param hugeInt HugeInteger
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream& output, const HugeInteger& hugeInt) {

    bool firstZero{false};

    for (int decimal{0}; decimal < HugeInteger::digits; ++decimal) {

        if (firstZero)
            output << hugeInt.integer[decimal];
        else if (hugeInt.integer[decimal]) {
            firstZero = true;
            output << hugeInt.integer[decimal];
        }
        else if (decimal == HugeInteger::digits - 1) {
            output << hugeInt.integer[decimal];
        }
    }

    return output;
}