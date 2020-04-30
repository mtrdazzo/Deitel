/**
 * @file tst_Ex_9_6.cpp
 *
 * @brief Tests the add, subtract, multiply, and divide methods of the Rational class.
 *
 * @author Matt Randazzo
 */

#include <Ex_9_6.h>
#include <gtest/gtest.h>

/**
 * @brief Attempt to construct a rational number with a zero denominator.
 */
TEST(constructor, ZeroDenominator) {

  try {
      Rational r1{1, 0};
  }
  catch (std::invalid_argument const & err ) {
      EXPECT_EQ(err.what(), std::string("denominator cannot be zero"));
  }
}

/**
 * @brief Construct a positive rational number.
 */
TEST(constructor, PositiveRational) {

  Rational r1{1, 2};

  EXPECT_EQ(r1.getNumerator(), 1);
  EXPECT_EQ(r1.getDenominator(), 2);

}

/**
 * @brief Construct a rational number with a negative numerator.
 */
TEST(constructor, NegativeNumerator) {

  Rational r1{-1, 2};

  EXPECT_EQ(r1.getNumerator(), -1);
  EXPECT_EQ(r1.getDenominator(), 2);
}

/**
 * @brief Construct a rational number with a negative denominator.
 */
TEST(constructor, NegativeDenominator) {

  Rational r1{1, -2};

  EXPECT_EQ(r1.getNumerator(), -1);
  EXPECT_EQ(r1.getDenominator(), 2);
}

/**
 * @brief Construct a negative number with a negative denominator.
 */
TEST(constructor, NegativeNumeratorDenominator) {

  Rational r1{-1, -2};

  EXPECT_EQ(r1.getNumerator(), 1);
  EXPECT_EQ(r1.getDenominator(), 2);
}

/**
 * @brief Construct a rational number equal to zero.
 */
TEST(rationalDouble, ZeroRational) {

  Rational r1{0, 2};

  EXPECT_DOUBLE_EQ(r1.toDouble(), 0.0);
}

/**
 * @brief Construct a rational positive number less than one.
 */
TEST(rationalDouble, RationalDoublePositiveGreaterThanOne) {

  Rational r1{2, 1};

  EXPECT_DOUBLE_EQ(r1.toDouble(), 2.0);
}

/**
 * @brief Construct a positive rational number equal to one.
 */
TEST(rationalDouble, RationalDoubleEqualToOne) {

  Rational r1{4, 4};

  EXPECT_DOUBLE_EQ(r1.toDouble(), 1.0);
  EXPECT_EQ(r1.getNumerator(), 1);
  EXPECT_EQ(r1.getDenominator(), 1);
}

/**
 * @brief Construct a positive rational number less than one.
 */
TEST(rationalDouble, RationalDoublePositiveLessThanOne) {

  Rational r1{1, 2};

  EXPECT_DOUBLE_EQ(r1.toDouble(), 0.5);
}

// /**
//  * @brief Add a zero to a rational number.
//  */
// TEST(add, AddZero) {

//     Rational r1{1, 2};
//     Rational r2{0, 1};

//     EXPECT_DOUBLE_EQ(r1.add(r2).toDouble(), r1.toDouble());
// }

// /**
//  * @brief Add two positive numbers with a positives result.
//  */
// TEST(add, AddPositivePositiveResult) {

//     Rational r1{1, 2};
//     Rational r2{2, 3};

//     EXPECT_DOUBLE_EQ(r1.add(r2).toDouble(), 7.0 / 6.0);
// }

// /**
//  * @brief Add two numbers with a postive result.
//  */
// TEST(add, AddNegativePositiveResult) {

//     Rational r1{1, 2};
//     Rational r2{-1, 3};

//     EXPECT_DOUBLE_EQ(r1.add(r2).toDouble(), 1.0 / 6.0);
// }

/**
 * @brief Add two numbers for a negative result.
 */
TEST(add, AddNegativeNegativeResult) {

    Rational r1{1, 3};
    Rational r2{-1, 2};

    EXPECT_DOUBLE_EQ(r1.add(r2).toDouble(), -1.0 / 6.0);
}

/**
 * @brief Add two numbers with a negative result.
 */
TEST(add, AddNegativeZeroResult) {

    Rational r1{1, 2};
    Rational r2{-1, 2};

    EXPECT_DOUBLE_EQ(r1.add(r2).toDouble(), 0.0);
}

/**
 * @brief Add two negative numbers.
 */
TEST(add, AddTwoNegative) {

    Rational r1{-1, 2};
    Rational r2{-2, 3};

    EXPECT_DOUBLE_EQ(r1.add(r2).toDouble(), -7.0 / 6.0);
}

/**
 * @brief Subtract zero from a positive number.
 */
TEST(subtract, SubtractZero) {

    Rational r1{1, 2};
    Rational r2{0, 2};

    EXPECT_DOUBLE_EQ(r1.subtract(r2).toDouble(), 0.5);
}

/**
 * @brief Subtract two negative numbers with a zero result.
 */
TEST(subtract, SubtractNegativeZeroResult) {

    Rational r1{-1, 2};
    Rational r2{-1, 2};

    EXPECT_DOUBLE_EQ(r1.subtract(r2).toDouble(), 0.0);
}

/**
 * @brief Subtract two positive numbers with a zero result.
 */
TEST(subtract, SubtractPositiveZeroResult) {

    Rational r1{1, 2};
    Rational r2{1, 2};

    EXPECT_DOUBLE_EQ(r1.subtract(r2).toDouble(), 0.0);
}

/**
 * @brief Subtract two positive numbers with a positive result.
 */
TEST(subtract, SubtractPositivePositveResult) {

    Rational r1{15, 2};
    Rational r2{3, 2};

    EXPECT_DOUBLE_EQ(r1.subtract(r2).toDouble(), 6.0);
}

/**
 * @brief Subtract two positive numbers with a negative result.
 */
TEST(subtract, SubtractPositiveNegativeResult) {

    Rational r1{1, 2};
    Rational r2{3, 2};

    EXPECT_DOUBLE_EQ(r1.subtract(r2).toDouble(), -1.0);
}

/**
 * @brief Subtract a negative number from a positive number.
 */
TEST(subtract, SubtractNegativePositiveResult) {

    Rational r1{1, 2};
    Rational r2{-3, 2};

    EXPECT_DOUBLE_EQ(r1.subtract(r2).toDouble(), 2.0);
}

/**
 * @brief Subtract a negative number from another negative number.
 */
TEST(subtract, SubtractNegativeNegativeResult) {

    Rational r1{-7, 2};
    Rational r2{-3, 2};

    EXPECT_DOUBLE_EQ(r1.subtract(r2).toDouble(), -2.0);
}

/**
 * @brief Multiply by zero.
 */
TEST(multiply, MultiplyByZero) {

    Rational r1{1, 2};
    Rational r2{0, 2};

    EXPECT_DOUBLE_EQ(r1.multiply(r2).toDouble(), 0.0);
}

/**
 * @brief Multiply by one.
 */
TEST(multiply, MultiplyByOne) {

    Rational r1{1, 2};
    Rational r2{1, 1};

    EXPECT_DOUBLE_EQ(r1.multiply(r2).toDouble(), 0.5);
}

/**
 * @brief Multiply by a positive number greater than one.
 */
TEST(multiply, MultiplyByPositiveGreaterThanOne) {

    Rational r1{1, 2};
    Rational r2{3, 2};

    EXPECT_DOUBLE_EQ(r1.multiply(r2).toDouble(), 0.75);
}

/**
 * @brief Multiply by a negative number less than negative one.
 */
TEST(multiply, MultiplyByNegativeGreaterThanOne) {

    Rational r1{1, 2};
    Rational r2{-3, 2};

    EXPECT_DOUBLE_EQ(r1.multiply(r2).toDouble(), -0.75);
}

/**
 * @brief Multiply by a positive number less than one.
 */
TEST(multiply, MultiplyByPositiveLessThanOne) {

    Rational r1{1, 2};
    Rational r2{1, 2};

    EXPECT_DOUBLE_EQ(r1.multiply(r2).toDouble(), 0.25);

}

/**
 * @brief Multiply by a negative number greater than negative one.
 */
TEST(multiply, MultiplyByNegativeLessThanOne) {

    Rational r1{1, 2};
    Rational r2{-1, 2};

    EXPECT_DOUBLE_EQ(r1.multiply(r2).toDouble(), -0.25);
}

/**
 * @brief Multiply by a smaller negative number greater than negative one.
 */
TEST(multiply, MultiplyBySmallerNegativeLessThanOne) {

    Rational r1{2, 1};
    Rational r2{-1, 2};

    EXPECT_DOUBLE_EQ(r1.multiply(r2).toDouble(), -1.0);
}

/**
 * @brief Multiply by a smaller positive number less than one.
 */
TEST(multiply, MultiplyBySmallerPositiveLessThanOne) {

    Rational r1{2, 1};
    Rational r2{1, 2};

    EXPECT_DOUBLE_EQ(r1.multiply(r2).toDouble(), 1.0);
}

/**
 * @brief Divide by one.
 */
TEST(divide, DivideByOne) {

    Rational r1{2, 1};
    Rational r2{1, 1};

    EXPECT_DOUBLE_EQ(r1.divide(r2).toDouble(), 2.0);
}

/**
 * @brief Divide by a smaller positive number.
 */
TEST(divide, DivideBySmallerPositive) {

    Rational r1{2, 1};
    Rational r2{1, 2};

    EXPECT_DOUBLE_EQ(r1.divide(r2).toDouble(), 4.0);
}

/**
 * @brief Divide by a smaller negative number.
 */
TEST(divide, DivideBySmallerNegative) {

    Rational r1{2, 1};
    Rational r2{-1, 2};

    EXPECT_DOUBLE_EQ(r1.divide(r2).toDouble(), -4.0);
}

/**
 * @brief Divide by a larger positive number.
 */
TEST(divide, DivideByLargerPositive) {

    Rational r1{2, 1};
    Rational r2{7, 2};

    EXPECT_DOUBLE_EQ(r1.divide(r2).toDouble(), 4.0 / 7.0);
}

/**
 * @brief Divide by a larger negative number.
 */
TEST(divide, DivideByLargerNegative) {

    Rational r1{2, 1};
    Rational r2{-7, 2};

    EXPECT_DOUBLE_EQ(r1.divide(r2).toDouble(), -4.0 / 7.0);

}

/**
 * @brief Attempt to divide by zero.
 */
TEST(divide, DivideByZero) {

    Rational r1{2, 1};
    Rational r2{0, 2};

    try {
        r1.divide(r2);
    }
    catch (std::invalid_argument const & err) {
        EXPECT_EQ(std::string("cannot divide by zero"), err.what());
    }
}

/**
 * @brief Return the string representation representation of a zero rational.
 */
TEST(toString, ToStringZero) {

    Rational r1{0, 5};

    EXPECT_EQ(r1.toRationalString(), std::string("0"));

}

/**
 * @brief Return the string representation representation of a negative rational
 *        less than negative one.
 */
TEST(toString, ToStringNegative) {

    Rational r1{-2, 1};

    EXPECT_EQ(r1.toRationalString().c_str(), std::string("-2"));

}

/**
 * @brief Return the string representation representation of a negative rational
 *        greater than zero.
 */
TEST(toString, ToStringPositve) {

    Rational r1{2, 1};

    EXPECT_EQ(r1.toRationalString().c_str(), std::string("2"));

}

/**
 * @brief Return the string representation representation of a positive rational.
 */
TEST(toString, ToStringPositveFraction) {

    Rational r1{2, 3};

    EXPECT_EQ(r1.toRationalString().c_str(), std::string("2/3"));

}

/**
 * @brief Return the string representation representation of a negative rational.
 */
TEST(toString, ToStringNegativeFraction) {

    Rational r1{-2, 3};

    EXPECT_EQ(r1.toRationalString().c_str(), std::string("-2/3"));

}

/**
 * @brief Return the double representation of a negative rational.
 */
TEST(toDouble, ToDoubleNegativeFraction) {

    Rational r1{-2, 3};

    EXPECT_DOUBLE_EQ(r1.toDouble(), -2.0/3.0);

}

/**
 * @brief Return the double representation of a positive rational.
 */
TEST(toDouble, ToDoublePositiveFraction) {

    Rational r1{2, 3};

    EXPECT_DOUBLE_EQ(r1.toDouble(), 2.0/3.0);

}

/**
 * @brief Return the double representation of a positive rational.
 */
TEST(toDouble, ToDoublePositive) {

    Rational r1{3, 2};

    EXPECT_DOUBLE_EQ(r1.toDouble(), 3.0/2.0);

}

/**
 * @brief Return the double representation of a negative rational.
 */
TEST(toDouble, ToDoubleNegative) {

    Rational r1{-3, 2};

    EXPECT_DOUBLE_EQ(r1.toDouble(), -3.0/2.0);

}

/**
 * @brief Return the double representation of zero.
 */
TEST(toDouble, ToDoubleZero) {

    Rational r1{0, 2};

    EXPECT_DOUBLE_EQ(r1.toDouble(), 0.0);

}

/**
 * @brief Return a simplified double representation of a rational number.
 */
TEST(toDouble, ToDoubleOne) {

    Rational r1{2, 2};

    EXPECT_DOUBLE_EQ(r1.toDouble(), 1.0);

}