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
 * @brief Construct a new Polynomial:: Polynomial object
 * 
 * @param coefficients STL array of coefficients with indices representing polynomial order.
 */
Polynomial::Polynomial(POLYNOMIAL_ARRAY & coefficients) {
    m_aCoefficients = coefficients;
}
