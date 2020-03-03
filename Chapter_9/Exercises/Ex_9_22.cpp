/**
 * @file Ex_9_22.cpp
 *
 * @brief Implementation for the Time class to represent the time as the number of seconds
 *        since midnight.
 *
 * @author Matt Randazzo
 */

#include <iomanip>
#include <stdexcept>
#include <sstream>
#include <Ex_9_22.h>

#include <iostream>

/* Time constructor initializes each data member */
Time::Time(int hour, int minute, int second) {
    setTime(hour, minute, second);
}

/* Set new Time value using universal time */
void Time::setTime(int h, int m, int s) {
    setHour(h);
    setMinute(m);
    setSecond(s);
}

/**
 * @brief Set the number of hours since midnight
 * 
 * @param h Number of hours since midnight
 */
void Time::setHour(int h) {
    if (h >= 0 && h < HOURS_PER_DAY) {

        unsigned int hr_tmp = getHour();

        if (hr_tmp) {
            secondsSinceMidnight -= hr_tmp * SECONDS_PER_MINUTE * MINUTES_PER_HOUR;
        }
        secondsSinceMidnight += static_cast<uint32_t>(h) * SECONDS_PER_MINUTE * MINUTES_PER_HOUR;
    }
    else {
        throw std::invalid_argument("hour must be 0-23");
    }
}

/**
 * @brief Set the number of minutes since midnight
 * 
 * @param m Number of minutes since midnight
 */
void Time::setMinute(int m) {
    if (m >= 0 && m < MINUTES_PER_HOUR) {
        unsigned int hr_tmp = getHour();
        unsigned int min_tmp = getMinute();

        if (hr_tmp) {
            secondsSinceMidnight -= hr_tmp * SECONDS_PER_MINUTE * MINUTES_PER_HOUR;
        }

        if (min_tmp) {
            secondsSinceMidnight -= min_tmp * SECONDS_PER_MINUTE;
        }
        secondsSinceMidnight += m * SECONDS_PER_MINUTE;
        setHour(hr_tmp);
    }
    else {
        throw std::invalid_argument("minute must be 0-59");
    }
}

/**
 * @brief Set the number of seconds since midnight
 * 
 * @param s Number of seconds since midnight
 */
void Time::setSecond(int s) {
    if (s >= 0 && s < SECONDS_PER_MINUTE) {

        unsigned int hr_tmp = getHour();
        unsigned int min_tmp = getMinute();

        if (hr_tmp) {
            secondsSinceMidnight -= static_cast<uint32_t>(hr_tmp) * SECONDS_PER_MINUTE * MINUTES_PER_HOUR;
        }

        if (min_tmp) {
            secondsSinceMidnight -= min_tmp * SECONDS_PER_MINUTE;
        }

        secondsSinceMidnight = s;
        setMinute(min_tmp);
        setHour(hr_tmp);
    }
    else {
        throw std::invalid_argument("second must be 0-59");
    }
}

/**
 * @brief Get the number of hours since midnight
 */
unsigned int Time::getHour(void) const { 

    return secondsSinceMidnight / (SECONDS_PER_MINUTE * MINUTES_PER_HOUR);

}

/**
 * @brief Get the number of seconds minutes since midnight
 */
unsigned int Time::getMinute(void) const { 
    
    return (secondsSinceMidnight - getHour() * (SECONDS_PER_MINUTE * MINUTES_PER_HOUR)) / SECONDS_PER_MINUTE;
}

/**
 * @brief Get the number of seconds since midnight
 */
unsigned int Time::getSecond(void) const { 

    return secondsSinceMidnight - (getHour() * (SECONDS_PER_MINUTE * MINUTES_PER_HOUR) + getMinute() * SECONDS_PER_MINUTE);
}

/**
 * @brief Output time to a universal string Ex: 14:22:32
 */
std::string Time::toUniversalString() const {

    std::ostringstream output;

    output << std::setfill('0') << std::setw(2) << getHour() << ":";
    output << std::setw(2) << getMinute() << ":" << std::setw(2) << getSecond();

    return output.str();
}

/**
 * @brief Output time to a standard string Ex: 1:34:44
 */
std::string Time::toStandardString() const {
    std::ostringstream output;

    output << std::setfill('0') << std::setw(2);
    output << ((getHour() == 0 || getHour() == 12) ? 12 : getHour() % 12);
    output << ":" << std::setw(2) << getMinute() << ":";
    output << std::setw(2) << getSecond() << (getHour() < 12 ? " AM" : " PM");
    
    return output.str();
}