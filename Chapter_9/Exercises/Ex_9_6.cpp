/**
 * @file Ex_9_6.cpp
 *
 * @brief Implementation for the Rational class. Includes logic for adding, subtracting,
 *        solving, and printing Rational numbers.
 *
 * @author Matt Randazzo
 */

#include <Ex_9_6.h>
#include <sstream>

/**
 *  @brief Default Class Constructor
 */
Rational::Rational(int numer, int denom) :
    m_iNumerator{numer}, m_iDenominator{denom} {
        if (denom == 0)
            throw std::invalid_argument("denominator cannot be zero");
        if (m_iDenominator < 1) {
            m_iDenominator *= -1;
            m_iNumerator *= -1;
        }
        simplifyRational();
    };

/**
 * @brief Add two rational numbers together
 * 
 * @param other Rational number to be added to this object
 * @return Sum of two rational numbers
 */
Rational Rational::add(Rational &other) {

    if (other.m_iDenominator == 0)
        throw std::invalid_argument("denominator cannot be zero");

    int32_t iNumerator_tmp{m_iNumerator};
    int32_t iDenominator_tmp{m_iDenominator};

    iNumerator_tmp *= other.m_iDenominator;
    iNumerator_tmp += other.m_iNumerator * iDenominator_tmp;
    iDenominator_tmp *= other.m_iDenominator;

    return Rational(iNumerator_tmp, iDenominator_tmp);
}

/**
 * @brief Subtract one rational number from another.
 * 
 * @param other Rational number to be subtracted from this object
 * @return Difference of two rational numbers
 */
Rational Rational::subtract(Rational &other) {

    if (other.m_iDenominator == 0)
        throw std::invalid_argument("denominator cannot be zero");

    int32_t iNumerator_tmp{m_iNumerator};
    int32_t iDenominator_tmp{m_iDenominator};

    iNumerator_tmp *= other.m_iDenominator;
    iNumerator_tmp -= other.m_iNumerator * iDenominator_tmp;
    iDenominator_tmp *= other.m_iDenominator;

    return Rational(iNumerator_tmp, iDenominator_tmp);
}

/**
 * @brief Divide one rational number into another
 * 
 * @param other Rational number to be divided into this object
 * @return Quotient of two rational numbers
 */
Rational Rational::divide(Rational &other) {

    if (other.m_iNumerator == 0)
        throw std::invalid_argument("cannot divide by zero");

    int32_t iNumerator_tmp{m_iNumerator};
    int32_t iDenominator_tmp{m_iDenominator};

    iNumerator_tmp *= other.m_iDenominator;
    iDenominator_tmp *= other.m_iNumerator;

    if (iDenominator_tmp < 0) {
        iNumerator_tmp *= -1;
        iDenominator_tmp *= -1;
    }

    return Rational(iNumerator_tmp, iDenominator_tmp);
}

/**
 * @brief Simplify rational number by its greatest common divisor.
 */
void Rational::simplifyRational(void) {

    int32_t greatest_d;
    bool n_neg{false};

    if (m_iNumerator < 0) {
        n_neg = true;
        m_iNumerator *= -1;
    }

    /* Get lowest of the two */
    if ((greatest_d = gcd(m_iNumerator, m_iDenominator)) != 0) {
        m_iNumerator /= greatest_d;
        m_iDenominator /= greatest_d;
    }

    if (n_neg)
        m_iNumerator *= -1;

}

/**
 * @brief  Find the greatest common divisor between two integers.
 * 
 * @param a First integer
 * @param b Second integer
 * @return Greatest common divisor of the two integers
 */
int32_t Rational::gcd(int a, int b) {

    if (a == 0)
        return a;
    if (b == 0)
        return b;

    if (a == b)
        return a;

    if (a > b)
        return gcd(a-b, b);

    return gcd(a, b-a);
}

/**
 * @brief Multiply one rational number by another
 * 
 * @param other Rational number to be multiplied by this object
 * @return Product of two rational numbers
 */
Rational Rational::multiply(Rational &other) {

    if (other.m_iDenominator == 0)
        throw std::invalid_argument("cannot divide by zero");

    int32_t iNumerator_tmp{m_iNumerator};
    int32_t iDenominator_tmp{m_iDenominator};

    iNumerator_tmp *= other.m_iNumerator;
    iDenominator_tmp *= other.m_iDenominator;

    return Rational(iNumerator_tmp, iDenominator_tmp);
}

/**
 * @brief Produce the double representation of the rational number.
 * 
 * @return Double representation of the rational number
 */
double Rational::toDouble(void) {

    return static_cast<double>(m_iNumerator) / m_iDenominator;
}

/**
 * @brief Produce the string represenatation of the rational number.
 * 
 * @return Strings representation of the rational number
 */
std::string Rational::toRationalString(void) {

    std::ostringstream output;

    output << m_iNumerator;

    if (m_iNumerator && m_iDenominator != 1)
        output << "/" << m_iDenominator;

    return output.str();
}