/**
 * @file Ex_10_10.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Quadratic class method definitions.
 * @version 0.1
 * @date 2020-06-27
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "Ex_10_10.h"
#include <sstream>

/**
 * @brief Sum of two Quadratic objects.
 * 
 * @param other Quadratic object to be added
 * @return Quadratic Sum of two Quadratic objects 
 */
Quadratic Quadratic::operator+(const Quadratic & other) const {
    return Quadratic(this->m_iQuadratic + other.m_iQuadratic,
                     this->m_iLinear + other.m_iLinear,
                     this->m_iConstant + other.m_iConstant);
}

/**
 * @brief Difference of two Quadratic objects.
 * 
 * @param other Quadratic object to be subtracted
 * @return Quadratic Difference of two Quadratic objects
 */
Quadratic Quadratic::operator-(const Quadratic & other) const {
    return Quadratic(this->m_iQuadratic - other.m_iQuadratic,
                     this->m_iLinear - other.m_iLinear,
                     this->m_iConstant - other.m_iConstant);
}

/**
 * @brief Output Quadratic object to stream in the form of ax^2 + bx + c = 0.
 * 
 * @param output Output stream
 * @param equation Quadratic object
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream& output, const Quadratic& equation) {

    bool hasQuadratic{false};
    bool hasLinear{false};

    if (equation.m_iQuadratic) {
        hasQuadratic = true;
        if (equation.m_iQuadratic < 0)
            output << "-";
        if (std::abs(equation.m_iQuadratic) > 1)
            output << std::abs(equation.m_iQuadratic);
        output << "x^2";
    }

    if (equation.m_iLinear) {
        hasLinear = true;
        if (hasQuadratic) {
            if (equation.m_iLinear < 0)
                output << " - ";
            else if (equation.m_iLinear > 0)
                output << " + ";
            if (std::abs(equation.m_iLinear) > 1)
                output << std::abs(equation.m_iLinear);
        }
        else {
            if (equation.m_iLinear == -1)
                output << '-';
            else if (equation.m_iLinear != 1)
                output << equation.m_iLinear;
        }
        output << "x";
    }

    if (equation.m_iConstant) {
        if (hasLinear) {
            if (equation.m_iConstant < 0)
                output << " - ";
            else if (equation.m_iConstant > 0)
                output << " + ";
            output << std::abs(equation.m_iConstant);
        }
        else {
            output << equation.m_iConstant;
        }
    }

    return output;
}

/**
 * @brief Output quadratic formula in the form ax^2 + bx + c as string.
 * 
 * @return std::string 
 */
std::string Quadratic::str() const {

    std::ostringstream output;

    output << *this;

    return output.str();
}