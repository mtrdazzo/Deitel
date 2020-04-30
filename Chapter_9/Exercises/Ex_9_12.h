/**
 * Exercise 9-12 Enhancing Class Rectangle
 *
 * Create a more sophisticated Rectangle class than the one you created in Exercise 9-11. This class
 * stores only the Cartesian coordinates of the four corners of the rectangle. The constructor calls
 * a set function that accepts four sets of coordinates and verifies that each of these is in the
 * first quadrant with no single x- or y- coordinate larger than 20.0. The set function also verifies
 * that the supplied coordinates do, in fact, specify a rectangle. Provide member functions that
 * calculate the length, width, perimeter, and area. The length is the larger of the two dimensions.
 * Include a predicate function square that determines whether the rectangle is a square.
 *
 */

#ifndef EX_9_12_H
#define EX_9_12_H

class Rectangle {

    public:

        static const int MIN_VALUE{0};
        static const int MAX_VALUE{20};

        struct Coordinate {
            float x;
            float y;
        };

        Rectangle(Coordinate, Coordinate, Coordinate, Coordinate);
        ~Rectangle();

        float area(void) const;
        float perimeter(void) const;
        float length(void) const;
        float width(void) const;
        void set(Coordinate, Coordinate, Coordinate, Coordinate);
        bool square(void){ return length() == width(); }

    private:

        Coordinate topLeft;
        Coordinate topRight;
        Coordinate bottomLeft;
        Coordinate bottomRight;

};

#endif