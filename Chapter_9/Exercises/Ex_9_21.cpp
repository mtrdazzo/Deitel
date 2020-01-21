#include <Ex_9_21.h>

IntegerSet::IntegerSet(void) {

    /* Initialize empty integer set */
    for (size_t index{0}; index < MAX_VECTOR_SIZE; index++)
        setOfInts.push_back(false);
}

IntegerSet::IntegerSet(std::array<bool, MAX_VECTOR_SIZE> arrayOfInts) {

    /* Initialize empty integer set */
    for (size_t index{0}; index < MAX_VECTOR_SIZE; index++)
        setOfInts.push_back(arrayOfInts[index]);
}

void IntegerSet::setInteger(const size_t index, const bool status) {
    if (index >= MAX_VECTOR_SIZE)
        throw std::invalid_argument("invalid index, must be between 0 and 100 inclusive");
    setOfInts[index] = status;
}

bool IntegerSet::getInteger(const size_t index) {
    if (index >= MAX_VECTOR_SIZE)
        throw std::invalid_argument("invalid index, must be between 0 and 100 inclusive");
    
    return setOfInts[index];
}

IntegerSet IntegerSet::unionOfSets(const IntegerSet & other) const {

    std::array<bool, MAX_VECTOR_SIZE> unionArray;

    for (size_t index{0}; index < MAX_VECTOR_SIZE; index++)
        unionArray[index] = (this->setOfInts[index] || other.setOfInts[index]) ? true : false;

    IntegerSet unionIntegerSet(unionArray);

    return unionIntegerSet;
}

IntegerSet IntegerSet::intersectionOfSets(const IntegerSet & other) const {

    std::array<bool, MAX_VECTOR_SIZE> unionArray;

    for (size_t index{0}; index < MAX_VECTOR_SIZE; index++)
        unionArray[index] = (this->setOfInts[index] && other.setOfInts[index]) ? true : false;

    IntegerSet unionIntegerSet(unionArray);

    return unionIntegerSet;
}