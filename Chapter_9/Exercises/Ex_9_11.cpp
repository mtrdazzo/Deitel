#include <Ex_9_11.h>

/* Class Constructors */
Rectangle::Rectangle(float _length, float _width) {
    setLength(_length);
    setWidth(_width);
}

Rectangle::Rectangle(float _length) : Rectangle(_length, 1.0) {};
Rectangle::Rectangle(void): Rectangle(1.0, 1.0) {};

Rectangle::~Rectangle() {};

/**
 * @brief Calculate the perimeter of the rectangle
 * 
 * @return Perimeter of the rectangle
 */
float Rectangle::perimeter(void) const {
    return 2.0 * ( length + width );
}

/**
 * @brief Calculate the area of the rectangle
 * 
 * @return Area of the rectangle
 */
float Rectangle::area(void) const {
    return length * width;
}

/**
 * @brief Set the width of the rectangle
 * @param width new width of the rectangle
 */
void Rectangle::setWidth(float width) {
    if (width > MIN_DIMENSION && width < MAX_DIMENSION)
        this->width = width;
}

/**
 * @brief Set the length of the rectangle
 * @param length new length of the rectangle
 */
void Rectangle::setLength(float length) {
    if (length > MIN_DIMENSION && length < MAX_DIMENSION)
        this->length = length;
}