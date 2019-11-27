#ifndef _EX_7_21_H
#define _EX_7_21_H

#include <iostream>
#include <array>
#include <vector>

#define NUM_EMPLOYEES 3

class Craftsworker {

    public:

        enum class Products {
            PRODUCT1 = 1,
            PRODUCT2,
            PRODUCT3,
            PRODUCT4
        };

        class Slip {

            public:

                Slip(std::string _m_strName, Products _m_uiProductID)
                 : m_strName{_m_strName},
                   m_uiProductID{_m_uiProductID} {}

                void printInvoice(void) const {
                    std::cout << "Employee Name: " << m_strName << std::endl;
                    std::cout << "   Product ID: Product" << static_cast<int>(m_uiProductID) << '\n' << std::endl;
                }

            private:

                std::string m_strName;
                Products m_uiProductID;

        };

        Craftsworker(std::string _m_strName) :
            m_strName{_m_strName} {
                setID();
            }

        uint8_t numJobs(void) const { return m_vJobs.size(); }

        void assignJob(Products job) {
            m_vJobs.push_back(job);
        }

        Slip sendSlip(void) {
            Products tmp{m_vJobs[numJobs() - 1]};
            m_vJobs.pop_back();
            return Slip(m_strName, tmp);
        }

        inline std::string getName(void) const { return m_strName; }
        inline uint32_t getID(void) const { return m_uiID; }

    private:

        void setID(void) {
            m_uiID = MIN_ID + rand() % MAX_ID;
        }

        static const uint16_t MIN_ID{100};
        static const uint16_t MAX_ID{1000};

        std::string m_strName;
        uint32_t m_uiID;
        std::vector<Products> m_vJobs;

};

uint8_t getNumberOfJobs(void);
Craftsworker::Products getProductType(void);


uint8_t getNumberOfJobs(void) {

    const static int min_jobs{0};
    const static int max_jobs{4};

    return min_jobs + rand() % max_jobs;
}

Craftsworker::Products getProductType(void) {

    static const uint8_t min_product_id{static_cast<uint8_t>(Craftsworker::Products::PRODUCT1)};
    static const uint8_t max_product_id{static_cast<uint8_t>(Craftsworker::Products::PRODUCT4)};

    return static_cast<Craftsworker::Products>(min_product_id + rand() % max_product_id);
}

#endif /* _EX_7_21_H */