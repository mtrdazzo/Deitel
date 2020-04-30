#include <Ex_9_18.h>
#include <gtest/gtest.h>

/**
 * @brief Sunny day scenario to create company employee objects.
 */
TEST(Constructor, SunnyDay) {

    Employees company1("Matt", "Randazzo" , "Mike", "Brown");
    Employees company2("Bryan", "V" , "Mike", "Bandy");
}