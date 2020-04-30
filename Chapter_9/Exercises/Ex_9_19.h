/**
 * Exercise 9-19 Date Class Modification
 *
 * Modify class Date to have the following capabilities:
 *
 * a) Output the date in multiple formats such as
 *
 *   DDD YYYY
 *   MM/DD/YY
 *   June 14, 1992
 *
 * b) Use overloaded constructors to create Date objects initialized with dates of the
 *    formats in part (a).
 *
 * C) Create a date constructor that reads the system date using the standard library functions
 *    of the <ctime> header and sets the Date members.
 *
 */

#ifndef EX_9_19_H
#define EX_9_19_H

#include <string>
#include <array>

class Date {

    public:
        static const unsigned int monthsPerYear{12}; //months in a year
        static const unsigned int daysPerNonLeapYear{365};
        static const unsigned int daysPerLeapYear{366};
        explicit Date(unsigned int, unsigned int, unsigned int);
        Date();
        Date(unsigned int, unsigned int);
        Date(std::string);
        std::string toOutputDY() const;
        std::string toOutputMDY() const; // date string in month/day/year format
        std::string toOutputFullDate() const;

        void setMonth(unsigned int);
        void setYear(unsigned int);

        unsigned int getMonth(void) const { return month; }
        unsigned int getDay(void) const { return day; }
        unsigned int getYear(void) const { return year; }

    private:
        unsigned int month; // 1-12 (January-December)
        unsigned int day; // 1-31 based on month
        unsigned int year; // any year

        static const std::array<int, monthsPerYear + 1> daysPerMonth;
        bool _isLeapYear(const unsigned int) const;

        // utility function to check if day is proper for month and year
        unsigned int checkDay(int) const;
};

#endif