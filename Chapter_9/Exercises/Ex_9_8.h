/**
 * @file Ex_9_8.h
 *
 * @brief Interface to the Student object class.
 * 
 * @mainpage Exercise 9-8 Student Class
 *
 * Many universities have information systems which track their students' academic records. Create a class called
 * Student that can be used in such systems. The class should represent a sutdent and should have data members
 * to represent each student's firstName, middleName, lastName, sex, yearOfBirth, registrationNumber, and email.
 * Decide on teh appropriate data type for each data member. Provide a constructor which takes seven parameters
 * and initializes the seven data members. Also provide set and get functions for each data member.
 *
 * @author Matt Randazzo
 */

#ifndef EX_9_8_H
#define EX_9_8_H

#include <string>

class Student {

    public:

        /* Constructor and Destructor */
        Student(std::string firstName, std::string middleName, std::string lastName,
                std::string sex, uint32_t yearOfBirth, uint32_t registrationNumber,
                std::string email);
        ~Student();

        /* Getters and Setters */
        std::string getFirstName(void) const  { return firstName; }
        std::string getMiddleName(void) const { return middleName; }
        std::string getLastName(void) const   { return lastName; }
        std::string getSex(void) const { return sex; }
        uint32_t getYearOfBirth(void) const { return yearOfBirth; }
        uint32_t getRegistrationNumber(void) const { return registrationNumber; }
        std::string getEmail(void) const { return email; }

        void setFirstName(const std::string firstName) { this->firstName = firstName; }
        void setMiddleName(const std::string middleName) { this->middleName = middleName; }
        void setLastName(const std::string lastName) { this->lastName = lastName; }

        void setSex(const std::string);
        void setYearOfBirth(const uint32_t);
        void setEmail(const std::string);
        void setRegistrationNumber(const uint32_t registrationNumber) { this->registrationNumber = registrationNumber; }

    private:

        std::string firstName;
        std::string middleName;
        std::string lastName;
        std::string sex;
        uint32_t    yearOfBirth;
        uint32_t    registrationNumber;
        std::string email;
};

#endif