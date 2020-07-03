/**
 * @file Ex_10_12.h
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief DollarAmount class definition
 * 
 * Exercise 10-12 DollarAmount Class Enhancement
 * 
 * Enhance class DollarAmount from Exercise 5.32 with overloaded addition (+), subtraction (-),
 * and division (/) operators.
 * 
 * @version 0.1
 * @date 2020-07-03
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <string>
#include <cmath>

class DollarAmount {

    public:

        explicit DollarAmount(int64_t value) : amount{value} {};

        /**
         * @brief Addition operator with DollarAmount operand
         * 
         * @return DollarAmount 
         */
        DollarAmount operator+(const DollarAmount & other) const {
            return DollarAmount(amount + other.amount);
        }

        /**
         * @brief Addition operator with integer operand
         * 
         * @return DollarAmount 
         */
        DollarAmount operator+(const int64_t & other) const {
            return *this + DollarAmount(other);
        }

        /**
         * @brief Subtration operator with DollarAmount operand
         * 
         * @return DollarAmount 
         */
        DollarAmount operator-(const DollarAmount & other) const {
            return DollarAmount(amount - other.amount);
        }

        /**
         * @brief Subtraction operator with integer operand
         * 
         * @return DollarAmount 
         */
        DollarAmount operator-(const int64_t & other) const {
            return *this - DollarAmount(other);
        }

        /**
         * @brief Division operator with DollarAmount operand
         * 
         * @return int64_t 
         */
        int64_t operator/(const DollarAmount & other) const {
            if (other.amount == 0)
                throw std::invalid_argument("cannot divide by zero");
            return amount / other.amount;
        }

        /**
         * @brief Division operator with integer operand
         * 
         * @return int64_t
         */
        int64_t operator/(const int64_t & other) const {
            if (other == 0)
                throw std::invalid_argument("cannot divide by zero");
            return amount / other;
        }

        /**
         * @brief Money amount to string
         * 
         * @return std::string 
         */
        std::string toString() const;

    private:
        int64_t amount{0}; /* dollar amount in pennies */

};