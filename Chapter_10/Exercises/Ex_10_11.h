/**
 * @file Ex_10_11.h
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Polynomial Class definition
 * 
 * Exercise 10-11 Polynomial Class
 * 
 * Develop class Polynomial. The internal representation of a Polynomial is an array of
 * terms. Each term contains a coefficient and an exponent-e.g.the term 2x^4 has the coefficient
 * 2 and the exponent 4. Develop a complete class containing proper constructor and destructor
 * functions as well as set and get functions. The class houdl also provide the following
 * overloaded operator capabilities:
 * 
 *  a) Overload the addition operator (+) to add two Polynomials.
 *  b) Overload the subtraction operator (-) to subtract two Polynomials.
 *  c) Overload the assignment operator to assign one Polynomial to another.
 *  d) Overload the multiplication operator (*) to multiply two Polynomials.
 *  e) Overload the addition assignment operator (+=), subtraction assignment operator (-=), and
 *     multiplication assignment operator (*=).
 * 
 * @version 0.1
 * @date 2020-06-30
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <cstddef>
#include <array>

#define NUM_COFFICIENTS 40
typedef std::array<int, NUM_COFFICIENTS> POLYNOMIAL_ARRAY;

class Polynomial {

    public:

        /**
         * @brief Construct a new Polynomial object
         * 
         */
        Polynomial();

        /**
         * @brief Construct a new Polynomial object from polynomial array
         * 
         */
        Polynomial(POLYNOMIAL_ARRAY &);

        /**
         * @brief Destroy the Polynomial object
         * 
         */
        ~Polynomial() {};

        /**
         * @brief Assignment operator.
         * 
         * @return Polynomial 
         */
        void operator=(const Polynomial &);

        /**
         * @brief Addition operator.
         * 
         * @return Polynomial 
         */
        Polynomial operator+(const Polynomial &) const;

        /**
         * @brief Subtraction operator.
         * 
         * @return Polynomial 
         */
        Polynomial operator-(const Polynomial &) const;

        /**
         * @brief Multiplication operator.
         * 
         * @return Polynomial 
         */
        Polynomial operator*(const Polynomial &) const;

        /**
         * @brief Addition assignment operator.
         * 
         */
        void operator+=(const Polynomial &);

        /**
         * @brief Subtraction assignment operator.
         * 
         */
        void operator-=(const Polynomial &);

        /**
         * @brief Multiplication assignment operator.
         * 
         */
        void operator*=(const Polynomial &);

        /**
         * @brief Equality operator.
         * 
         * @return true 
         * @return false 
         */
        bool operator==(const Polynomial &) const;

        /**
         * @brief Get the coefficient C of the nth polynomial of the form C*x^n.
         * 
         * @return int 
         */
        int getCoefficient(size_t order) const { return m_aCoefficients.at(order); }

        /**
         * @brief Set the coefficient C of the nth polynomial of the form C*x^n.
         * 
         */
        void setCoefficient(size_t order, int coefficient) { m_aCoefficients.at(order) = coefficient; }

    private:

        POLYNOMIAL_ARRAY m_aCoefficients;
};