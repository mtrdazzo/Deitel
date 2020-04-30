/**
 * Exercise 9-16 Breaking Encapsulation
 *
 * The aim of encapsulation (data hiding) is to protect a class's private data from being
 * modified by outside code. However, under certain circumstances data hiding can be defeated.
 * Explain under what cirumstances data hiding can be defeated.
 *
 * One way encapsulation can be broken is by a public method returning a pointer or
 * reference to a private data member.
 *
 */

#ifndef EX_9_16_H
#define EX_9_16_H

class BrokenEncapsulation {

    public:

        BrokenEncapsulation(int _data) : data{_data} {}
        BrokenEncapsulation(void) {}
        ~BrokenEncapsulation() {}

        int* getPrivateInt1(void) { return &data; }
        int& getPrivateInt2(void) { return data; }
        int getData(void) const { return data; }

    public:

        int data{0};

};

#endif