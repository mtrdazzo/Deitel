/**
 * @file Ex_9_8.cpp
 *
 * @brief Implementation for the Student class to store a student's data.
 *
 * @author Matt Randazzo
 */

#include <Ex_9_8.h>
#include <stdexcept>

/**
 * @brief Default Student class constructor with seven parameters.
 */
Student::Student(std::string _firstName, std::string _middleName, std::string _lastName,
                 std::string _sex, uint32_t _yearOfBirth, uint32_t _registrationNumber,
                 std::string _email) {
                     setFirstName(_firstName);
                     setMiddleName(_middleName);
                     setLastName(_lastName);
                     setSex(_sex);
                     setYearOfBirth(_yearOfBirth);
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
 * @brief Set the birth year of a student
 * 
 * @param yearOfBirth birth year of the student
 */
void Student::setYearOfBirth(const uint32_t yearOfBirth) {
    if (yearOfBirth < 1900 || yearOfBirth > 2020)
        std::invalid_argument("Invalid year of birth, must be (1900-2020)");
    else
        this->yearOfBirth = yearOfBirth;
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
