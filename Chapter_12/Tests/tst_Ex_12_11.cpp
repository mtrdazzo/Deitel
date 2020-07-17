/**
 * @file tst_Ex_12_11.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Testing Employee class hierarchy
 * @version 0.1
 * @date 2020-07-14
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <vector>
#include <typeinfo>
#include <time.h>
#include <gtest/gtest.h>
#include <Ex_12_11.h>

time_t theTime = time(nullptr);
struct tm *aTime = localtime(&theTime);
int currentMonth = aTime->tm_mon + 1;

/**
 * @brief Test polymorphism using pointers of base class Employee. Add $100 bonus to salaried employees and
 *        the base salary of base plus commission employees if their birth month is this month.
 * 
 */
TEST(EmployeeConstructor, DynamicPolymorphism) {

    const int bonus{100};
    const double baseSalary{350.0};

    std::vector<Employee*> employees;

    SalariedEmployee salaryEmployee1{"John", "Doe", "123456789", currentMonth, 12, 1990, baseSalary};
    SalariedEmployee salaryEmployee2{"John", "Doe", "123456789", (currentMonth + 1) > 12 ? currentMonth - 1 : currentMonth + 1 , 12, 1990, baseSalary};

    CommissionEmployee commissionEmployee{"Jane", "Do", "987654321", 3, 14, 1992, 42.3, 0.67};
    BasePlusCommissionEmployee basePlusCommissionEmployee1{"JJ", "Doe", "987654322", currentMonth, 15, 1988, 43.4, 0.63, baseSalary};
    BasePlusCommissionEmployee basePlusCommissionEmployee2{"JJ", "Doe", "987654322", (currentMonth + 1) > 12 ? currentMonth - 1 : currentMonth + 1, 15, 1988, 43.4, 0.63, baseSalary};

    employees.push_back(&salaryEmployee1);
    employees.push_back(&salaryEmployee2);
    employees.push_back(&commissionEmployee);
    employees.push_back(&basePlusCommissionEmployee1);
    employees.push_back(&basePlusCommissionEmployee2);

    for (Employee * employee : employees) {

        if (employee->getBirthDate().getMonth() == currentMonth) {
            BasePlusCommissionEmployee* commissionEmployeePtr = dynamic_cast<BasePlusCommissionEmployee*>(employee);
            SalariedEmployee* salariedEmployeePtr = dynamic_cast<SalariedEmployee*>(employee);
        
            if (commissionEmployeePtr != nullptr)
                commissionEmployeePtr->setBaseSalary(commissionEmployeePtr->getBaseSalary() + bonus);
            else if (salariedEmployeePtr != nullptr)
                salariedEmployeePtr->setWeeklySalary(salariedEmployeePtr->getWeeklySalary() + bonus);
        }
    }

    /* same month, adds bonus */
    EXPECT_EQ(employees[0]->toString(), salaryEmployee1.toString());
    EXPECT_EQ(employees[0]->earnings(), bonus + baseSalary);

    /* different month, no bonus */
    EXPECT_EQ(employees[1]->toString(), salaryEmployee2.toString());
    EXPECT_EQ(employees[1]->earnings(), baseSalary);

    /* commission employee does not change */
    EXPECT_EQ(employees[2]->toString(), commissionEmployee.toString());

    /* same month, adds bonus */
    EXPECT_EQ(employees[3]->toString(), basePlusCommissionEmployee1.toString());
    EXPECT_EQ(employees[3]->earnings(), (bonus + baseSalary) + basePlusCommissionEmployee1.getGrossSales() * basePlusCommissionEmployee1.getCommissionRate());

    /* different month, no bonus */
    EXPECT_EQ(employees[4]->toString(), basePlusCommissionEmployee2.toString());
    EXPECT_EQ(employees[4]->earnings(), baseSalary + basePlusCommissionEmployee2.getGrossSales() * basePlusCommissionEmployee2.getCommissionRate());
}