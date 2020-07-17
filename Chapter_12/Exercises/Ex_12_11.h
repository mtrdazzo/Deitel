/**
 * @file Ex_12_11.h
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2020-07-14
 * 
 * Exercise 12-11 Payroll-System Modification
 * 
 * Modify the payroll system of Figs. 12.9-12.17 to include private data member birthDate in class Employee. Use class
 * Date from Figs 10.6-10.7 to represent an employee's birthday. Assume that payroll is processed once per month. Create
 * a vector of Employee pointers to store the various employee objects. In a loop, calculate the payroll for each Employee
 * (polymorphically), and add a $100.00 bonus to the person's payroll amount if the current month is the month in which the
 * Employee's birthday occurs.
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef EX_12_11_H
#define EX_12_11_H

#include <string>
#define SSN_LENGTH 9

class Date {

    public:
        /**
         * @brief Construct a new Date object
         * 
         */
        Date(int = 0, int = 0, int = 0);

        /**
         * @brief Set the Day
         * 
         */
        void setDay(int);

        /**
         * @brief Get the Day
         * 
         * @return int 
         */
        int getDay() const {
            return day;
        }

        /**
         * @brief Set the Month
         * 
         */
        void setMonth(int);

        /**
         * @brief Get the Month
         * 
         * @return int 
         */
        int getMonth() const {
            return month;
        }

        /**
         * @brief Set the Year
         * 
         */
        void setYear(int);

        /**
         * @brief Get the Year
         * 
         * @return int 
         */
        int getYear() const {
            return year;
        }

        /**
         * @brief Output to Date string e.g. 11/12/08
         * 
         * @return std::string 
         */
        std::string toString() const;

    private:
        bool isLeapYear() const;

        int day;
        int month;
        int year;
};

class Employee {

    public:

        /**
         * @brief Construct a new Employee object
         * 
         */
        Employee(const std::string&, const std::string&, const std::string&, int, int, int);

        /**
         * @brief Destroy the Employee object
         * 
         */
        virtual ~Employee() = default;

        /**
         * @brief Set the first name
         * 
         */
        void setFirstName(const std::string &);

        /**
         * @brief Get the first name
         * 
         * @return std::string 
         */
        std::string getFirstName() const { return firstName; }

        /**
         * @brief Set the last name
         * 
         */
        void setLastName(const std::string &);

        /**
         * @brief Get the last name
         * 
         * @return std::string 
         */
        std::string getLastName() const { return lastName; }

        /**
         * @brief Set the Social Security Number
         * 
         */
        void setSocialSecurityNumber(const std::string &);

        /**
         * @brief Get the Social Security Number
         * 
         * @return std::string 
         */
        std::string getSocialSecurityNumber() const { return socialSecurityNumber; }

        /**
         * @brief Get the birth date
         * 
         * @return Date 
         */
        Date getBirthDate() const { return birthDate; }

        /**
         * @brief Set the birth date
         * 
         */
        void setBirthDate(int month, int day, int year) {
            birthDate = Date(month, day, year);
        }

        /**
         * @brief Output the employee's information to a string
         * 
         * @return std::string 
         */
        virtual std::string toString() const;

        /**
         * @brief Pure virtual function to calculate earnings
         * 
         * @return double 
         */
        virtual double earnings() const = 0;

    private:
        std::string firstName;
        std::string lastName;
        std::string socialSecurityNumber;
        Date birthDate;
};

class SalariedEmployee : public Employee {

    public:
        SalariedEmployee(const std::string &, const std::string &, const std::string &,
                         int, int, int, double = 0.0);
        
        virtual ~SalariedEmployee() = default;

        /**
         * @brief Set the weekly salary
         * 
         */
        void setWeeklySalary(double);

        /**
         * @brief Get the weekly salary
         * 
         * @return double 
         */
        double getWeeklySalary() const { return weeklySalary; }

        /**
         * @brief Get the earnings
         * 
         * @return double 
         */
        virtual double earnings() const override;

        /**
         * @brief Output the salaried employee information to a string
         * 
         * @return std::string 
         */
        virtual std::string toString() const override;

    private:
        double weeklySalary;

};

class CommissionEmployee : public Employee {

    public:

        /**
         * @brief Construct a new Commission Employee object
         * 
         */
        CommissionEmployee(const std::string &, const std::string &, const std::string &,
                         int, int, int, double = 0.0, double = 0.0);
        
        /**
         * @brief Destroy the Commission Employee object
         * 
         */
        virtual ~CommissionEmployee() = default;

        /**
         * @brief Set the gross sales
         * 
         */
        void setGrossSales(double);

        /**
         * @brief Get the gross sales
         * 
         * @return double 
         */
        double getGrossSales() const { return grossSales; }

        /**
         * @brief Set the commission rate
         * 
         */
        void setCommissionRate(double);

        /**
         * @brief Get the commission rate
         * 
         * @return double 
         */
        double getCommissionRate() const { return commissionRate; }

        /**
         * @brief Return the earnings for the commission employee
         * 
         * @return double 
         */
        virtual double earnings() const override;

        /**
         * @brief Output the commission employee information to a string
         * 
         * @return std::string 
         */
        virtual std::string toString() const override;

    private:
        double grossSales;
        double commissionRate;
};

class BasePlusCommissionEmployee : public CommissionEmployee {

    public:

        /**
         * @brief Construct a new Base Plus Commission Employee object
         * 
         */
        BasePlusCommissionEmployee(const std::string &, const std::string &, const std::string &,
                                   int, int, int, double, double, double);

        /**
         * @brief Destroy the Base Plus Commission Employee object
         * 
         */
        virtual ~BasePlusCommissionEmployee() = default;

        /**
         * @brief Set the base salary
         * 
         */
        void setBaseSalary(double);

        /**
         * @brief Get the base salary
         * 
         * @return double 
         */
        double getBaseSalary() const { return baseSalary; }

        /**
         * @brief Return the earnings for the base plus commission employee
         * 
         * @return double 
         */
        virtual double earnings() const override;

        /**
         * @brief Output the base plus commission information to a string
         * 
         * @return std::string 
         */
        virtual std::string toString() const override;

    private:
        double baseSalary;
};

#endif /* EX_12_11_H */