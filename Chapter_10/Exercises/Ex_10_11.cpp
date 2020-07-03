/**
 * @file Ex_10_11.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Polynomial class method definitions
 * @version 0.1
 * @date 2020-06-30
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "Ex_10_11.h"

/**
 * @brief Construct a new Polynomial:: Polynomial object with all coefficients as zero.
 * 
 */
Polynomial::Polynomial() {
    for (auto & order : m_aCoefficients)
        order = 0;
}

/**
 * @brief Construct a new Polynomial:: Polynomial object
 * 
 * @param coefficients STL array of coefficients with indices representing polynomial order.
 */
Polynomial::Polynomial(POLYNOMIAL_ARRAY & coefficients) {
    m_aCoefficients = coefficients;
}

/**
 * @brief Set coefficients of Polynomial from other polynomial.
 * 
 * @param other 
 */
void Polynomial::operator=(const Polynomial & other) {
    for (size_t order{0}; order < NUM_COFFICIENTS; ++order)
        m_aCoefficients.at(order) = other.getCoefficient(order);
}

/**
 * @brief Addition operator, returns the sum of the coefficients of the two Polynomial operands.
 * 
 * @param other Second Polynomial operand
 * @return Polynomial Sum of the two operands
 */
Polynomial Polynomial::operator+(const Polynomial & other) const {
    Polynomial sum;

    for (size_t order{0}; order < NUM_COFFICIENTS; ++order)
        sum.setCoefficient(order, this->getCoefficient(order) + other.getCoefficient(order));
    return sum;
}

/**
 * @brief Subtraction operator, retuns the difference of the coefficients of the two Polynomial operands.
 * 
 * @param other 
 * @return Polynomial Difference of the two operands
 */
Polynomial Polynomial::operator-(const Polynomial & other) const {
    Polynomial difference;

    for (size_t order{0}; order < NUM_COFFICIENTS; ++order)
        difference.setCoefficient(order, this->getCoefficient(order) - other.getCoefficient(order));
    
    return difference;
}

/**
 * @brief Addition assignment operator.
 * 
 * @param other 
 */
void Polynomial::operator+=(const Polynomial & other) {
    for (size_t order{0}; order < NUM_COFFICIENTS; ++order)
        m_aCoefficients[order] += other.getCoefficient(order);
}

/**
 * @brief Subtraction assignment operator
 * 
 * @param other 
 */
void Polynomial::operator-=(const Polynomial & other) {
    for (size_t order{0}; order < NUM_COFFICIENTS; ++order)
        m_aCoefficients[order] -= other.getCoefficient(order);
}

Polynomial Polynomial::operator*(const Polynomial & other) const {
    Polynomial product;
    size_t order3{0};

    for (size_t order1{0}; order1 < NUM_COFFICIENTS; ++order1) {
        for (size_t order2{0}; order2 < NUM_COFFICIENTS; ++order2) {
            if (order1 == 0 && order2 == 0)
                product.m_aCoefficients[0] = m_aCoefficients[order1] * other.m_aCoefficients[order2];
            else if (order1 == 0 && order2 != 0) {
                product.m_aCoefficients[order2] += m_aCoefficients[order1] * other.m_aCoefficients[order2];
            }
            else if (order1 != 0 && order1 == 0) {
                product.m_aCoefficients[order1] += m_aCoefficients[order1] * other.m_aCoefficients[order2];

            }
            else {
                order3 = order1 + order2;
                if (order3 < NUM_COFFICIENTS)
                    product.m_aCoefficients[order3] += m_aCoefficients[order1] * other.m_aCoefficients[order2];
            }
        }
    }
    return product;
}

/**
 * @brief Multiplication assignment operator
 * 
 * @param other 
 */
void Polynomial::operator*=(const Polynomial & other) {
    Polynomial product = *this * other;
    *this = other;
}

/**
 * @brief Equality operator
 * 
 * @param other 
 * @return true If all coefficients for all polynomials are equal
 * @return false 
 */
bool Polynomial::operator==(const Polynomial & other) const {
    for (size_t order{0}; order < NUM_COFFICIENTS; ++order)
        if (m_aCoefficients.at(order) != other.m_aCoefficients.at(order)) {
            return false;
        }
    return true;
}