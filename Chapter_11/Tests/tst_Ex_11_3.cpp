/**
 * @file tst_Ex_11_3.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Testing composition of CommissionEmployee and BasePlusCommissionEmployee classes
 * @version 0.1
 * @date 2020-07-06
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <gtest/gtest.h>
#include <Ex_11_3.h>

TEST(CommissionEmployee, Constructor) {
    CommissionEmployee ce{"Jon", "Doe", "123456789", 5000, 0.25};
}