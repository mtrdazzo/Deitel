/**
 * @file Ex_12_14.h
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Class definitions of Payroll hierarchy with PieceWorker and HourlyWorker added
 * @version 0.1
 * @date 2020-07-15
 * 
 * Exercise 12-14 Payroll-System Modification
 * 
 * Modify the payroll system of Figs. 12.9-12.17 to include additional Employee subclasses Pieceworker
 * and HourlyWorker. A PieceWorker represents an employee whose pay is based on the number of pieces of
 * merchandise produced. An HourlyWorker represents an employee whose pay is based on an hourly wage and
 * the number of hours worked. Hourly workers receive overtime pay (1.5 times the hourly wage) for all
 * hours worked in excess of 40 hours.
 * 
 * Class Pieceworker should contain private data member wage (to store the employee's wage per piece) and
 * pieces (to store the number of pieces produced). Class HourlyWorker should contain private data members
 * wage (to store the employee's wage per hour) and hours (to store the hours worked). In class PieceWorker,
 * provide a concrete implementation of member function earnings that calculates the employee's earnings by
 * multiplying the number of pieces produced by the wage per piece. In class HourlyWorker, provide a concrete
 * implementation of member function earnings that calculates the employee's earnings by multiplying the
 * number of hours worked by the wage per hour. If the number of hours worked is over 40, be sure to pay the
 * HourlyWorker for the overtime hours. Add a pointer to an object of each new class into the vector or Employee
 * pointers in main. For each Employee, display its string representation and earnings.
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef EX_12_14_H
#define EX_12_14_H

#include <string>

#define SSN_LENGTH 9
#define MAX_INPUT_LENGTH 10

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

class PieceWorker : public Employee {

    public:

        /**
         * @brief Construct a new Piece Worker object
         * 
         */
        PieceWorker(const std::string &, const std::string &, const std::string &,
                    int, int, int, double, int);

        /**
         * @brief Destroy the Piece Worker object
         * 
         */
        virtual ~PieceWorker() = default;

        /**
         * @brief Set the Wage object
         * 
         */
        void setWage(double);

        /**
         * @brief Get the Wage object
         * 
         * @return double 
         */
        double getWage() const { return wage; }

        /**
         * @brief Set the Pieces object
         * 
         */
        void setPieces(int);

        /**
         * @brief Get the Pieces object
         * 
         * @return int 
         */
        int getPieces() const { return pieces; }

        /**
         * @brief Output the piece worker information to a string
         * 
         * @return std::string 
         */
        virtual std::string toString() const override;

        /**
         * @brief Calculate the earnings for the piece worker
         * 
         * @return double 
         */
        virtual double earnings() const override;

    private:
        double wage;
        int pieces;

};

#endif /* EX_12_14_H */