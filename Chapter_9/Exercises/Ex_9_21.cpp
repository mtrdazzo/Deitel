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

void IntegerSet::insertInteger(const size_t index) {
    if (index >= MAX_VECTOR_SIZE)
        throw std::invalid_argument("invalid index, must be between 0 and 100 inclusive");
    setOfInts[index] = true;
}

void IntegerSet::deleteInteger(const size_t index) {
    if (index >= MAX_VECTOR_SIZE)
        throw std::invalid_argument("invalid index, must be between 0 and 100 inclusive");
    setOfInts[index] = false;
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

std::string IntegerSet::toString(void) const {

    std::ostringstream output;
    bool has_elements{false};

    for (size_t index{0}; index < MAX_VECTOR_SIZE; index++)
        if (setOfInts[index]) {
            if (has_elements) {
                output << ", " << index;
            }
            else
            {
                has_elements = true;
                output << index;
            }
        }

    if (has_elements)
        return output.str();
    else
        return std::string("---");
}

bool IntegerSet::isEqualTo(const IntegerSet &other) const {

    for (size_t index{0}; index < MAX_VECTOR_SIZE; index++)
        if (setOfInts[index] != other.setOfInts[index])
            return false;
    return true;
}