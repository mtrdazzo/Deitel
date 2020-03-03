#include <Ex_9_12.h>
#include <array>

/**
 * @brief Rectangle class constructor
 * @param c1 Top left coordinate of the rectangle
 * @param c2 Top right coordinate of the rectangle
 * @param c3 Bottom left coordinate of the rectangle
 * @param c4 Borrom right coordinate of the rectangle
 */
Rectangle::Rectangle(Coordinate c1, Coordinate c2, Coordinate c3, Coordinate c4) {

    if (c1.x > MIN_VALUE && c1.y < MAX_VALUE && c4.y > MIN_VALUE && c4.x < MAX_VALUE && \
        c1.y == c2.y && c1.x == c3.x && c2.x == c4.x && c3.y == c4.y \
        && c1.y - c3.y > 0 && c2.x - c1.x > 0)
            set(c1, c2, c3, c4);
    else {
        throw std::invalid_argument("not a valid rectangle");
    }
}

/**
 * @brief Rectangle class destructor
 */
Rectangle::~Rectangle(void) {};

/**
 * @brief Set the coordinates of the rectangle
 * @param c1 Top left coordinate of the rectangle
 * @param c2 Top right coordinate of the rectangle
 * @param c3 Bottom left coordinate of the rectangle
 * @param c4 Borrom right coordinate of the rectangle
 */
void Rectangle::set(Coordinate c1, Coordinate c2, Coordinate c3, Coordinate c4) {
    topLeft = c1;
    topRight = c2;
    bottomLeft = c3;
    bottomRight = c4;
}
/**
 * @brief Get the length (longer of the two axis)
 * @return length of the rectangle
 */
float Rectangle::length(void) const {

    return ((topRight.x - topLeft.x) >= (topLeft.y - bottomLeft.y)) ? topRight.x - topLeft.x : topLeft.y - bottomLeft.y;

}

/**
 * @brief Get the width (shorter of the two axis)
 * @return width of the rectangle
 */
float Rectangle::width(void) const {

    return ((topRight.x - topLeft.x) < (topLeft.y - bottomLeft.y)) ? topRight.x - topLeft.x : topLeft.y - bottomLeft.y;

}

/**
 * @brief Calculate the area of the rectangle
 * @return area of the rectangle
 */
float Rectangle::area(void) const {

    return (topRight.x - topLeft.x) * (topLeft.y - bottomLeft.y);

}

/**
 * @brief Calculate the perimeter of the rectangle
 * @return perimeter of the rectangle
 */
float Rectangle::perimeter(void) const {

    return 2 * ((topRight.x - topLeft.x) + (topLeft.y - bottomLeft.y));

}