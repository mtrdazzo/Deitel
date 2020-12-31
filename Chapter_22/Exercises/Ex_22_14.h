/**
 * @file Ex_22_14.h
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Percentage digits letters
 * @version 0.1
 * @date 2020-12-30
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef _EX_22_14_INCLUDE
#define _EX_22_14_INCLUDE

struct Percentage {
    double percentNum{0.0};
    double percentAlpha{0.0};
};

Percentage CalculatePercentages(void);

#endif // _EX_22_14_INCLUDE