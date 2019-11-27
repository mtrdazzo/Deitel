/**
 * Exercise 7-21 Workshop Summary
 *
 * Use a two-dimensional array to solve the following problem. A craft workshop has three craftspeople
 * (1 to 3) wo produce four different products (1 to 4). Once a day, each craftsperson passes in a
 * slip for each different type of product completed. Each slip contains the following:
 *
 *  a) The craft-person's number
 *  b) The product number
 *  c) The quantity of items completed
 *
 * Thus each craftsperson passes in between 0 and 4 production slips per day. Write a program that will
 * read in the information as supplied on each individual production slip and summarize the total items
 * manufactured by a craftsperson by product.
 *
 */

#include <iostream>
#include <cstdlib>
#include "Ex_7_21.h"

int main(int argc, char **argv) {

    srand(static_cast<unsigned int>(time(0)));

    std::array<Craftsworker, NUM_EMPLOYEES> employees{Craftsworker("Matt"),
                                                      Craftsworker("Danielle"),
                                                      Craftsworker("Dom")};

    uint8_t num_jobs;
    uint8_t current_job{0};

    for (Craftsworker& employee : employees) {
        num_jobs = getNumberOfJobs();
        while (num_jobs--) {
            employee.assignJob(getProductType());
        }
    }

    current_job = 1;
    for (Craftsworker& employee : employees) {
        while (employee.numJobs()) {
            std::cout << "\nJob Number: " << current_job << std::endl;
            employee.sendSlip().printInvoice();
            ++current_job;
        }
    }

    return EXIT_SUCCESS;
}
