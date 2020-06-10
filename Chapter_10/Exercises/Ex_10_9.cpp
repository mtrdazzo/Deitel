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
 * @brief Construct a new Huge Integer:: Huge Integer object
 * 
 */
HugeInteger::HugeInteger() {
    for (size_t tens{0}; tens < digits; tens++)
        integer[tens] = 0;
}

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
 * @brief Return the string representation of the HugeInteger
 * 
 * @return std::string 
 */
std::string HugeInteger::str() const {

    std::ostringstream output;

    output << *this;

    return output.str();
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
 * @return HugeInteger
 */
HugeInteger HugeInteger::operator+(int other) const {
    return *this + HugeInteger(other);
}

/**
 * @brief Add an intger string to a HugeInteger
 * 
 * @param other integer string
 * @return HugeInteger 
 */
HugeInteger HugeInteger::operator+(const std::string& other) const {
    return *this + HugeInteger(other);
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

/**
 * @brief Multiply two HugeIntegers together.
 * 
 * @param other
 * @return HugeInteger
 */
HugeInteger HugeInteger::operator*(const HugeInteger & other) const {

    HugeInteger tmp;
    int carry{0};
    int current_index{0};

    for (int decimal_this{digits-1}; decimal_this >= 0; --decimal_this) {

        for (int decimal_other{digits-1}; decimal_other >= 0; --decimal_other) {

            current_index = decimal_other - (digits - (decimal_this + 1));

            tmp.integer[current_index] += integer[decimal_this] * other.integer[decimal_other] + carry;

            if (tmp.integer[current_index] > 9) {
                carry = tmp.integer[current_index] / 10;
                tmp.integer[current_index] %= 10;
            }
            else {
                carry = 0;
            }
        }
    }

    return tmp;
}

/**
 * @brief Multiply HugeInteger and integer.
 * 
 * @param other Other
 * @return HugeInteger
 */
HugeInteger HugeInteger::operator*(const int & other) const {

    return *this * HugeInteger(other);
}

/**
 * @brief Multiply HugeInteger and integer.
 * 
 * @param other Other
 * @return HugeInteger
 */
HugeInteger HugeInteger::operator*(const std::string & other) const {

    return *this * HugeInteger(other);
}

HugeInteger & HugeInteger::operator=(const HugeInteger & other) {
    for (int8_t tens{0}; tens < digits; ++tens)
        this->integer[tens] = other.integer[tens];
    return *this;
}
