/**
 * Exercise 9-21 IntegerSet Class
 * 
 * Create class IntegerSet for which each object can hold integers in the range 0 through 100.
 * Represent the set internally as a vector of bool values. Element a[i] is true if integer i
 * is in the set. Element a[j] is false if integer j is not in the set. The default constructor
 * initializes a set to the so-called "empty set," i.e., a set for which all elements contain
 * false.
 * 
 * a) Provide member functions for the common set operations. For example, provide a unionOfSets
 * member function that creates a third set that is the set-theoretic union of two existing sets
 * (i.e., an element of the result is set to true if that element is true in either or both of the
 * existing sets, and an element of the result is set to false if that element is false in each 
 * of the existing sets).
 * 
 * b) Provide an intersectionOfSets member function which creates a third set which is the set-theoretic
 * intersection of two existing sets (i.e., an element of the result is set to false if that element is
 * false in either or both of the existing sets, and an element of the result is set to true if that
 * element is true in each of the existing sets).
 * 
 */

#ifndef EX_9_21_H
#define EX_9_21_H

extern "C" {
    #include <stdbool.h>
    #include <stdint.h>
}

#include <vector>
#include <array>

#define MAX_VECTOR_SIZE 101

class IntegerSet {

    public:

        explicit IntegerSet(void);
        IntegerSet(std::array<bool, MAX_VECTOR_SIZE>);

        IntegerSet unionOfSets(const IntegerSet &) const;
        IntegerSet intersectionOfSets(const IntegerSet &) const;
        
        void setInteger(const size_t, const bool);
        bool getInteger(const size_t);

    private:

        std::vector<bool> setOfInts;

};

#endif /* EX_9_21_H */