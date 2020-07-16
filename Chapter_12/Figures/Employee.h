/**
 * @file Employee.h
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Class definition for Employee class
 * @version 0.1
 * @date 2020-07-14
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

class Employee {

    public:

        Employee(const std::string&, const std::string&, const std::string&);

        virtual ~Employee() = default; /* compiler generates virtual destructor */

        void setFirstName(const std::string&);
        std::string getFirstName() const;

        void setLastName(const std::string&);
        std::string getLastName() const;

        void setSocialSecurityNumber(const std::string&);
        std::string getSocialSecurityNumber() const;

        /* pure virutal function makes Employee an abstract base class */
        virtual double earnings() const = 0; /* pure virtual */
        virtual std::string toString() const; /* virtual */
    
    private:
        std::string firstName;
        std::string lastName;
        std::string socialSecurityNumber;

};

#endif