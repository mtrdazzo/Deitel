/**
 * @file Ex_10_13.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief DollarAmount class method definitions
 * @version 0.1
 * @date 2020-07-05
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "Ex_10_13.h"

/**
 * @brief Express the dollar amount as a string (i.e., 6.32 or 0.04)
 * 
 * @return std::string 
 */
std::string DollarAmount::toString() const {

    std::string negative;
    std::string dollars{std::to_string(amount / 100)};
    std::string cents{std::to_string(std::abs(amount % 100))};

    if (amount % 100 < 0 && amount / 100 >= 0 )
        negative = "-";

    return negative + dollars + "." + ((cents.size() > 1) ? "" : "0") + cents;
}