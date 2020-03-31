/**
 * Exercise 9-18 Constructors and Destructors
 *
 * In which order are constructors and destructors called for the objects of a class?
 *
 * Constructors are called from the inside out in order, while the destructors are called from
 * the outside in opposite order. Running Ex_9_18 shows the order of destructors/constructors
 * from the stdout output when these are called.
 *
 */

#ifndef EX_9_18_H
#define EX_9_18_H

#include <iostream>

class Name {

    public:

        Name(std::string first, std::string last) :
            firstName{first}, lastName{last} {
                std::cout << "Constructor Name object: " << firstName << " " << lastName << std::endl;
        };

        ~Name(void) {
            std::cout << "Destructor Name object: " << firstName << " " << lastName << std::endl;
        }

    public:

        std::string firstName;
        std::string lastName;
};

class Employees {

    public:

        Employees(std::string first1, std::string last1, std::string first2, std::string last2) :
            worker1{first1, last1}, worker2{first2, last2} {
                std::cout << "Constructor Employee Object" << std::endl;
        }

        ~Employees() {
            std::cout << "Destructor Employee Object" << std::endl;
        }

    private:

        Name worker1;
        Name worker2;
};

#endif