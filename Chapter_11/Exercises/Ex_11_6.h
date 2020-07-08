/**
 * @file Ex_11_6.h
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Inheritance heirarchy for students at a university definitions
 * @version 0.1
 * @date 2020-07-07
 * 
 * Exercise 11-6 Student Inheritance Hierarchy
 * 
 * Create an inheritance hierarchy for students at a university. Use student as the base
 * class of the hierarchy, the include classes UndergraduateStudent and GraduateStudent
 * that derive from Student. Continue to extend the hierarchy as much as possible.
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef EX_11_6_H
#define EX_11_6_H

#include <string>

class DOB {

    public:
        /**
         * @brief Construct a new DOB object
         * 
         */
        DOB(int = 0, int = 0, int = 0);

        /**
         * @brief Set the Day
         * 
         */
        void setDay(int);

        /**
         * @brief Get the Day
         * 
         * @return int 
         */
        int getDay() const {
            return day;
        }

        /**
         * @brief Set the Month
         * 
         */
        void setMonth(int);

        /**
         * @brief Get the Month
         * 
         * @return int 
         */
        int getMonth() const {
            return month;
        }

        /**
         * @brief Set the Year
         * 
         */
        void setYear(int);

        /**
         * @brief Get the Year
         * 
         * @return int 
         */
        int getYear() const {
            return year;
        }

        /**
         * @brief Output to DOB string e.g. 11/12/08
         * 
         * @return std::string 
         */
        std::string toString() const;

    private:
        bool isLeapYear() const;

        int day;
        int month;
        int year;

};

class Student {

    public:
        /**
         * @brief Construct a new Student object
         * 
         */
        Student(std::string, std::string, int, int, int);

        /**
         * @brief Set the First Name
         * 
         */
        void setFirstName(std::string);

        /**
         * @brief Get the First Name
         * 
         * @return std::string 
         */
        std::string getFirstName() const {
            return firstName;
        }

        /**
         * @brief Set the Last Name
         * 
         */
        void setLastName(std::string);

        /**
         * @brief Get the Last Name
         * 
         * @return std::string 
         */
        std::string getLastName() const {
            return lastName;
        }

        /**
         * @brief Get the ID number of the student
         * 
         */
        void getID(std::string);

        /**
         * @brief Get DOB information
         * 
         * @return std::string 
         */
        std::string getDOB() const {
            return dateOfBirth.toString();
        }

        /**
         * @brief Set the DOB
         * 
         * @param day 
         * @param month 
         * @param year 
         */
        void setDOB(int day, int month, int year) {
            dateOfBirth.setDay(day);
            dateOfBirth.setMonth(month);
            dateOfBirth.setYear(year);
        }

        /**
         * @brief Output Student information to a string
         * 
         * @return std::string 
         */
        std::string toString() const;

    private:
        std::string firstName;
        std::string lastName;
        DOB dateOfBirth;

        static const int daysOfMonths[];
};


class UndergraduateStudent : public Student {

    public:
        /**
         * @brief Construct a new Undergraduate Student object
         * 
         */
        UndergraduateStudent(std::string, std::string, int, int, int);

        /**
         * @brief Get the student ID
         * 
         * @return std::string 
         */
        std::string getID() {
            return id;
        }

        /**
         * @brief Output the undergraduate student information
         * 
         * @return std::string 
         */
        std::string toString() const;

    private:
        void _createID();

        std::string id;
};

class GraduateStudent : public Student {

    public:
        /**
         * @brief Construct a new Undergraduate Student object
         * 
         */
        GraduateStudent(std::string, std::string, int, int, int);

        /**
         * @brief Get the student ID
         * 
         * @return std::string 
         */
        std::string getID() {
            return id;
        }

        /**
         * @brief Output the undergraduate student information
         * 
         * @return std::string 
         */
        std::string toString() const;

    private:
        void _createID();

        std::string id;
};

class DoctoralStudent : public GraduateStudent {

    public:
        /**
         * @brief Construct a new Doctoral Student object
         * 
         */
        DoctoralStudent(std::string, std::string, int, int, int);

};

class MastersStudent : public GraduateStudent {

    public:
        /**
         * @brief Construct a new Masters Student object
         * 
         */
        MastersStudent(std::string, std::string, int, int, int);

};

#endif