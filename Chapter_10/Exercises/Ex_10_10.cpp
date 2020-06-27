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

/**
 * @brief Sum of two Quadratic objects.
 * 
 * @param other Quadratic object to be added
 * @return Quadratic Sum of two Quadratic objects 
 */
Quadratic Quadratic::operator+(const Quadratic & other) const {
    return Quadratic(this->m_iQuadratic + other.m_iQuadratic,
                     this->m_iLinear + other.m_iLinear,
                     this->m_iConstant + other.m_iLinear);
}

/**
 * @brief Difference of two Quadratic objects.
 * 
 * @param other Quadratic object to be subtracted
 * @return Quadratic Difference of two Quadratic objects
 */
Quadratic Quadratic::operator-(const Quadratic & other) const {
    return Quadratic(this->m_iQuadratic - other.m_iQuadratic,
                     this->m_iLinear + other.m_iLinear,
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

    if (equation.m_iQuadratic)
        output << equation.m_iQuadratic << "x^2";

    if (equation.m_iLinear) {
        if (equation.m_iLinear < 0)
            output << " - ";
        else if (equation.m_iLinear > 0)
            output << " + ";
        output << std::abs(equation.m_iLinear);
    }

    if (equation.m_iConstant) {
        if (equation.m_iConstant < 0)
            output << " - ";
        else if (equation.m_iConstant > 0)
            output << " + ";
        output << std::abs(equation.m_iConstant);
    }

    return output;
}