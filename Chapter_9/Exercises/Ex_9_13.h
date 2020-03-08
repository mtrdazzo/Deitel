/**
 * Exercise 9-13 Enhancing Class Rectangle
 *
 * Modify class Rectangle from Exercise 9.12 to include a draw function that displays the rectangle
 * inside a 25-by-25 box enclosing the portion of the first quadrant in which the rectangle resides.
 * Include a setFillCharacter funtion to speciy the character out of which the body of the rectangle
 * will be drawn. Include a setPerimeterCharacter function to specify the character that will be used
 * to draw the border of the rectangle. If you feel ambitious, you might include functions to scale
 * the size of the rectangle and move it around within the designated portion of the first quadrant.
 *
 */

#ifndef EX_9_13_H
#define EX_9_13_H

#include <iostream>

class Rectangle {

    public:

        static const uint8_t MIN_VALUE{0};
        static const uint8_t MAX_VALUE{20};

        struct Coordinate {
            int x;
            int y;
        };

        Rectangle(Coordinate, Coordinate, Coordinate, Coordinate);
        ~Rectangle();

        int getBottomVertex(void) const { return bottomLeft.y; }
        int getTopVertex(void) const { return topLeft.y; }
        int getLeftVertex(void) const { return topLeft.x; }
        int getRightVertex(void) const { return topRight.x; }

        float area(void) const;
        float perimeter(void) const;
        float length(void) const;
        float width(void) const;
        void drawRectangle(void) const;
        void setPerimeterCharacter(const char);
        void setFillCharacter(const char);
        void setScale(const float);
        void moveX(const int);
        void moveY(const int);
        bool square(void){ return length() == width(); }

    private:

        static const uint8_t MAX_GRID{20};

        char perimeterCharacter{'-'};
        char fillCharacter{'*'};
        Coordinate topLeft;
        Coordinate topRight;
        Coordinate bottomLeft;
        Coordinate bottomRight;
        float scale{1.0};

};

#endif