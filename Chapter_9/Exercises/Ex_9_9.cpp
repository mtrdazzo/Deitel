/**
 * @file Ex_9_9.cpp
 *
 * @brief Implementation for the Name and Student class to store a student's data.
 *
 * @author Matt Randazzo
 */

/**
 * @file Ex_9_9.cpp
 *
 * @brief Enhanced Implementation for the Student and Name classes.
 *
 * @author Matt Randazzo
 */

#include <Ex_9_9.h>

/**
 * @brief Default Name class constructor with four parameters.
 */
Name::Name(std::string s_salutation, std::string s_firstName, std::string s_middleName, std::string s_lastName) :
            salutation{s_salutation},
            firstName{s_firstName},
            middleName{s_middleName},
            lastName{s_lastName} {};

/**
 * @brief Default Student class constructor with seven parameters.
 */
Student::Student(std::string _firstName, std::string _middleName, std::string _lastName,
                 std::string _sex, uint32_t _month, uint32_t _day, uint32_t _yearOfBirth, uint32_t _registrationNumber,
                 std::string _email) : fullName{Name(std::string(""), _firstName, _middleName, _lastName)}, birthDate{_month, _day, _yearOfBirth} {
                     setSex(_sex);
                     setRegistrationNumber(_registrationNumber);
                     setEmail(_email);
};

Student::~Student(void) {}

/**
 * @brief Set the sex of a student
 * 
 * @param sex "Male" or "Female"
 */
void Student::setSex(const std::string sex) {
    if (sex.compare(std::string("Male")) && sex.compare(std::string("Female")))
        std::invalid_argument("invalid sex must be either Male/Female");
    else
        this->sex = sex;
}

/**
 * @brief Set the email of a student
 * 
 * @param email email address of the student
 */
void Student::setEmail(const std::string email) {

    if (email.find('@') < 1 && email.find(".com") > 1)
        std::invalid_argument("Invalid email must be in the form <address>@<service>.com");
    else
        this->email = email;
}
