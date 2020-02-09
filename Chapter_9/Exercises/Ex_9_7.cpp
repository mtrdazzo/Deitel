/**
 * @file Ex_9_7.cpp
 *
 * @brief Implementation for the Name class which can output a constant salutation.
 *
 * @author Matt Randazzo
 */

#include <Ex_9_7.h>
#include <sstream>

/**
 * @brief Default Name class constructor with four parameters.
 */
Name::Name(std::string s_salutation, std::string s_firstName, std::string s_middleName, std::string s_lastName) :
            salutation{s_salutation},
            firstName{s_firstName},
            middleName{s_middleName},
            lastName{s_lastName} {};

/**
 * @brief Outputs the person's full name in the form:
 *        "salutation lastName, firstName middleName"
 *
 * @return person's full name
 *
 */
std::string Name::toString(void) {

    std::ostringstream output;

    output << salutation << " " << lastName << ", ";
    output << firstName << " " << middleName << ".";

    return output.str();
}
