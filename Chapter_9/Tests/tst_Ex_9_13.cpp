#include <Ex_9_13.h>
#include <gtest/gtest.h>

/**
 * @brief Get a random integer
 */
int getRandomNumber(void) {
    return (Rectangle::MIN_VALUE + 1) + static_cast<int>(rand()) % Rectangle::MAX_VALUE;
}

/**
 * @brief Get a set of random numbers
 * 
 * @param x1 random integer for the x-axis
 * @param x2 random integer for the x-axis which is greater than x1
 * @param y1 random integer for the y-axis
 * @param x2 random integer for the y-axis which is greater than y1
 */
void getRandomNumberSet(int &x1, int& x2, int &y1, int& y2) {

    int tmp;
    x1 = getRandomNumber();
    x2 = getRandomNumber();
    y1 = getRandomNumber();
    y2 = getRandomNumber();

    if (x1 > x2) {
        tmp = x1;
        x1 = x2;
        x2 = tmp;
    }

    if (y1 > y2) {
        tmp = y1;
        y1 = y2;
        y2 = tmp;
    }

}

/**
 * @brief Move the rectangle by zero in the x direction
 */
TEST(MoveX, MoveZero) {

    int x1{2};
    int x2{3};
    int y1{4};
    int y2{5};

    int delta{0};

    Rectangle::Coordinate c1{x1, y2};
    Rectangle::Coordinate c2{x2, y2};
    Rectangle::Coordinate c3{x1, y1};
    Rectangle::Coordinate c4{x2, y1};

    Rectangle rect{c1, c2, c3, c4};

    rect.moveX(delta);

    EXPECT_EQ(rect.getRightVertex(), x2 + delta);
    EXPECT_EQ(rect.getLeftVertex(), x1 + delta);
    EXPECT_EQ(rect.getTopVertex(), y2);
    EXPECT_EQ(rect.getBottomVertex(), y1);
}

/**
 * @brief Move rectangle in the positive x-direction
 */
TEST(MoveX, MovePositiveValid) {

    int x1{2};
    int x2{3};
    int y1{4};
    int y2{5};

    int delta{1};

    Rectangle::Coordinate c1{x1, y2};
    Rectangle::Coordinate c2{x2, y2};
    Rectangle::Coordinate c3{x1, y1};
    Rectangle::Coordinate c4{x2, y1};

    Rectangle rect{c1, c2, c3, c4};

    rect.moveX(delta);

    EXPECT_EQ(rect.getRightVertex(), x2 + delta);
    EXPECT_EQ(rect.getLeftVertex(), x1 + delta);
    EXPECT_EQ(rect.getTopVertex(), y2);
    EXPECT_EQ(rect.getBottomVertex(), y1);
}

/**
 * @brief Move rectangle in the negative x-direction
 */
TEST(MoveX, MoveNegativeValid) {

    int x1{2};
    int x2{3};
    int y1{4};
    int y2{5};

    int delta{-1};

    Rectangle::Coordinate c1{x1, y2};
    Rectangle::Coordinate c2{x2, y2};
    Rectangle::Coordinate c3{x1, y1};
    Rectangle::Coordinate c4{x2, y1};

    Rectangle rect{c1, c2, c3, c4};

    rect.moveX(delta);

    EXPECT_EQ(rect.getRightVertex(), x2 + delta);
    EXPECT_EQ(rect.getLeftVertex(), x1 + delta);
    EXPECT_EQ(rect.getTopVertex(), y2);
    EXPECT_EQ(rect.getBottomVertex(), y1);
}

/**
 * @brief Attempt to move the rectangle in the x-direction past the
 * maximum index
 */
TEST(MoveX, MovePositiveInvalid) {

    int x1{2};
    int x2{3};
    int y1{4};
    int y2{5};

    int delta{Rectangle::MAX_VALUE - x2};

    Rectangle::Coordinate c1{x1, y2};
    Rectangle::Coordinate c2{x2, y2};
    Rectangle::Coordinate c3{x1, y1};
    Rectangle::Coordinate c4{x2, y1};

    Rectangle rect{c1, c2, c3, c4};

    rect.moveX(delta);

    EXPECT_EQ(rect.getRightVertex(), x2);
    EXPECT_EQ(rect.getLeftVertex(), x1);
    EXPECT_EQ(rect.getTopVertex(), y2);
    EXPECT_EQ(rect.getBottomVertex(), y1);
}

/**
 * @brief Attempt to move the rectangle in the negative x-direction past the
 * minimum index
 */
TEST(MoveX, MoveNegativeInvalid) {

    int x1{2};
    int x2{3};
    int y1{4};
    int y2{5};

    int delta{-x1};

    Rectangle::Coordinate c1{x1, y2};
    Rectangle::Coordinate c2{x2, y2};
    Rectangle::Coordinate c3{x1, y1};
    Rectangle::Coordinate c4{x2, y1};

    Rectangle rect{c1, c2, c3, c4};

    rect.moveX(delta);

    EXPECT_EQ(rect.getRightVertex(), x2);
    EXPECT_EQ(rect.getLeftVertex(), x1);
    EXPECT_EQ(rect.getTopVertex(), y2);
    EXPECT_EQ(rect.getBottomVertex(), y1);
}

/**
 * @brief Move rectangle in the y-direction by zero
 */
TEST(MoveY, MoveZero) {

    int x1{2};
    int x2{3};
    int y1{4};
    int y2{5};

    int delta{0};

    Rectangle::Coordinate c1{x1, y2};
    Rectangle::Coordinate c2{x2, y2};
    Rectangle::Coordinate c3{x1, y1};
    Rectangle::Coordinate c4{x2, y1};

    Rectangle rect{c1, c2, c3, c4};

    rect.moveY(delta);

    EXPECT_EQ(rect.getRightVertex(), x2);
    EXPECT_EQ(rect.getLeftVertex(), x1);
    EXPECT_EQ(rect.getTopVertex(), y2);
    EXPECT_EQ(rect.getBottomVertex(), y1);
}

/**
 * @brief Move rectangle in the positive x-direction
 */
TEST(MoveY, MovePositiveValid) {

    int x1{2};
    int x2{3};
    int y1{4};
    int y2{5};

    int delta{1};

    Rectangle::Coordinate c1{x1, y2};
    Rectangle::Coordinate c2{x2, y2};
    Rectangle::Coordinate c3{x1, y1};
    Rectangle::Coordinate c4{x2, y1};

    Rectangle rect{c1, c2, c3, c4};

    rect.moveY(delta);

    EXPECT_EQ(rect.getRightVertex(), x2);
    EXPECT_EQ(rect.getLeftVertex(), x1);
    EXPECT_EQ(rect.getTopVertex(), y2 + delta);
    EXPECT_EQ(rect.getBottomVertex(), y1 + delta);
}

/**
 * @brief Move rectangle in the negative x-direction
 */
TEST(MoveY, MoveNegativeValid) {

    int x1{2};
    int x2{3};
    int y1{4};
    int y2{5};

    int delta{-1};

    Rectangle::Coordinate c1{x1, y2};
    Rectangle::Coordinate c2{x2, y2};
    Rectangle::Coordinate c3{x1, y1};
    Rectangle::Coordinate c4{x2, y1};

    Rectangle rect{c1, c2, c3, c4};

    rect.moveY(delta);

    EXPECT_EQ(rect.getRightVertex(), x2);
    EXPECT_EQ(rect.getLeftVertex(), x1);
    EXPECT_EQ(rect.getTopVertex(), y2 + delta);
    EXPECT_EQ(rect.getBottomVertex(), y1 + delta);
}

/**
 * @brief Attempt to move the rectangle a single value beyond the
 * maximum y-axis
 */
TEST(MoveY, MovePositiveInvalid) {

    int x1{2};
    int x2{3};
    int y1{4};
    int y2{5};

    int delta{Rectangle::MAX_VALUE - y2};

    Rectangle::Coordinate c1{x1, y2};
    Rectangle::Coordinate c2{x2, y2};
    Rectangle::Coordinate c3{x1, y1};
    Rectangle::Coordinate c4{x2, y1};

    Rectangle rect{c1, c2, c3, c4};

    rect.moveY(delta);

    EXPECT_EQ(rect.getRightVertex(), x2);
    EXPECT_EQ(rect.getLeftVertex(), x1);
    EXPECT_EQ(rect.getTopVertex(), y2);
    EXPECT_EQ(rect.getBottomVertex(), y1);
}

/**
 * @brief Attempt to move the rectangle beyond the minimum y-axis
 * minimum positition
 */
TEST(MoveY, MoveNegativeInvalid) {

    int x1{2};
    int x2{3};
    int y1{4};
    int y2{5};

    int delta{-y1};

    Rectangle::Coordinate c1{x1, y2};
    Rectangle::Coordinate c2{x2, y2};
    Rectangle::Coordinate c3{x1, y1};
    Rectangle::Coordinate c4{x2, y1};

    Rectangle rect{c1, c2, c3, c4};

    rect.moveY(delta);

    EXPECT_EQ(rect.getRightVertex(), x2);
    EXPECT_EQ(rect.getLeftVertex(), x1);
    EXPECT_EQ(rect.getTopVertex(), y2);
    EXPECT_EQ(rect.getBottomVertex(), y1);
}

/**
 * @brief Increase the scale of the rectangle by a valid multiplier
 */
TEST(SetScale, IncreaseValid) {

    int x1{2};
    int x2{3};
    int y1{4};
    int y2{5};

    float scale{15.0};

    Rectangle::Coordinate c1{x1, y2};
    Rectangle::Coordinate c2{x2, y2};
    Rectangle::Coordinate c3{x1, y1};
    Rectangle::Coordinate c4{x2, y1};

    Rectangle rect{c1, c2, c3, c4};

    rect.setScale(scale);

    EXPECT_EQ(rect.getRightVertex(), 17);
    EXPECT_EQ(rect.getLeftVertex(), x1);
    EXPECT_EQ(rect.getTopVertex(), 19);
    EXPECT_EQ(rect.getBottomVertex(), y1);
}

/**
 * @brief Attempt to increase the size of the rectangle by an invalid
 * multiplier
 */
TEST(SetScale, IncreaseInvalid) {

    int x1{2};
    int x2{3};
    int y1{4};
    int y2{5};

    float scale{17.0};

    Rectangle::Coordinate c1{x1, y2};
    Rectangle::Coordinate c2{x2, y2};
    Rectangle::Coordinate c3{x1, y1};
    Rectangle::Coordinate c4{x2, y1};

    Rectangle rect{c1, c2, c3, c4};

    rect.setScale(scale);

    EXPECT_EQ(rect.getRightVertex(), x2);
    EXPECT_EQ(rect.getLeftVertex(), x1);
    EXPECT_EQ(rect.getTopVertex(), y2);
    EXPECT_EQ(rect.getBottomVertex(), y1);
}

/**
 * @brief Decrease the size of the rectangle by a valid multiplier
 */
TEST(SetScale, DecreaseValid) {

    int x1{2};
    int x2{4};
    int y1{4};
    int y2{6};

    float scale{0.5};

    Rectangle::Coordinate c1{x1, y2};
    Rectangle::Coordinate c2{x2, y2};
    Rectangle::Coordinate c3{x1, y1};
    Rectangle::Coordinate c4{x2, y1};

    Rectangle rect{c1, c2, c3, c4};

    rect.setScale(scale);

    EXPECT_EQ(rect.getRightVertex(), 3);
    EXPECT_EQ(rect.getLeftVertex(), x1);
    EXPECT_EQ(rect.getTopVertex(), 5);
    EXPECT_EQ(rect.getBottomVertex(), y1);
}

/**
 * @brief Attempt to decrease the size of the rectangle by an invalid
 * multiplier
 */
TEST(SetScale, DecreaseInvalid) {

    int x1{2};
    int x2{4};
    int y1{4};
    int y2{6};

    float scale{0.25};

    Rectangle::Coordinate c1{x1, y2};
    Rectangle::Coordinate c2{x2, y2};
    Rectangle::Coordinate c3{x1, y1};
    Rectangle::Coordinate c4{x2, y1};

    Rectangle rect{c1, c2, c3, c4};

    rect.setScale(scale);

    EXPECT_EQ(rect.getRightVertex(), x2);
    EXPECT_EQ(rect.getLeftVertex(), x1);
    EXPECT_EQ(rect.getTopVertex(), y2);
    EXPECT_EQ(rect.getBottomVertex(), y1);
}

/**
 * @brief Draw the maximum area square
 */
TEST(Draw, MaxSquare) {

    int x1{1};
    int x2{19};
    int y1{1};
    int y2{19};

    Rectangle::Coordinate c1{x1, y2};
    Rectangle::Coordinate c2{x2, y2};
    Rectangle::Coordinate c3{x1, y1};
    Rectangle::Coordinate c4{x2, y1};

    Rectangle rect{c1, c2, c3, c4};

    rect.setFillCharacter('$');
    rect.setPerimeterCharacter('@');

    rect.drawRectangle();

}

/**
 * @brief Draw the minimum size square
 */
TEST(Draw, MinSquare) {

    int x1{1};
    int x2{2};
    int y1{1};
    int y2{2};

    Rectangle::Coordinate c1{x1, y2};
    Rectangle::Coordinate c2{x2, y2};
    Rectangle::Coordinate c3{x1, y1};
    Rectangle::Coordinate c4{x2, y1};

    Rectangle rect{c1, c2, c3, c4};

    rect.drawRectangle();

}

/**
 * @brief Fill the minimum square with a new character
 */
TEST(Draw, MinSquareFilling) {

    int x1{2};
    int x2{4};
    int y1{2};
    int y2{4};

    Rectangle::Coordinate c1{x1, y2};
    Rectangle::Coordinate c2{x2, y2};
    Rectangle::Coordinate c3{x1, y1};
    Rectangle::Coordinate c4{x2, y1};

    Rectangle rect{c1, c2, c3, c4};

    rect.drawRectangle();

}