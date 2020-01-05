#include <iostream>
#include <sstream>
#include <math.h>
#include "Ex_9_5.h"

/**
 * Add the parameters of another Quadratic function.
 *
 * @param other   Other quadratic object to sum to current object
 * @return        void
 */
void Quadratic::add(Quadratic& other) {
    a += other.a;
    b += other.b;
    c += other.c;
}

/**
 * Subtract the parameters of another Quadratic function.
 *
 * @param other   Other quadratic object to sum to current object
 * @return        void
 */
void Quadratic::subtract(Quadratic& other) {
    a -= other.a;
    b -= other.b;
    c -= other.c;
}

/**
 * Add the parameters of another Quadratic function.
 *
 * @return A string representation of a quadratic equation in the form
 *         ax^2 + bx + c
 */
std::string Quadratic::toString(void) {

    std::ostringstream output;

    output << a << "x^2 + " << b << "x + " << c;

    return output.str();
}

/**
 * Solves the quadratic equation. Displays the solutions if (b^2 - 4ac) is greater
 * than 0. Otherwise it displays "No Real Roots."
 *
 * @return void
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