#include <Ex_9_11.h>
#include <gtest/gtest.h>

/**
 * @brief Create default Rectangle object
 */
TEST(Constructor, DefaultConstructor) {

    Rectangle rect1;

    EXPECT_FLOAT_EQ(rect1.getLength(), 1.0);
    EXPECT_FLOAT_EQ(rect1.getWidth(), 1.0);
}

/**
 * @brief Create default Rectangle object with the length as an argument.
 */
TEST(Constructor, SingleArgumentConstructor) {

    Rectangle rect1{5.0};

    EXPECT_FLOAT_EQ(rect1.getLength(), 5.0);
    EXPECT_FLOAT_EQ(rect1.getWidth(), 1.0);
}

/**
 * @brief Create default Rectangle object with length and width as arguments.
 */
TEST(Constructor, TwoArgumentConstructor) {

    Rectangle rect1{5.0, 19.9};

    EXPECT_FLOAT_EQ(rect1.getLength(), 5.0);
    EXPECT_FLOAT_EQ(rect1.getWidth(), 19.9);
}

/**
 * @brief Create Rectangle with single zero argument
 */
TEST(Constructor, SingleInvalidArgumentLess) {
    Rectangle rect1{0.0, 3.0};

    EXPECT_FLOAT_EQ(rect1.getLength(), 1.0);
    EXPECT_FLOAT_EQ(rect1.getWidth(), 3.0);
}

/**
 * @brief Create Rectangle object with width larger than the maximum.
 */
TEST(Constructor, SingleInvalidArgumentGreater) {
    Rectangle rect1{4.2, 20.0};

    EXPECT_FLOAT_EQ(rect1.getLength(), 4.2);
    EXPECT_FLOAT_EQ(rect1.getWidth(), 1.0);
}

/**
 * @brief Get the perimeter of a minimum sized rectangle object.
 */
TEST(Perimeter, Minumum) {
    Rectangle rect1{1.0, 1.0};

    EXPECT_DOUBLE_EQ(rect1.perimeter(), 4.0);
}

/**
 * @brief Get the perimeter of a maximum sized rectangle object.
 */
TEST(Perimeter, Maximum) {
    Rectangle rect1{19.0, 19.0};

    EXPECT_DOUBLE_EQ(rect1.perimeter(), 76.0);
}

/**
 * @brief Get the perimeter of a nominal sized rectangle object.
 */
TEST(Perimeter, Nominal) {
    Rectangle rect1{5.0, 4.0};

    EXPECT_DOUBLE_EQ(rect1.perimeter(), 18.0);
}

/**
 * @brief Get the area of a minimum size rectangle object.
 */
TEST(Area, Minimum) {
    Rectangle rect1{1.0, 1.0};

    EXPECT_DOUBLE_EQ(rect1.area(), 1.0);
}

/**
 * @brief Get teh area of a maximum sized rectangle object.
 */
TEST(Area, Maximum) {
    Rectangle rect1{19.0, 19.0};

    EXPECT_DOUBLE_EQ(rect1.area(), 361.0);
}

/**
 * @brief Get the area of a nominally sized rectangle object.
 */
TEST(Area, Nominal) {
    Rectangle rect1{5.0, 4.0};

    EXPECT_DOUBLE_EQ(rect1.area(), 20.0);
}
