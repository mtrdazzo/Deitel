#include <Ex_9_19.h>
#include <gtest/gtest.h>

TEST(DYFormat, FirstDayOfYear) {

    Date sampleDate{1, 1, 2020};

    EXPECT_EQ(sampleDate.toOutputDY(), "001 2020");
}

TEST(DYFormat, SecondDaySecondMonth) {

    Date sampleDate{2, 2, 2020};

    EXPECT_EQ(sampleDate.toOutputDY(), "033 2020");
}

TEST(DYFormat, LastDayOfYear) {

    Date sampleDate{12, 31, 2020};

    EXPECT_EQ(sampleDate.toOutputDY(), "365 2020");
}

TEST(MDYFormat, FirstDayOfYear) {

    Date sampleDate{1, 1, 2020};

    EXPECT_EQ(sampleDate.toOutputMDY(), "01/01/20");
}

TEST(MDYFormat, SecondDaySecondMonth) {

    Date sampleDate{2, 2, 2020};

    EXPECT_EQ(sampleDate.toOutputMDY(), "02/02/20");
}

TEST(MDYFormat, LastDayOfYear) {

    Date sampleDate{12, 31, 2020};

    EXPECT_EQ(sampleDate.toOutputMDY(), "12/31/20");
}

TEST(MDYFormat, FirstDayOf1900) {

    Date sampleDate{1, 1, 1900};

    EXPECT_EQ(sampleDate.toOutputMDY(), "01/01/00");
}

TEST(FullDateFormat, FirstDayOfYear) {

    Date sampleDate{1, 1, 2020};

    EXPECT_EQ(sampleDate.toOutputFullDate(), "January 1, 2020");
}

TEST(FullDateFormat, SecondDaySecondMonth) {

    Date sampleDate{2, 2, 2020};

    EXPECT_EQ(sampleDate.toOutputFullDate(), "February 2, 2020");
}

TEST(FullDateFormat, LastDayNonLeapYear) {

    Date sampleDate{12, 31, 2020};

    EXPECT_EQ(sampleDate.toOutputFullDate(), "December 31, 2020");
}

TEST(FullDateFormat, LastDayLeapYear) {
    Date sampleDate{366, 2020};

    EXPECT_EQ(sampleDate.toOutputFullDate(), std::string("December 31, 2020"));
}

TEST(ConstructorDY, FirstOfYear) {
    Date sampleDate{1, 2020};

    EXPECT_EQ(sampleDate.getDay(), static_cast<unsigned int>(1));
    EXPECT_EQ(sampleDate.getMonth(),  static_cast<unsigned int>(1));
    EXPECT_EQ(sampleDate.getYear(),  static_cast<unsigned int>(2020));
}

TEST(ConstructorDY, SecondDaySecondMonth) {
    Date sampleDate{35, 2020};

    EXPECT_EQ(sampleDate.getDay(),  static_cast<unsigned int>(4));
    EXPECT_EQ(sampleDate.getMonth(), static_cast<unsigned int>(2));
    EXPECT_EQ(sampleDate.getYear(), static_cast<unsigned int>(2020));
}

TEST(ConstructorDY, ZeroDayLeapYear) {

    try {
        Date sampleDate{0, 2020};
    }
    catch (std::invalid_argument const & error) {
        EXPECT_STRCASEEQ(error.what(), "day must be between 1 and 366");
    }
}

TEST(ConstructorDY, OverDayLeapYear) {

    try {
        Date sampleDate{367, 2020};
    }
    catch (std::invalid_argument const & error) {
        EXPECT_STRCASEEQ(error.what(), "day must be between 1 and 366");
    }
}

TEST(ConstructorDY, ZeroDayNonLeapYear) {

    try {
        Date sampleDate{0, 2019};
    }
    catch (std::invalid_argument const & error) {
        EXPECT_STRCASEEQ(error.what(), "day must be between 1 and 365");
    }
}

TEST(ConstructorDY, OverDayNonLeapYear) {

    try {
        Date sampleDate{366, 2019};
    }
    catch (std::invalid_argument const & error) {
        EXPECT_STRCASEEQ(error.what(), "day must be between 1 and 365");
    }
}

TEST(ConstructorDY, FirstDayThirdMonthNonLeapYear) {
    Date sampleDate{60, 2019};

    EXPECT_EQ(sampleDate.getDay(), static_cast<unsigned int>(1));
    EXPECT_EQ(sampleDate.getMonth(), static_cast<unsigned int>(3));
    EXPECT_EQ(sampleDate.getYear(), static_cast<unsigned int>(2019));
}

TEST(ConstructorDY, FirstDayThirdMonthLeapYear) {
    Date sampleDate{61, 2020};

    EXPECT_EQ(sampleDate.getDay(), static_cast<unsigned int>(1));
    EXPECT_EQ(sampleDate.getMonth(), static_cast<unsigned int>(3));
    EXPECT_EQ(sampleDate.getYear(), static_cast<unsigned int>(2020));
}

TEST(ConstructorDY, LastDayLeapYear) {
    Date sampleDate{366, 400};

    EXPECT_EQ(sampleDate.getDay(), static_cast<unsigned int>(31));
    EXPECT_EQ(sampleDate.getMonth(), static_cast<unsigned int>(12));
    EXPECT_EQ(sampleDate.getYear(), static_cast<unsigned int>(400));
}

TEST(DefaultConstructor, GetCurrentTime) {

    Date sampleDate;
    time_t todaySeconds;
    struct tm * timeInfo;

    time(&todaySeconds);

    timeInfo = localtime( &todaySeconds );

    EXPECT_EQ(sampleDate.getMonth(), static_cast<unsigned int>(timeInfo->tm_mon));
    EXPECT_EQ(sampleDate.getYear(), static_cast<unsigned int>(timeInfo->tm_year));
    EXPECT_EQ(sampleDate.getDay(), static_cast<unsigned int>(timeInfo->tm_mday));
}
