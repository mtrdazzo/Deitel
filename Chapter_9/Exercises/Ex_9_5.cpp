/**
 * @file Ex_9_25.cpp
 *
 * @brief Implementation for the Quadratic class. Includes logic for adding, subtracting,
 *        solving, and printing quadratic functions.
 *
 * @author Matt Randazzo
 */

#include <Ex_9_5.h>
#include <sstream>
#include <math.h>

/**
 *  @brief Class Constructors (Delegated format)
 */
Quadratic::Quadratic(double a_in, double b_in, double c_in) :
    a{a_in}, b{b_in}, c{c_in}{
        if( a == 0 )
            a = 1;
    }

Quadratic::Quadratic(double a_in, double b_in) : Quadratic(a_in, b_in, 0) {}
Quadratic::Quadratic(double a_in) : Quadratic(a_in, 0, 0) {}
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
 *
 */
void Quadratic::solve(void) {

    double solution1{0.0};
    double solution2{0.0};

    if (b * b - 4 * a * c >= 0) {
        solution1 = (-1 * b + sqrt(b * b - 4 * a * c)) / (2 * a);
        solution2 = (-1 * b - sqrt(b * b - 4 * a * c)) / (2 * a);
    
        std::cout << "Solution 1: " << solution1 << std::endl;
        std::cout << "Solution 2: " << solution2 << std::endl;
    }
    else {
        std::cout << "No Real Roots" << std::endl;
    }
}