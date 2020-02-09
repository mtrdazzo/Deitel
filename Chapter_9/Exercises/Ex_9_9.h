/**
 * @file Ex_9_9.h
 *
 * @brief Interface to the Student object class.
 * 
 * @mainpage Exercise 9-9 Improving Student Class
 *
 * Improve the Student class in the previous exercise by using the concept of composition. Replace the three
 * data members used to represent names with a data member of the Name class you created in Exercise 9.7. In
 * addition, replace the data member used to represent th eyear of birth of a student with a full date of
 * birth by making use of class Date of Figs 9.14-9.15. Note that using a Name data member calls for a
 * default constructor in class Name.
 *
 * @author Matt Randazzo
 */

#ifndef EX_9_9_H
#define EX_9_9_H

#include <Ex_9_7.h>
#include <sstream>

class Student {

    public:

        class Date {

            public:
                explicit Date(unsigned int m, unsigned int d, unsigned int y) {
                    setYear(y);
                    setMonth(m);
                    setDay(d);
                }

                std::string toString(void) const {
                    std::ostringstream output;

                    output << month << '/' << day << '/' << year;

                    return output.str();
                }

                unsigned int getYear(void) const { return year; }
                unsigned int getMonth(void )const { return month; }
                unsigned int getDay(void) const { return day; }

                void setYear(unsigned int _year) {
                    if (_year < 1900 || _year > 2020)
                        std::invalid_argument("Invalid year of birth, must be (1900-2020)");
                    else
                        year = _year;
                }

                void setDay(unsigned int _day) {
                    if (month % 2)
                        if (_day > 0 && _day <= 31)
                            day = _day;
                        else
                            std::invalid_argument("Invalid day, must be (1-31) for this month");
                    else {
                        if (month == 2 && year % 400 && _day > 29)
                            std::invalid_argument("Invalid day, must be (1-29) for this month");
                        if (_day > 0 && _day <= 30)
                            day = _day;
                        else
                            std::invalid_argument("Invalid day, must be (1-30) for this month");
                    }
                }

                void setMonth(unsigned int _month) {
                    if (_month > 0 && _month <= 12)
                        month = _month;
                    else
                        std::invalid_argument("Invalid month of year, must be (1-12)");
                }

            private:

                unsigned int month;
                unsigned int day;
                unsigned int year;
        };

        /* Constructor and Destructor */
        Student(std::string firstName, std::string middleName, std::string lastName,
                std::string sex, uint32_t month, uint32_t day, uint32_t yearOfBirth, uint32_t registrationNumber,
                std::string email);
        ~Student();

        /* Getters and Setters */
        std::string getFirstName(void) const  { return this->fullName.getFirstName(); }
        std::string getMiddleName(void) const { return this->fullName.getMiddleName(); }
        std::string getLastName(void) const   { return this->fullName.getLastName(); }
        std::string getSex(void) const { return sex; }
        uint32_t getYearOfBirth(void) const { return birthDate.getYear(); }
        uint32_t getRegistrationNumber(void) const { return registrationNumber; }
        std::string getEmail(void) const { return email; }
        unsigned int getMonth(void) const { return birthDate.getMonth(); }
        unsigned int getDay(void) const { return birthDate.getDay(); }

        void setFirstName(const std::string firstName) { this->fullName.setFirstName(firstName); }
        void setMiddleName(const std::string middleName) { this->fullName.setMiddleName(middleName); }
        void setLastName(const std::string lastName) { this->fullName.setLastName(lastName); }

        void setSex(const std::string);
        void setYearOfBirth(const uint32_t) { }
        void setEmail(const std::string);
        void setRegistrationNumber(const uint32_t registrationNumber) { this->registrationNumber = registrationNumber; }

    private:

        Name        fullName;
        std::string sex;
        Date        birthDate;
        uint32_t    registrationNumber;
        std::string email;
};

#endif
