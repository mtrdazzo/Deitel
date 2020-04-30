/**
 * @file Ex_9_5.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Implementation for the Quadratic class. Includes logic for adding, subtracting,
 *        solving, and printing quadratic functions.
 * @version 0.1
 * @date 2020-04-08
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <Ex_9_5.h>
#include <sstream>
#include <math.h>

/**
 * @brief Construct a new Quadratic:: Quadratic object
 * 
 * @param a_in Second degree polynomial constant
 * @param b_in First degree polynomial constant
 * @param c_in Constant
 */
Quadratic::Quadratic(double a_in, double b_in, double c_in) :
    a{a_in}, b{b_in}, c{c_in}{
        if( a == 0.0 )
            a = 1.0;
    }

/**
 * @brief Construct a new Quadratic:: Quadratic object
 * 
 * @param a_in Second degree polynomial constant
 * @param b_in First degree polynomial constant
 */
Quadratic::Quadratic(double a_in, double b_in) : Quadratic(a_in, b_in, 0) {}

/**
 * @brief Construct a new Quadratic:: Quadratic object
 * 
 * @param a_in Second degree polynomial constant
 */
Quadratic::Quadratic(double a_in) : Quadratic(a_in, 0, 0) {}

/**
 * @brief Construct a new Quadratic:: Quadratic object
 * 
 */
Quadratic::Quadratic(void) : Quadratic(1, 0, 0) {}

/**
 * @brief Add the parameters of another Quadratic function.
 *
 * @param other Other quadratic object to sum to current object
 */
void Quadratic::add(Quadratic& other) {
    a += other.a;
    b += other.b;
    c += other.c;
}

/**
 * @brief Subtract the parameters of another Quadratic function.
 *
 * @param other Other quadratic object to sum to current object
 */
void Quadratic::subtract(Quadratic& other) {
    a -= other.a;
    b -= other.b;
    c -= other.c;
}

/**
 * @brief Add the parameters of another Quadratic function.
 *
 * @return A string representation of a quadratic equation in the form
 *         ax^2 + bx + c
 */
std::string Quadratic::toString(void) {

    std::ostringstream output;

    if (a != 0.0) {
        if (a == -1.0)
            output << "-";
        else if (a != 1.0)
            output << a;
        output << "x^2";
    }
    if (b != 0.0) {
        output << ((b > 0) ? " + " : " - ");
        if (std::abs(b) != 1.0)
            output << std::abs(b);
        output << "x";
    }
    if (c != 0.0) {
        output << ((c > 0) ? " + " : " - ");
        output << std::abs(c);
    }

    return output.str();
}

/**
 * @brief Solves the quadratic equation. Displays the solutions if (b^2 - 4ac)
 *        is greater than 0. Otherwise it displays "No Real Roots."
 */
std::string Quadratic::solve(void) {

    std::ostringstream output;
    double solution1{0.0};
    double solution2{0.0};

    if (b * b - 4 * a * c >= 0) {
        solution1 = (-1 * b + sqrt(b * b - 4 * a * c)) / (2 * a);
        solution2 = (-1 * b - sqrt(b * b - 4 * a * c)) / (2 * a);
    
        output << "Solution 1: " << solution1 << std::endl;
        output << "Solution 2: " << solution2 << std::endl;
    }
    else {
        output << "No Real Roots" << std::endl;
    }

    return output.str();
}