/**
 * @file Ex_9_22.h
 *
 * @brief Interface to the Time object clas to represent the time as the number of
 *        seconds after midnight.
 * 
 * @mainpage Exercise 9-22 Time Class Modification
 * 
 * It would be perfectly resonable for the Time class of Figs. 9.5-9.6 to represent
 * the time internally as the number of seconds since midnight rather than the three
 * integer values hour, minute, and second. Clients could use the same public member
 * functions and get the same results. Modify the Time class of Fig. 9.5 to implement
 * the time as the number of seconds since midnight and show that there is no visible
 * change in functionality to the clients of the class. (This exercise nicely
 * demonstrates the virtues of implementation hiding.)
 * 
 * @author Matt Randazzo
 */

#ifndef EX_9_22_H
#define EX_9_22_H

#include <string>

#define SECONDS_PER_MINUTE 60
#define MINUTES_PER_HOUR 60
#define HOURS_PER_DAY 24

class Time {

    public:

        Time(int = 0, int = 0, int = 0); // default constructor

        // set functions
        void setTime(int, int, int);
        void setHour(int);
        void setMinute(int);
        void setSecond(int);

        // get functions
        unsigned int getHour() const;
        unsigned int getMinute() const;
        unsigned int getSecond() const;

        std::string toUniversalString() const;
        std::string toStandardString() const;

    private:

        uint32_t secondsSinceMidnight{0};
};

#endif /* EX_9_22_H */