#include <iostream>
#include <sstream>
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