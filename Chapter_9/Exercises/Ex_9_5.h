/**
 * Exercise 9-5 Quadratic Equations Class
 * 
 * Create a class called Quadratic for performing arithmetic on and solving quadratic
 * equations. A quadratic equation is an equation in the form
 * 
 *      ax + bx + c = 0
 * 
 * where a != 0. Use double variables to represent a, b, and c and provide a constructor that
 * enables objects of this class to be initialized when they are created. Give default values
 * of a = 1, b = 0, and c = 0. Create a char variable called variabled to represent the variable
 * used in the equation and give it a default value of x. The constructor should not allow the
 * value of a to be 0. If 0 is given, assign 1 to a. Provide public member functions that perform
 * the following tasks:
 * 
 *  a) add - adds two Quadratic equations by adding the corresponding values of a, b, and c. The
 *     The function takes another object of type Quadratic as its paramter and adds it to the calling
 *     object.
 * 
 *  b) subtract - subtracts two Quadratic equations by subtracting corresponding values of a, b, and c.
 *     The function takes another object of type Quadratic as its paramter and subtracts it from the
 *     calling object.
 * 
 *  c) toString - returns a string representation of a quadratic equation in the form ax^2 + bx + c = 0
 *     and using actual values of the data members.
 * 
 *  d) solve - solves a quadratic equation and displays the solutions if (b^2 - 4ac) is greater than 0.
 *     Otherwise, it displays "No Real Roots".
 * 
 *   Write a driver program to test the functionality of the Quadratic class.
 * 
 */

#ifndef EX_9_5_H
#define EX_9_5_H

#include <iostream>

class Quadratic {

    public:

        /* Function prototypes */
        void add(Quadratic&);
        void subtract(Quadratic&);
        std::string toString(void);
        void solve(void);
    
    private:

        double a;
        double b;
        double c;
        char variable;

};

#endif