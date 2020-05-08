// Fig. 10.7: Date.cpp
// Date class member and friend function definitions

#include <iostream>
#include <string>
#include "Date.h"

using namespace std;

// initialize static member; one classwide copy
const array<unsigned int, 13> Date::days {
    0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

// Date constructor
Date::Date(int month, int day, int year) {
    setDate(month, day, year);
}

// set month, day, year
void Date::setDate(unsigned int mm, unsigned int dd, unsigned int yy) {

    if (mm >= 1 && mm <= 12) {
        month = mm;
    }
    else {
        throw invalid_argument("Month must be 1-12");
    }

    if (yy >= 1900 && yy <= 2100) {
        year = yy;
    }
    else {
        throw invalid_argument("Year must be >= 1900 and <= 2100");
    }

    // test for a leap year
    if ((mm == 2 && leapYear(year) && dd >= 1 && dd <= 29) ||
        (dd >= 1 && dd <= days[mm])) {
            day = dd;
    }
    else {
        throw invalid_argument("Day is out of range for current month and year");
    }
}

// overloaded prefix increment operator
Date& Date::operator++() {
    helpIncrement(); // increment date
    return *this; // reference return to create an lvalue
}

// overloaded postfix increment operator; not that the
// dummy integer parameter does not hve a parameter name
Date Date::operator++(int) {
    Date temp{*this}; // hold current state of object
    helpIncrement();

    // return unincremented, saved, temporary object
    return temp; // value return; not a reference return
}

// add specified number of days to date
Date& Date::operator+=(unsigned int additionalDays) {
    for (unsigned int i = 0; i < additionalDays; i++)
        helpIncrement();

    return *this; // enables cascading
}

// if the year is a leap year, return true; otherwise, return false
bool Date::leapYear(int yy) {
    return yy % 400 == 0 || \
           ( yy % 100 != 0 && \
             yy % 4 == 0 );
}

// determine whether the day is the last day of the month
bool Date::endOfMonth(unsigned int testDay) const {
    if (month == 2 && leapYear(year)) {
        return testDay == 29;
    }
    else {
        return testDay == days[month];
    }
}

// function to help increment the date
void Date::helpIncrement() {
    //day is not the end of the month
    if (!endOfMonth(day)) {
        ++day;
    }
    else {
        if (month < 12) { // day is end of the month and month < 12
            ++month;
            day = 1; // first day of next month
        }
        else {
            ++year;     // increment year
            month = 1;  // first month of the year
            day = 1;   // first day of the year
        }
    }
}

// overloaded output operator
ostream& operator<<(ostream& output, const Date& d) {

    static string monthName[13] = { "", "January", "February", "March",
    "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    output << monthName[d.month] << " " << d.day << ", " << d.year;

    return output;
}

int main() {

    Date d1{12, 27, 2010}; // December 27, 2010
    Date d2; // January 1, 1900

    cout << "d1 is " << d1 << "\nd1 is " << d2;
    cout << "\n\nd2 += 7 is " << (d2 += 7);

    d2.setDate(2, 28, 2008);
    cout << "\n\n d2 is " << d2;
    cout << "\n++d2 is " << ++d2 << " (leap year allows 29th)";

    Date d3{7, 13, 2010};

    cout << "\n\nTesting the prefix increment operator:\n"
        << "  d3 is " << d3 << endl;
    cout << "++d3 is " << ++d3 << endl;
    cout << "  d3 is " << d3;

    cout << "\n\nTesting the prefix increment operator:\n"
        << "  d3 is " << d3 << endl;
    cout << "d3++ is " << d3++ << endl;
    cout << "  d3 is " << d3;

    cout << endl;
    return EXIT_SUCCESS;
}