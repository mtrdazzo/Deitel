/**
 * Exercise 9-11 Rectangle Class
 *
 * Create a class Rectangle with atttibutes length and width, each of which defaults to 1. Provide
 * member functions that calculate the perimeter and the area of the rectangle. Also, provide set
 * and get functions for the length and width attributes. The set functions should verify that length
 * and widtth are each floating-point numbers larger than 0.0 and less than 20.0.
 *
 */

#ifndef EX_9_11_H
#define EX_9_11_H

#include <iostream>

class Rectangle {

    public:

        Rectangle(float, float);
        Rectangle(float);
        Rectangle();
        ~Rectangle();

        float getWidth(void) const { return width; }
        float getLength(void) const { return length; }

        float perimeter(void) const;
        float area(void) const;

        void setWidth(float width);
        void setLength(float length);

    private:

        const float MAX_DIMENSION{20.0};
        const float MIN_DIMENSION{0.0};

        float width{1.0};
        float length{1.0};

};

#endif