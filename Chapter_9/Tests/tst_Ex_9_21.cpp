#include <Ex_9_21.h>
#include <gtest/gtest.h>

TEST(DefaultConstructor, AllElementsFalse) {

    IntegerSet empty_set;

    for (size_t index{0}; index < MAX_VECTOR_SIZE; index++)
        EXPECT_FALSE(empty_set.getInteger(index));
}

TEST(insertInteger, insertValidIntegers) {

    IntegerSet empty_set;

    empty_set.insertInteger(0);
    empty_set.insertInteger(100);
    empty_set.insertInteger(50);

    EXPECT_TRUE(empty_set.getInteger(0));
    EXPECT_TRUE(empty_set.getInteger(100));
    EXPECT_TRUE(empty_set.getInteger(50));
}

TEST(insertInteger, insertInvalidInteger) {

    IntegerSet empty_set;

    try {
        empty_set.insertInteger(MAX_VECTOR_SIZE);
    } catch (std::invalid_argument const &err) {
        EXPECT_STRCASEEQ(err.what(), "invalid index, must be between 0 and 100 inclusive");
    } 
}

TEST(insertInteger, deleteValidIntegers) {

    IntegerSet empty_set;

    empty_set.insertInteger(0);
    empty_set.insertInteger(100);
    empty_set.insertInteger(50);

    EXPECT_TRUE(empty_set.getInteger(0));
    EXPECT_TRUE(empty_set.getInteger(100));
    EXPECT_TRUE(empty_set.getInteger(50));

    empty_set.deleteInteger(0);
    empty_set.deleteInteger(100);
    empty_set.deleteInteger(50);
    
    EXPECT_FALSE(empty_set.getInteger(0));
    EXPECT_FALSE(empty_set.getInteger(100));
    EXPECT_FALSE(empty_set.getInteger(50));
}

TEST(insertInteger, deleteInvalidInteger) {

    IntegerSet empty_set;

    try {
        empty_set.deleteInteger(MAX_VECTOR_SIZE);
    } catch (std::invalid_argument const &err) {
        EXPECT_STRCASEEQ(err.what(), "invalid index, must be between 0 and 100 inclusive");
    } 
}

TEST(UnionOfSets, twoEmptySets) {

    IntegerSet empty_set1;
    IntegerSet empty_set2;

    IntegerSet empty_set3 = empty_set1.unionOfSets(empty_set2);

    for (size_t index{0}; index < MAX_VECTOR_SIZE; index++)
        EXPECT_FALSE(empty_set3.getInteger(index));
}

TEST(UnionOfSets, oneEmptySet) {

    uint8_t set1[] = {1, 6, 10, 50, 33};
    uint8_t set2[] = {12, 100, 75, 51, 99};

    IntegerSet empty_set1;
    IntegerSet empty_set2;

    for (size_t index{0}; index < sizeof(set1) / sizeof(set1[0]); index++)
        empty_set1.insertInteger(set1[index]);

    IntegerSet empty_set3 = empty_set1.unionOfSets(empty_set2);

    for (size_t index{0}; index < sizeof(set1) / sizeof(set1[0]); index++)
        EXPECT_TRUE(empty_set3.getInteger(set1[index]));

    for (size_t index{0}; index < sizeof(set2) / sizeof(set2[0]); index++)
        EXPECT_FALSE(empty_set3.getInteger(set2[index]));
}

TEST(UnionOfSets, twoNonEmptySets) {

    uint8_t set1[] = {1, 6, 10, 50, 33};
    uint8_t set2[] = {12, 100, 75, 50, 99};

    IntegerSet empty_set1;
    IntegerSet empty_set2;

    for (size_t index{0}; index < sizeof(set1) / sizeof(set1[0]); index++)
        empty_set1.insertInteger(set1[index]);

    for (size_t index{0}; index < sizeof(set2) / sizeof(set2[0]); index++)
        empty_set2.insertInteger(set2[index]);

    IntegerSet empty_set3 = empty_set1.unionOfSets(empty_set2);

    for (size_t index{0}; index < sizeof(set1) / sizeof(set1[0]); index++)
        EXPECT_TRUE(empty_set3.getInteger(set1[index]));

    for (size_t index{0}; index < sizeof(set2) / sizeof(set2[0]); index++)
        EXPECT_TRUE(empty_set3.getInteger(set2[index]));
}

TEST(IntersectionOfSets, twoEmptySets) {

    IntegerSet empty_set1;
    IntegerSet empty_set2;

    IntegerSet empty_set3 = empty_set1.intersectionOfSets(empty_set2);

    for (size_t index{0}; index < MAX_VECTOR_SIZE; index++)
        EXPECT_FALSE(empty_set3.getInteger(index));
}

TEST(IntersectionOfSets, oneNonIntersectingEmptySet) {

    uint8_t set1[] = {1, 6, 10, 50, 33};
    uint8_t set2[] = {12, 100, 75, 51, 99};

    IntegerSet empty_set1;
    IntegerSet empty_set2;

    for (size_t index{0}; index < sizeof(set1) / sizeof(set1[0]); index++)
        empty_set1.insertInteger(set1[index]);

    IntegerSet empty_set3 = empty_set1.intersectionOfSets(empty_set2);

    for (size_t index{0}; index < sizeof(set1) / sizeof(set1[0]); index++)
        EXPECT_FALSE(empty_set3.getInteger(set1[index]));

    for (size_t index{0}; index < sizeof(set2) / sizeof(set2[0]); index++)
        EXPECT_FALSE(empty_set3.getInteger(set2[index]));
}

TEST(IntersectionOfSets, twoNonIntersectingNonEmptySets) {

    uint8_t set1[] = {1, 6, 10, 50, 33};
    uint8_t set2[] = {12, 100, 75, 51, 99};

    IntegerSet empty_set1;
    IntegerSet empty_set2;

    for (size_t index{0}; index < sizeof(set1) / sizeof(set1[0]); index++)
        empty_set1.insertInteger(set1[index]);

    for (size_t index{0}; index < sizeof(set2) / sizeof(set2[0]); index++)
        empty_set2.insertInteger(set2[index]);

    IntegerSet empty_set3 = empty_set1.intersectionOfSets(empty_set2);

    for (size_t index{0}; index < sizeof(set1) / sizeof(set1[0]); index++)
        EXPECT_FALSE(empty_set3.getInteger(set1[index]));

    for (size_t index{0}; index < sizeof(set2) / sizeof(set2[0]); index++)
        EXPECT_FALSE(empty_set3.getInteger(set2[index]));
}

TEST(IntersectionOfSets, twoIntersectingNonEmptySets) {

    uint8_t set1[] = {1, 6, 10, 50, 33};
    uint8_t set2[] = {1, 6, 10, 50, 33};

    IntegerSet empty_set1;
    IntegerSet empty_set2;

    for (size_t index{0}; index < sizeof(set1) / sizeof(set1[0]); index++)
        empty_set1.insertInteger(set1[index]);

    for (size_t index{0}; index < sizeof(set2) / sizeof(set2[0]); index++)
        empty_set2.insertInteger(set2[index]);

    IntegerSet empty_set3 = empty_set1.intersectionOfSets(empty_set2);

    for (size_t index{0}; index < sizeof(set1) / sizeof(set1[0]); index++)
        EXPECT_TRUE(empty_set3.getInteger(set1[index]));

    for (size_t index{0}; index < sizeof(set2) / sizeof(set2[0]); index++)
        EXPECT_TRUE(empty_set3.getInteger(set2[index]));
}

TEST(ToStringOutput, emptySet) {

    IntegerSet empty_set1;

    EXPECT_STRCASEEQ(empty_set1.toString().c_str(),"---");
}

TEST(ToStringOutput, nonEmptySet) {

    IntegerSet set;

    set.insertInteger(0);
    set.insertInteger(100);
    set.insertInteger(50);

    EXPECT_STRCASEEQ(set.toString().c_str(), "0, 50, 100");
}

TEST(IsEqualTo, nonEmptySetsEqual) {

    IntegerSet set1;
    IntegerSet set2;

    uint8_t num_array1[] = {1, 6, 10, 50, 33};
    uint8_t num_array2[] = {1, 6, 10, 50, 33};

    for (size_t index{0}; index < sizeof(num_array1) / sizeof(num_array1[0]); index++)
        set1.insertInteger(num_array1[index]);

    for (size_t index{0}; index < sizeof(num_array2) / sizeof(num_array2[0]); index++)
        set2.insertInteger(num_array2[index]);

    EXPECT_TRUE(set1.isEqualTo(set2));
}

TEST(IsEqualTo, emptySetsEqual) {

    IntegerSet empty_set1;
    IntegerSet empty_set2;

    EXPECT_TRUE(empty_set1.isEqualTo(empty_set2));
}

TEST(IsEqualTo, nonEmptySetsNotEqual) {

    IntegerSet set1;
    IntegerSet set2;

    uint8_t num_array1[] = {1, 6, 10, 50, 100};
    uint8_t num_array2[] = {1, 6, 10, 50};

    for (size_t index{0}; index < sizeof(num_array1) / sizeof(num_array1[0]); index++)
        set1.insertInteger(num_array1[index]);

    for (size_t index{0}; index < sizeof(num_array2) / sizeof(num_array2[0]); index++)
        set2.insertInteger(num_array2[index]);

    EXPECT_FALSE(set1.isEqualTo(set2));
}