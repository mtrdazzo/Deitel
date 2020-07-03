#include <gtest/gtest.h>
#include "Ex_10_11.h"
#include <cstdlib>
#include <ctime>

/**
 * @brief Get a polynomial array with random coefficients between -100 and 100.
 * 
 * @return int 
 */
POLYNOMIAL_ARRAY getRandomPolynomials() {
    /* set random seed based on current time */
    srand(static_cast<unsigned int>(time(0)));

    POLYNOMIAL_ARRAY pArray;
    for (auto & coefficient : pArray)
        coefficient = -100 + rand() / 100;
    
    return pArray;
}

/**
 * @brief Construct a Polynomial object from a random array of integers.
 * 
 */
TEST(PolynomialConstructor, RandomIntegers) {
    POLYNOMIAL_ARRAY pArray{getRandomPolynomials()};
    Polynomial p1{pArray};

    for (size_t order{0}; order < NUM_COFFICIENTS; ++order)
        EXPECT_EQ(p1.getCoefficient(order), pArray.at(order));
    
    Polynomial empty;

    for (size_t order{0}; order < NUM_COFFICIENTS; ++order)
        EXPECT_EQ(empty.getCoefficient(order), 0);
}

/**
 * @brief Set Polynomial coefficients from a random array of integers.
 * 
 */
TEST(PolynomialSetter, RandomIntegers) {
    POLYNOMIAL_ARRAY pArray{getRandomPolynomials()};
    Polynomial p1{pArray};

    for (size_t order{0}; order < NUM_COFFICIENTS; ++order)
        p1.setCoefficient(order, pArray.at(order));
    
    for (size_t order{0}; order < NUM_COFFICIENTS; ++order)
        EXPECT_EQ(p1.getCoefficient(order), pArray.at(order));
}

/**
 * @brief Attempt to access out of bounds order in the polynomial.
 * 
 */
TEST(PolynomialsSetter, OutOfBounds) {
    POLYNOMIAL_ARRAY pArray{getRandomPolynomials()};
    Polynomial p1{pArray};
    
    try {
        p1.getCoefficient(NUM_COFFICIENTS);
    }
    catch (std::out_of_range & err) {
        EXPECT_NE(err.what(), "");
    }

    try {
        p1.getCoefficient(-1);
    }
    catch (std::out_of_range & err) {
        EXPECT_NE(err.what(), "");
    }
}

/**
 * @brief Test the Addition operator
 * 
 */
TEST(PolynomialOperators, Addition) {
    POLYNOMIAL_ARRAY pArray1{getRandomPolynomials()};
    POLYNOMIAL_ARRAY pArray2{getRandomPolynomials()};

    Polynomial p1{pArray1};
    Polynomial p2{pArray2};
    Polynomial p3 = p1 + p2;

    for (size_t order{0}; order < NUM_COFFICIENTS; ++order)
        EXPECT_EQ(p3.getCoefficient(order), p1.getCoefficient(order) + p2.getCoefficient(order));
    
    Polynomial empty;
    Polynomial p4{pArray1};
    Polynomial p5 = p4 + empty;

    for (size_t order{0}; order < NUM_COFFICIENTS; ++order)
        EXPECT_EQ(p5.getCoefficient(order), p4.getCoefficient(order));
}

/**
 * @brief Test the Subtraction operator
 * 
 */
TEST(PolynomialOperators, Subtraction) {
    POLYNOMIAL_ARRAY pArray1{getRandomPolynomials()};
    POLYNOMIAL_ARRAY pArray2{getRandomPolynomials()};

    Polynomial p1{pArray1};
    Polynomial p2{pArray2};
    Polynomial p3 = p1 - p2;

    for (size_t order{0}; order < NUM_COFFICIENTS; ++order)
        EXPECT_EQ(p3.getCoefficient(order), p1.getCoefficient(order) - p2.getCoefficient(order));
    
    Polynomial empty;
    Polynomial p4{pArray1};
    Polynomial p5 = p4 - empty;

    for (size_t order{0}; order < NUM_COFFICIENTS; ++order)
        EXPECT_EQ(p5.getCoefficient(order), p4.getCoefficient(order));
}

/**
 * @brief Test the Addition assignment operator
 * 
 */
TEST(PolynomialOperators, AdditionAssignment) {
    POLYNOMIAL_ARRAY pArray1{getRandomPolynomials()};
    POLYNOMIAL_ARRAY pArray2{getRandomPolynomials()};

    Polynomial p1{pArray1};
    Polynomial p2{pArray2};
    Polynomial p3{p1 + p2};

    p1 += p2;
    for (size_t order{0}; order < NUM_COFFICIENTS; ++order)
        EXPECT_EQ(p3.getCoefficient(order), p1.getCoefficient(order));
    
    Polynomial empty;
    Polynomial p4{pArray1};
    Polynomial p5{p4};

    p4 += empty;
    for (size_t order{0}; order < NUM_COFFICIENTS; ++order)
        EXPECT_EQ(p5.getCoefficient(order), p4.getCoefficient(order));
}

/**
 * @brief Test the Subtraction assignment operator
 * 
 */
TEST(PolynomialOperators, SubtractionAssignment) {
    POLYNOMIAL_ARRAY pArray1{getRandomPolynomials()};
    POLYNOMIAL_ARRAY pArray2{getRandomPolynomials()};

    Polynomial p1{pArray1};
    Polynomial p2{pArray2};
    Polynomial p3{p1 - p2};

    p1 -= p2;
    for (size_t order{0}; order < NUM_COFFICIENTS; ++order)
        EXPECT_EQ(p3.getCoefficient(order), p1.getCoefficient(order));
    
    Polynomial empty;
    Polynomial p4{pArray1};
    Polynomial p5{p4};

    p4 -= empty;
    for (size_t order{0}; order < NUM_COFFICIENTS; ++order)
        EXPECT_EQ(p5.getCoefficient(order), p4.getCoefficient(order));
}

/**
 * @brief Test the assignment operator
 * 
 */
TEST(PolynomialOperators, Assignment) {
    POLYNOMIAL_ARRAY pArray1{getRandomPolynomials()};

    Polynomial p1{pArray1};
    Polynomial p2;

    p2 = p1;
    for (size_t order{0}; order < NUM_COFFICIENTS; ++order)
        EXPECT_EQ(p2.getCoefficient(order), p1.getCoefficient(order));
}

/**
 * @brief Test the multiplication operator
 * 
 */
TEST(PolynomialOperators, Multiplication) {
    POLYNOMIAL_ARRAY pArray{1};
    POLYNOMIAL_ARRAY pArray2{0};
    POLYNOMIAL_ARRAY pArray3{getRandomPolynomials()};

    Polynomial one{pArray};
    Polynomial zero{pArray2};
    Polynomial random{pArray3};

    /* Identity property */
    Polynomial product = one * one;
    EXPECT_EQ(product, one);

    product = one * random;
    EXPECT_EQ(product, random);
    product = one * random;
    EXPECT_EQ(product, random);

    /* zero property */
    product = zero * random;
    EXPECT_EQ(product, zero);
    product = random * zero;
    EXPECT_EQ(product, zero);

    product = one * zero;
    EXPECT_EQ(product, zero);
    product = zero * one;
    EXPECT_EQ(product, zero);

    /* small polynomials */
    POLYNOMIAL_ARRAY pArray4{1, 1};
    Polynomial p1{pArray4};
    product = p1 * p1;
    POLYNOMIAL_ARRAY expected{1, 2, 1};
    EXPECT_EQ(product, Polynomial(expected));

    POLYNOMIAL_ARRAY pArray5{1, -1};
    Polynomial p2{pArray5};
    product = p1 * p2;

    expected.at(0) = 1;
    expected.at(1) = 0;
    expected.at(2) = -1;

    EXPECT_EQ(product, Polynomial(expected));

    /* Overflow over order NUM_COEFFICIENTS */
    p2 = zero;
    p2.setCoefficient(20, 2);
    product = p2 * p2;
    EXPECT_EQ(product, zero);

    /* No overflow */
    p1 = zero;
    p1.setCoefficient(19, 2);
    product = p1 * p2;
    Polynomial expectedP;
    expectedP.setCoefficient(39, 4);
    EXPECT_EQ(product, expectedP);
}