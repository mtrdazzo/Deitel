#include <Ex_9_12.h>
#include <cstdlib>
#include <gtest/gtest.h>

/**
 * @brief Get a random float
 */
float getRandomNumber(void) {
    return Rectangle::MIN_VALUE + static_cast<float>(rand())/static_cast<float>(RAND_MAX/ Rectangle::MAX_VALUE);
}

/**
 * @brief Create a rectangle using four randomly chosen floats
 */
TEST(Constructor, ValidRectangle) {

    float x1 = getRandomNumber();
    float x2 = getRandomNumber();
    float y1 = getRandomNumber();
    float y2 = getRandomNumber();

    if (x1 > x2) {
        float tmp = x2;
        x2 = x1;
        x1 = tmp;
    }


    if (y1 > y2) {
        float tmp = y2;
        y2 = y1;
        y1 = tmp;
    }

    Rectangle::Coordinate c1{x1, y2};
    Rectangle::Coordinate c2{x2, y2};
    Rectangle::Coordinate c3{x1, y1};
    Rectangle::Coordinate c4{x2, y1};

    Rectangle rect1{c1, c2, c3, c4};

}

/**
 * @brief Create a rectangle with an invalid left vertex
 */
TEST(Constructor, InvalidLeftVertex) {

    float x1 = getRandomNumber();
    float x2 = getRandomNumber();
    float y1 = getRandomNumber();
    float y2 = getRandomNumber();

    if (x1 > x2) {
        float tmp = x2;
        x2 = x1;
        x1 = tmp;
    }


    if (y1 > y2) {
        float tmp = y2;
        y2 = y1;
        y1 = tmp;
    }

    Rectangle::Coordinate c1{x1 + static_cast<float>(0.1), y2};
    Rectangle::Coordinate c2{x2, y2};
    Rectangle::Coordinate c3{x1, y1};
    Rectangle::Coordinate c4{x2, y1};

    try {
        Rectangle rect1{c1, c2, c3, c4};
    }
    catch (std::invalid_argument const & err) {
        EXPECT_STRCASEEQ(err.what(), "not a valid rectangle");
    }
}

/**
 * @brief Create a rectangle with an invalid top vertex
 */
TEST(Constructor, InvalidTopVertex) {

    float x1 = getRandomNumber();
    float x2 = getRandomNumber();
    float y1 = getRandomNumber();
    float y2 = getRandomNumber();

    if (x1 > x2) {
        float tmp = x2;
        x2 = x1;
        x1 = tmp;
    }


    if (y1 > y2) {
        float tmp = y2;
        y2 = y1;
        y1 = tmp;
    }

    Rectangle::Coordinate c1{x1, y2};
    Rectangle::Coordinate c2{x2, y2 + static_cast<float>(0.1)};
    Rectangle::Coordinate c3{x1, y1};
    Rectangle::Coordinate c4{x2, y1};

    try {
        Rectangle rect1{c1, c2, c3, c4};
    }
    catch (std::invalid_argument const & err) {
        EXPECT_STRCASEEQ(err.what(), "not a valid rectangle");
    }
}

/**
 * @brief Create a rectangle with an invalid right vertex
 */
TEST(Constructor, InvalidRightVertex) {

    float x1 = getRandomNumber();
    float x2 = getRandomNumber();
    float y1 = getRandomNumber();
    float y2 = getRandomNumber();

    if (x1 > x2) {
        float tmp = x2;
        x2 = x1;
        x1 = tmp;
    }


    if (y1 > y2) {
        float tmp = y2;
        y2 = y1;
        y1 = tmp;
    }

    Rectangle::Coordinate c1{x1, y2};
    Rectangle::Coordinate c2{x2, y2};
    Rectangle::Coordinate c3{x1, y1};
    Rectangle::Coordinate c4{x2 + static_cast<float>(0.1), y1};

    try {
        Rectangle rect1{c1, c2, c3, c4};
    }
    catch (std::invalid_argument const & err) {
        EXPECT_STRCASEEQ(err.what(), "not a valid rectangle");
    }
}

/**
 * @brief Create a rectangle with an invalid bottom vertex
 */
TEST(Constructor, InvalidBottomVertex) {

    float x1 = getRandomNumber();
    float x2 = getRandomNumber();
    float y1 = getRandomNumber();
    float y2 = getRandomNumber();

    if (x1 > x2) {
        float tmp = x2;
        x2 = x1;
        x1 = tmp;
    }


    if (y1 > y2) {
        float tmp = y2;
        y2 = y1;
        y1 = tmp;
    }

    Rectangle::Coordinate c1{x1, y2};
    Rectangle::Coordinate c2{x2, y2};
    Rectangle::Coordinate c3{x1, y1};
    Rectangle::Coordinate c4{x2, y1 + static_cast<float>(0.1)};

    try {
        Rectangle rect1{c1, c2, c3, c4};
    }
    catch (std::invalid_argument const & err) {
        EXPECT_STRCASEEQ(err.what(), "not a valid rectangle");
    }
}

/**
 * @brief Create a rectangle with an invalid minimum x-coordinate
 */
TEST(Constructor, InvalidMinimumX) {

    float x1 = getRandomNumber();
    float x2 = getRandomNumber();
    float y1 = getRandomNumber();
    float y2 = getRandomNumber();

    if (x1 > x2) {
        float tmp = x2;
        x2 = x1;
        x1 = tmp;
    }


    if (y1 > y2) {
        float tmp = y2;
        y2 = y1;
        y1 = tmp;
    }

    Rectangle::Coordinate c1{0.0, y2};
    Rectangle::Coordinate c2{x2, y2};
    Rectangle::Coordinate c3{x1, y1};
    Rectangle::Coordinate c4{x2, y1};

    try {
        Rectangle rect1{c1, c2, c3, c4};
    }
    catch (std::invalid_argument const & err) {
        EXPECT_STRCASEEQ(err.what(), "not a valid rectangle");
    }
}

/**
 * @brief Create a rectangle with an invalid minimum y-coordinate
 */
TEST(Constructor, InvalidMinimumY) {

    float x1 = getRandomNumber();
    float x2 = getRandomNumber();
    float y1 = getRandomNumber();
    float y2 = getRandomNumber();

    if (x1 > x2) {
        float tmp = x2;
        x2 = x1;
        x1 = tmp;
    }


    if (y1 > y2) {
        float tmp = y2;
        y2 = y1;
        y1 = tmp;
    }

    Rectangle::Coordinate c1{x1, y2};
    Rectangle::Coordinate c2{x2, y2};
    Rectangle::Coordinate c3{x1, 0.0};
    Rectangle::Coordinate c4{x2, y1};

    try {
        Rectangle rect1{c1, c2, c3, c4};
    }
    catch (std::invalid_argument const & err) {
        EXPECT_STRCASEEQ(err.what(), "not a valid rectangle");
    }
}

/**
 * @brief Create a rectangle with an invalid maximum x-coordinate
 */
TEST(Constructor, InvalidMaximumX) {

    float x1 = getRandomNumber();
    float x2 = getRandomNumber();
    float y1 = getRandomNumber();
    float y2 = getRandomNumber();

    if (x1 > x2) {
        float tmp = x2;
        x2 = x1;
        x1 = tmp;
    }


    if (y1 > y2) {
        float tmp = y2;
        y2 = y1;
        y1 = tmp;
    }

    Rectangle::Coordinate c1{x1, y2};
    Rectangle::Coordinate c2{20.0, y2};
    Rectangle::Coordinate c3{x1, y1};
    Rectangle::Coordinate c4{x2, y1};


    try {
        Rectangle rect1{c1, c2, c3, c4};
    }
    catch (std::invalid_argument const & err) {
        EXPECT_STRCASEEQ(err.what(), "not a valid rectangle");
    }
}

/**
 * @brief Create a rectangle with an invalid maximum y-coordinate
 */
TEST(Constructor, InvalidMaximumY) {

    float x1 = getRandomNumber();
    float x2 = getRandomNumber();
    float y1 = getRandomNumber();
    float y2 = getRandomNumber();

    if (x1 > x2) {
        float tmp = x2;
        x2 = x1;
        x1 = tmp;
    }


    if (y1 > y2) {
        float tmp = y2;
        y2 = y1;
        y1 = tmp;
    }

    Rectangle::Coordinate c1{x1, y2};
    Rectangle::Coordinate c2{x2, y2};
    Rectangle::Coordinate c3{x1, 20.0};
    Rectangle::Coordinate c4{x2, y1};

    try {
        Rectangle rect1{c1, c2, c3, c4};
    }
    catch (std::invalid_argument const & err) {
        EXPECT_STRCASEEQ(err.what(), "not a valid rectangle");
    }
}

/**
 * @brief Find the length of the rectangle in the x-direction
 */
TEST(Length, FindLengthX) {

    Rectangle::Coordinate c1{1, 5};
    Rectangle::Coordinate c2{6, 5};
    Rectangle::Coordinate c3{1, 1};
    Rectangle::Coordinate c4{6, 1};

    Rectangle rect1{c1, c2, c3, c4};

    EXPECT_FLOAT_EQ(rect1.length(), c2.x - c1.x);
}

/**
 * @brief Find the length in the y-direction
 */
TEST(Length, FindLengthY) {

    Rectangle::Coordinate c1{1, 6};
    Rectangle::Coordinate c2{5, 6};
    Rectangle::Coordinate c3{1, 1};
    Rectangle::Coordinate c4{5, 1};

    Rectangle rect1{c1, c2, c3, c4};

    EXPECT_FLOAT_EQ(rect1.length(), c2.y - c4.y);
}

/**
 * @brief Find the length of a square
 */
TEST(Length, FindLengthSquare) {

    Rectangle::Coordinate c1{1, 5};
    Rectangle::Coordinate c2{5, 5};
    Rectangle::Coordinate c3{1, 1};
    Rectangle::Coordinate c4{5, 1};

    Rectangle rect1{c1, c2, c3, c4};

    EXPECT_FLOAT_EQ(rect1.length(), c2.x - c1.x);
    EXPECT_FLOAT_EQ(rect1.length(), c2.y - c4.y);
}

/**
 * @brief Find the width in the x-direction
 */
TEST(Width, FindWidthX) {

    Rectangle::Coordinate c1{1, 5};
    Rectangle::Coordinate c2{6, 5};
    Rectangle::Coordinate c3{1, 1};
    Rectangle::Coordinate c4{6, 1};

    Rectangle rect1{c1, c2, c3, c4};

    EXPECT_FLOAT_EQ(rect1.width(), c2.y - c4.y);
}

/**
 * @brief Find the width in the y-direction
 */
TEST(Width, FindWidthY) {

    Rectangle::Coordinate c1{1, 6};
    Rectangle::Coordinate c2{5, 6};
    Rectangle::Coordinate c3{1, 1};
    Rectangle::Coordinate c4{5, 1};

    Rectangle rect1{c1, c2, c3, c4};

    EXPECT_FLOAT_EQ(rect1.width(), c2.x - c1.x);
}

/**
 * @brief Find the width of a square
 */
TEST(Width, FindWidthSquare) {

    Rectangle::Coordinate c1{1, 5};
    Rectangle::Coordinate c2{5, 5};
    Rectangle::Coordinate c3{1, 1};
    Rectangle::Coordinate c4{5, 1};

    Rectangle rect1{c1, c2, c3, c4};

    EXPECT_FLOAT_EQ(rect1.width(), c2.x - c1.x);
    EXPECT_FLOAT_EQ(rect1.width(), c2.y - c4.y);
}

/**
 * @brief Find the area of a maximum sized rectangle
 */
TEST(Area, MaximumArea) {

    Rectangle::Coordinate c1{1, 19};
    Rectangle::Coordinate c2{19, 19};
    Rectangle::Coordinate c3{1, 1};
    Rectangle::Coordinate c4{19, 1};

    Rectangle rect1{c1, c2, c3, c4};

    EXPECT_FLOAT_EQ(rect1.area(), 18.0 * 18.0);
}

/**
 * @brief Find the are of a minimum sized square
 */
TEST(Area, MinimumArea) {

    Rectangle::Coordinate c1{1, 2};
    Rectangle::Coordinate c2{2, 2};
    Rectangle::Coordinate c3{1, 1};
    Rectangle::Coordinate c4{2, 1};

    Rectangle rect1{c1, c2, c3, c4};

    EXPECT_FLOAT_EQ(rect1.area(), 1.0);
}

/**
 * @brief Find the area of a randomly sized rectangle
 */
TEST(Area, RandomArea) {

    float x1 = getRandomNumber();
    float x2 = getRandomNumber();
    float y1 = getRandomNumber();
    float y2 = getRandomNumber();

    if (x1 > x2) {
        float tmp = x2;
        x2 = x1;
        x1 = tmp;
    }


    if (y1 > y2) {
        float tmp = y2;
        y2 = y1;
        y1 = tmp;
    }

    Rectangle::Coordinate c1{x1, y2};
    Rectangle::Coordinate c2{x2, y2};
    Rectangle::Coordinate c3{x1, y1};
    Rectangle::Coordinate c4{x2, y1};

    Rectangle rect1{c1, c2, c3, c4};

    EXPECT_FLOAT_EQ(rect1.area(), (x2 - x1) * (y2 - y1));
}

/**
 * @brief Find the perimeter of a maximum sized rectangle
 */
TEST(Perimeter, MaximumPerimeter) {

    Rectangle::Coordinate c1{1, 19};
    Rectangle::Coordinate c2{19, 19};
    Rectangle::Coordinate c3{1, 1};
    Rectangle::Coordinate c4{19, 1};

    Rectangle rect1{c1, c2, c3, c4};

    EXPECT_FLOAT_EQ(rect1.perimeter(), 18.0 * 4.0);
}

/**
 * @brief Find the perimeter of a mimimum sized rectangle
 */
TEST(Perimeter, MinimumPerimeter) {

    Rectangle::Coordinate c1{1, 2};
    Rectangle::Coordinate c2{2, 2};
    Rectangle::Coordinate c3{1, 1};
    Rectangle::Coordinate c4{2, 1};

    Rectangle rect1{c1, c2, c3, c4};

    EXPECT_FLOAT_EQ(rect1.perimeter(), 4.0);
}

/**
 * @brief Find the perimeter of a randomly sized rectangle
 */
TEST(Perimeter, RandomPerimeter) {

    float x1 = getRandomNumber();
    float x2 = getRandomNumber();
    float y1 = getRandomNumber();
    float y2 = getRandomNumber();

    if (x1 > x2) {
        float tmp = x2;
        x2 = x1;
        x1 = tmp;
    }


    if (y1 > y2) {
        float tmp = y2;
        y2 = y1;
        y1 = tmp;
    }

    Rectangle::Coordinate c1{x1, y2};
    Rectangle::Coordinate c2{x2, y2};
    Rectangle::Coordinate c3{x1, y1};
    Rectangle::Coordinate c4{x2, y1};

    Rectangle rect1{c1, c2, c3, c4};

    EXPECT_FLOAT_EQ(rect1.perimeter(), 2.0 * ((x2 - x1) + (y2 - y1)));
}

/**
 * @brief Determine if a rectangle is a square
 */
TEST(Square, IsSquare) {

    Rectangle::Coordinate c1{1, 5};
    Rectangle::Coordinate c2{5, 5};
    Rectangle::Coordinate c3{1, 1};
    Rectangle::Coordinate c4{5, 1};

    Rectangle rect1{c1, c2, c3, c4};

    EXPECT_TRUE(rect1.square());
}

/**
 * @brief Determine a long rectangle is not a square
 */
TEST(Square, NotSquareLong) {

    Rectangle::Coordinate c1{1, 5};
    Rectangle::Coordinate c2{6, 5};
    Rectangle::Coordinate c3{1, 1};
    Rectangle::Coordinate c4{6, 1};

    Rectangle rect1{c1, c2, c3, c4};

    EXPECT_FALSE(rect1.square());
}

/**
 * @brief Determine a tall rectangle is not a square
 */
TEST(Square, NotSquareTall) {

    Rectangle::Coordinate c1{1, 6};
    Rectangle::Coordinate c2{5, 6};
    Rectangle::Coordinate c3{1, 1};
    Rectangle::Coordinate c4{5, 1};

    Rectangle rect1{c1, c2, c3, c4};

    EXPECT_FALSE(rect1.square());
}

