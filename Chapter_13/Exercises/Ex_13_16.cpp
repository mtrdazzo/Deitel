/**
 * @file Ex_13_16.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Complex class method definitions
 * @version 0.1
 * @date 2020-08-07
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <limits>
#include <cmath>
#include <sstream>
#include "Ex_13_16.h"

/**
 * @brief Construct a new Complex:: Complex object
 * 
 * @param real real part of the complex number
 * @param imaginary imaginary part of the complex number
 */
Complex::Complex(int real, int imaginary) {
    setReal(real);
    setImaginary(imaginary);
}

/**
 * @brief Stream extraction operator for Complex object
 * 
 * @param input Input stream
 * @param complexNumber Complex object
 * @return std::istream& Input stream for cascading calls
 */
std::istream& operator>>(std::istream& input, Complex & complexNumber) {

    static char inputArray[MAX_INPUT_SIZE];

    bool isNegative{false};
    int index{0};
    long tempValue{0};

    input.getline(inputArray, MAX_INPUT_SIZE);

    if (inputArray[0] == '-') {
        isNegative = true;
        ++index;
    }

    for (int tempIndex{index}; isdigit(inputArray[tempIndex]); ++tempIndex, ++index) {
        tempValue = tempValue * 10 + inputArray[tempIndex] - '0';
    }

    if (isNegative)
        tempValue *= -1;

    /* store the real part of the number */
    if (tempValue < std::numeric_limits<int>::min())
        throw std::invalid_argument("value too small");
    else if (tempValue > std::numeric_limits<int>::max())
        throw std::invalid_argument("value too large");
    else
        complexNumber.setReal(static_cast<int>(tempValue));

    /* skip white space */
    if (input.gcount() > index)
        while (inputArray[index] == ' ' && input.gcount() > index)
            ++index;

    if (inputArray[index] == '+') {
        isNegative = false;
        ++index;
    }
    else if (inputArray[index] == '-') {
        isNegative = true;
        ++index;
    }
    else if (inputArray[index] == '\0') {
        complexNumber.setImaginary(0);
        return input;
    }
    else
        throw std::invalid_argument("invalid character");

    /* skip white space */
    if (input.gcount() > index)
        while (inputArray[index] == ' ' && input.gcount() > index)
            ++index;

    if (!isdigit(inputArray[index]))
        throw std::invalid_argument("invalid character");

    tempValue = 0;
    for (int tempIndex{index}; isdigit(inputArray[tempIndex]); ++tempIndex, ++index) {
        tempValue = tempValue * 10 + inputArray[tempIndex] - '0';
    }

    if (isNegative)
        tempValue *= -1;

    if (inputArray[index] == 'i')
        ++index;

    /* skip white space */
    if (input.gcount() > index)
        while (inputArray[index] == ' ' && input.gcount() > index)
            ++index;

    if (inputArray[index] != '\0')
        throw std::invalid_argument("invalid character");
    else if (tempValue < std::numeric_limits<int>::min())
        throw std::invalid_argument("value too small");
    else if (tempValue > std::numeric_limits<int>::max())
        throw std::invalid_argument("value too large");
    else
        complexNumber.setImaginary(static_cast<int>(tempValue));

    return input;
}

/**
 * @brief Stream insertion operator for Complex object
 * 
 * @param output Output stream
 * @param complexNumber Complex object
 * @return std::ostream& Output stream for cascading calls
 */
std::ostream& operator<<(std::ostream& output, const Complex & complexNumber) {
    return output << complexNumber.toString();
}

/**
 * @brief Represent the complex number as a string
 * 
 * @return std::string Complex number in the form 3 + 8i
 */
std::string Complex::toString() const {

    std::ostringstream output;

    if (real)
        output << real;
    if (imaginary < 0) {
        if (real)
            /* case to long to account for all negative numbers */
            output << " - " << std::abs(static_cast<long>(imaginary)) << "i";
        else
            output << imaginary << "i";
    }
    else if (imaginary > 0) {
        if (real)
            output << " + " << imaginary << "i";
        else
            output << imaginary << "i";
    }
    return output.str();
}