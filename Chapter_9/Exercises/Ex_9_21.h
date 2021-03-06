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
 * c) Provide an insertElement function that places a new integer k into a set by setting a[k] to true.
 * Provide a deleteElement member function that deletes integer m by setting a[m] to false.
 * 
 * d) Provide a toString member function that returns a set as a string containing a list of numbers
 * separated by spaces. Include only those elements that are present in the set (i.e., their position in
 * the vector has a value of true). Return --- for an empty set.
 * 
 * e) Provide an isEqualTo member function that  determines whether two sets are equal.
 * 
 * f) Provide an additional constructor that receives an array of integers, and uses the array to
 * intialize a set object.
 * 
 * Now write a driver program to test your IntegerSet class. Intantiate several IntegerSet objects. Test
 * that all your member functions work properly.
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
#include <sstream>

#define MAX_VECTOR_SIZE 101

class IntegerSet {

    public:

        explicit IntegerSet(void);
        IntegerSet(const uint8_t *, const size_t);

        IntegerSet unionOfSets(const IntegerSet &) const;
        IntegerSet intersectionOfSets(const IntegerSet &) const;
        bool isEqualTo(const IntegerSet &) const;
        std::string toString(void) const;

        void insertInteger(const size_t);
        void deleteInteger(const size_t);
        bool getInteger(const size_t);

    private:

        std::vector<bool> setOfInts;

};

#endif /* EX_9_21_H */