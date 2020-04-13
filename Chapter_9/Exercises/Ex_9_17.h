/**
 * Exercise 9-17
 *
 * Can a Time class definition that includes both of the following constructors:
 *
 * Time(int h = 0, int m = 0, int s = 0);
 * Time();
 *
 * be used to default construct a Time object? If not, explain why.
 *
 * A constructor that defaults all its arguments is also a defualt constructor - that is,
 * a constructor that can be invoked with no arguments. There can only be at most one
 * default constructor per class.
 *
 */

#ifndef EX_9_17_H
#define EX_9_17_H

class Time {

    public:

        Time(int h = 1, int m = 2, int s = 3) :
            hour{h}, minute{m}, seconds{s} {};

        // Time() {}; Can only have one default constructor (no arguments) per class

        int getHour(void) const { return hour; }
        int getMinute(void) const { return minute; }
        int getSeconds(void) const { return seconds; }

    private:

        int hour;
        int minute;
        int seconds;
};

#endif