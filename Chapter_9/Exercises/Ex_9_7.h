/**
 * @file Ex_9_7.h
 *
 * @brief Interface to the Name object class.
 *
 * @mainpage Exercise 9-7 Name Class
 *
 * A name can find uses in many applications that involve people, for example payroll and banking.
 * Create a class called Name that contains data members of type string called firstName, middleName,
 * lastName, and salutation. Add a constructor that takes four parameters which are used to initialize
 * the four data members and member function called toString that returns the person's full name in the
 * form "salutation lastName, firstName middleName". Finally, add set and get functions for all data
 * members.
 *
 * @author Matt Randazzo
 */

#ifndef EX_9_7_H
#define EX_9_7_H

#include <string>

class Name {

    public:

        /* Class constructor */
        Name(std::string, std::string, std::string, std::string);

        /* Output to string */
        std::string toString(void);

        /* Setters */
        void setFirstName(std::string firstName) { this->firstName = firstName; }
        void setMiddleName(std::string middleName) { this->middleName = middleName; }
        void setLastName(std::string lastName) { this->lastName = lastName; }
        void setSalutation(std::string salutation) { this->salutation = salutation; }

        /* Getters */
        std::string getFirstName(void) const { return firstName; }
        std::string getLastName(void) const { return lastName; }
        std::string getMiddleName(void) const { return middleName; }
        std::string getSalutation(void) const { return salutation; }

    private:

        std::string salutation;
        std::string firstName;
        std::string middleName;
        std::string lastName;

};

#endif