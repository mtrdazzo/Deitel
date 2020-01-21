#include <Ex_9_21.h>
#include <gtest/gtest.h>

TEST(DefaultConstructor, AllElementsFalse) {

    IntegerSet empty_set;

    for (size_t index{0}; index < MAX_VECTOR_SIZE; index++)
        EXPECT_FALSE(empty_set.getInteger(index));
}

TEST(SetInteger, setElementsTrue) {

    IntegerSet empty_set;

    empty_set.setInteger(0, true);
    empty_set.setInteger(100, true);
    empty_set.setInteger(50, true);

    EXPECT_TRUE(empty_set.getInteger(0));
    EXPECT_TRUE(empty_set.getInteger(100));
    EXPECT_TRUE(empty_set.getInteger(50));
}

TEST(SetInteger, setInvalidElementTrue) {

    IntegerSet empty_set;

    try {
        empty_set.setInteger(MAX_VECTOR_SIZE, true);
    } catch (std::invalid_argument const &err) {
        EXPECT_STRCASEEQ(err.what(), "invalid index, must be between 0 and 100 inclusive");
    } 
}

TEST(SetInteger, setElementsFalse) {

    IntegerSet empty_set;

    empty_set.setInteger(0, true);
    empty_set.setInteger(100, true);
    empty_set.setInteger(50, true);

    EXPECT_TRUE(empty_set.getInteger(0));
    EXPECT_TRUE(empty_set.getInteger(100));
    EXPECT_TRUE(empty_set.getInteger(50));

    empty_set.setInteger(0, false);
    empty_set.setInteger(100, false);
    empty_set.setInteger(50, false);
    
    EXPECT_FALSE(empty_set.getInteger(0));
    EXPECT_FALSE(empty_set.getInteger(100));
    EXPECT_FALSE(empty_set.getInteger(50));
}

TEST(UnionOfSets, twoEmptySets) {

    IntegerSet empty_set1;
    IntegerSet empty_set2;

    IntegerSet empty_set3 = empty_set1.unionOfSets(empty_set2);

    for (size_t index{0}; index < MAX_VECTOR_SIZE; index++)
        EXPECT_FALSE(empty_set3.getInteger(index));
}

TEST(UnionOfSets, oneEmptySet) {

    std::array<size_t, 5> set1 = {1, 6, 10, 50, 33};
    std::array<size_t, 5> set2 = {12, 100, 75, 51, 99};

    IntegerSet empty_set1;
    IntegerSet empty_set2;

    for (size_t index{0}; index < set1.size(); index++)
        empty_set1.setInteger(set1[index], true);

    IntegerSet empty_set3 = empty_set1.unionOfSets(empty_set2);

    for (size_t index{0}; index < set1.size(); index++)
        EXPECT_TRUE(empty_set3.getInteger(set1[index]));

    for (size_t index{0}; index < set2.size(); index++)
        EXPECT_FALSE(empty_set3.getInteger(set2[index]));
}

TEST(UnionOfSets, twoNonEmptySets) {

    std::array<size_t, 5> set1 = {1, 6, 10, 50, 33};
    std::array<size_t, 5> set2 = {12, 100, 75, 50, 99};

    IntegerSet empty_set1;
    IntegerSet empty_set2;

    for (size_t index{0}; index < set1.size(); index++)
        empty_set1.setInteger(set1[index], true);

    for (size_t index{0}; index < set2.size(); index++)
        empty_set2.setInteger(set2[index], true);

    IntegerSet empty_set3 = empty_set1.unionOfSets(empty_set2);

    for (size_t index{0}; index < set1.size(); index++)
        EXPECT_TRUE(empty_set3.getInteger(set1[index]));

    for (size_t index{0}; index < set2.size(); index++)
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

    std::array<size_t, 5> set1 = {1, 6, 10, 50, 33};
    std::array<size_t, 5> set2 = {12, 100, 75, 51, 99};

    IntegerSet empty_set1;
    IntegerSet empty_set2;

    for (size_t index{0}; index < set1.size(); index++)
        empty_set1.setInteger(set1[index], true);

    IntegerSet empty_set3 = empty_set1.intersectionOfSets(empty_set2);

    for (size_t index{0}; index < set1.size(); index++)
        EXPECT_FALSE(empty_set3.getInteger(set1[index]));

    for (size_t index{0}; index < set2.size(); index++)
        EXPECT_FALSE(empty_set3.getInteger(set2[index]));
}

TEST(IntersectionOfSets, twoNonIntersectingNonEmptySets) {

    std::array<size_t, 5> set1 = {1, 6, 10, 50, 33};
    std::array<size_t, 5> set2 = {12, 100, 75, 51, 99};

    IntegerSet empty_set1;
    IntegerSet empty_set2;

    for (size_t index{0}; index < set1.size(); index++)
        empty_set1.setInteger(set1[index], true);

    for (size_t index{0}; index < set2.size(); index++)
        empty_set2.setInteger(set2[index], true);

    IntegerSet empty_set3 = empty_set1.intersectionOfSets(empty_set2);

    for (size_t index{0}; index < set1.size(); index++)
        EXPECT_FALSE(empty_set3.getInteger(set1[index]));

    for (size_t index{0}; index < set2.size(); index++)
        EXPECT_FALSE(empty_set3.getInteger(set2[index]));
}

TEST(IntersectionOfSets, twoIntersectingNonEmptySets) {

    std::array<size_t, 5> set1 = {1, 6, 10, 50, 33};
    std::array<size_t, 5> set2 = {1, 6, 10, 50, 33};

    IntegerSet empty_set1;
    IntegerSet empty_set2;

    for (size_t index{0}; index < set1.size(); index++)
        empty_set1.setInteger(set1[index], true);

    for (size_t index{0}; index < set2.size(); index++)
        empty_set2.setInteger(set2[index], true);

    IntegerSet empty_set3 = empty_set1.intersectionOfSets(empty_set2);

    for (size_t index{0}; index < set1.size(); index++)
        EXPECT_TRUE(empty_set3.getInteger(set1[index]));

    for (size_t index{0}; index < set2.size(); index++)
        EXPECT_TRUE(empty_set3.getInteger(set2[index]));
}