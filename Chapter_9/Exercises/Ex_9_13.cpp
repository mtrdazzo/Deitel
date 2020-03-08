#include <Ex_9_13.h>
#include <array>

Rectangle::Rectangle(Rectangle::Coordinate c1, Rectangle::Coordinate c2, Rectangle::Coordinate c3, Rectangle::Coordinate c4) {

    if (c1.x > MIN_VALUE && c1.y < MAX_VALUE && c4.y > MIN_VALUE && c4.x < MAX_VALUE && \
        c1.y == c2.y && c1.x == c3.x && c2.x == c4.x && c3.y == c4.y \
        && c1.y - c3.y > 0 && c2.x - c1.x > 0) {
            topLeft = c1;
            topRight = c2;
            bottomLeft = c3;
            bottomRight = c4;
        }
    else {
        throw std::invalid_argument("not a valid rectangle");
    }
}

Rectangle::~Rectangle(void) {};

/**
 * @brief Get the length (greater of the x/y dimensions) of the rectangle
 * @return Length of the rectangle
 */
float Rectangle::length(void) const {

    return (static_cast<float>(topRight.x - topLeft.x) >= static_cast<float>(topLeft.y - bottomLeft.y)) ? static_cast<float>(topRight.x - topLeft.x) : static_cast<float>(topLeft.y - bottomLeft.y);
}

/**
 * @brief Get the width (lesser of the x/y dimension) of the rectangle
 * @return Width of the rectangle
 */
float Rectangle::width(void) const {

    return (static_cast<float>(topRight.x - topLeft.x) < static_cast<float>(topLeft.y - bottomLeft.y)) ? static_cast<float>(topRight.x - topLeft.x) : static_cast<float>(topLeft.y - bottomLeft.y);
}

/**
 * @brief Calculate the area of the rectangle
 * @return Area of the rectangle
 */
float Rectangle::area(void) const {

    return static_cast<float>((topRight.x - topLeft.x)) * (topLeft.y - bottomLeft.y);
}

/**
 * @brief Calculate the perimeter of the rectangle
 * @return Perimeter of the rectangle
 */
float Rectangle::perimeter(void) const {

    return 2 * (static_cast<float>((topRight.x - topLeft.x)) + (topLeft.y - bottomLeft.y));
}

/**
 * @brief Set the perimeter character of the rectangle
 * @param c The perimeter character of the rectangle
 */
void Rectangle::setPerimeterCharacter(const char c) {
    perimeterCharacter = c;
}

/**
 * @brief Set the fill character of the rectangle
 * @param c The fill character of the rectangle
 */
void Rectangle::setFillCharacter(const char c) {
    fillCharacter = c;
}

/**
 * @brief Increase or decrease the scale of the area of the rectangle. If the area extends
 * beyond that of the MIN_VALUE or MAX_VALUE for either x/y dimension, the rectangle
 * will not be changed.
 * 
 * @param scale The multiplier to change the sides of the rectangle
 */
void Rectangle::setScale(const float scale) {

    int tmp_height = static_cast<int>(topRight.y - bottomRight.y) * scale + bottomRight.y;
    int tmp_width = static_cast<int>(topRight.x - topLeft.x) * scale + topLeft.x;

    if ( tmp_height < MAX_VALUE && tmp_height > bottomLeft.y && tmp_width > bottomLeft.x && tmp_height < MAX_VALUE) {
        topLeft.y = static_cast<int>((topLeft.y - bottomLeft.y)* scale + bottomLeft.y);
        topRight.x = static_cast<int>((topRight.x - topLeft.x) * scale + topLeft.x);
        topRight.y = static_cast<int>((topRight.y - bottomRight.y) * scale + bottomRight.y);
        bottomRight.x = static_cast<int>((bottomRight.x - bottomLeft.x) * scale + bottomLeft.x);
    }
}

/**
 * @brief Move the rectangle by a delta in the x-direction. If this is greater than
 * the MAX_VALUE or less than the MIN_VALUE, the entire rectangle will be shifted.
 * 
 * @param delta The number of spaces along the x-axis the rectangle will be shifted
 */
void Rectangle::moveX(const int delta) {
    if (topLeft.x + delta > MIN_VALUE && topRight.x + delta < MAX_VALUE) {
        topLeft.x += delta;
        bottomLeft.x += delta;
        topRight.x += delta;
        bottomRight.x += delta;
    }
}

/**
 * @brief Move the rectangle by a delta in the y-direction. If this is greater than
 * the MAX_VALUE or less than the MIN_VALUE, the entire rectangle will be shifted.
 * 
 * @param delta The number of spaces along the y-axis the rectangle will be shifted
 */
void Rectangle::moveY(const int delta) {
    if (bottomRight.y + delta > MIN_VALUE && topRight.y + delta < MAX_VALUE) {
        topLeft.y += delta;
        bottomLeft.y += delta;
        topRight.y += delta;
        bottomRight.y += delta;
    }
}

/**
 * @brief Draw the rectangle on the 2-D axis
 */
void Rectangle::drawRectangle(void) const {

    /* Top Padding */
    for (int topPadding{MAX_GRID - topLeft.y}; topPadding > 0; topPadding--)
        std::cout << '|' << '\n';

    /* Top Border */
    std::cout << '|';
    for (int leftPad{topLeft.x}; leftPad; leftPad--)
        std::cout << " ";
    for (int length{topRight.x - topLeft.x + 1}; length > 0; --length)
        std::cout << perimeterCharacter;
    std::cout << std::endl;

    /* Rectangle Body */
    if (topLeft.y - bottomLeft.y > 1) {

        int height{topLeft.y - bottomLeft.y - 1};

        while (height-- > 0) {

            /* Left Padding */
            std::cout << '|';
            for (int leftPad{topLeft.x}; leftPad; leftPad--)
                std::cout << " ";

            std::cout << perimeterCharacter;

            /* Filling */
            for (int length{topRight.x - topLeft.x -1}; length > 0; --length)
                std::cout << fillCharacter;

            std::cout << perimeterCharacter << std::endl;
        }
    }

    /* Bottom Border */
    std::cout << '|';
    for (int leftPad{topLeft.x}; leftPad; leftPad--)
        std::cout << " ";
    for (int length{bottomRight.x - bottomLeft.x + 1}; length; --length)
        std::cout << perimeterCharacter;
    std::cout << std::endl;

    /* Bottom Padding */
    for (int bottomPadding{bottomLeft.y-1}; bottomPadding > 0; bottomPadding--)
        std::cout << '|' << '\n';

    /* Bottom Axis */
    for (int counter{MAX_VALUE}; counter > 0; counter--)
        std::cout << '-';
    std::cout << std::endl;

}
