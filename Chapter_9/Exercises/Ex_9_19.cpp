#include <array>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <stdexcept>
#include <Ex_9_19.h>
#include <ctime>

const std::array<int, Date::monthsPerYear+1> Date::daysPerMonth = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

Date::Date(void) {
    time_t current_time;
    struct tm *timeinfo;
    time(&current_time);

    timeinfo = localtime(&current_time);

    month = timeinfo->tm_mon;
    year  = timeinfo->tm_year;
    day   = timeinfo->tm_mday;
}

Date::Date(unsigned int mn, unsigned int dy, unsigned int yr) {
    setMonth(mn);
    setYear(yr);
    day = checkDay(dy);
}

Date::Date(unsigned int day, unsigned int year) {

    unsigned int month{1};
    setYear(year);

    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
        if (!day || day > daysPerLeapYear)
            throw std::invalid_argument("day must be between 1 and 366");
    }
    else {
        if (!day || day > daysPerNonLeapYear)
            throw std::invalid_argument("day must be between 1 and 365");
    }

    while ((day - daysPerMonth[month] < day) && day - daysPerMonth[month] > 0) {
        if (month == 2 && _isLeapYear(year))
            day -= daysPerMonth[month++] + 1;
        else
            day -= daysPerMonth[month++];
    }

    this->day = day;
    this->month = month;
}

bool Date::_isLeapYear(const unsigned int year) const {
    return (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0));
}

void Date::setYear(unsigned int year) {
    if (!year)
        throw std::invalid_argument("year must be nonzero");
    this->year = year;
}

void Date::setMonth(unsigned int month) {
    if (month > monthsPerYear)
        throw std::invalid_argument("month must be between 1 and 12");
    this->month = month;
}

std::string Date::toOutputDY() const {
    std::ostringstream output;

    int dayOfYear{0};

    for (unsigned int month_tmp{1}; month_tmp < month; month_tmp++)
        dayOfYear += daysPerMonth[month_tmp];

    dayOfYear += day;

    output << std::setw(3) << std::setfill('0') << dayOfYear << ' ';
    output << std::setw(4) << year;
    return output.str();
}


std::string Date::toOutputMDY() const {
    std::ostringstream output;

    output << std::setw(2) << std::setfill('0') << month << '/';
    output << std::setw(2) << day << '/';
    output << std::setw(2) << year % 100;
    return output.str();
}

std::string Date::toOutputFullDate() const {
    static const std::array<std::string, monthsPerYear + 1> monthNames = { " ",
             "January", "February", "March", "April", "May", "June",
             "July", "August", "September", "October", "November", "December"};

    std::ostringstream output;

    output << monthNames[month] << ' ';
    output << day << ", ";
    output << year;

    return output.str();
}

unsigned int Date::checkDay(int testDay) const {

    if (testDay > 0 && testDay <= daysPerMonth[month])
        return testDay;

    if (month == 2 && testDay == 29 && _isLeapYear(year))
        return testDay;

    throw std::invalid_argument("Invalid day for current month and year");
}