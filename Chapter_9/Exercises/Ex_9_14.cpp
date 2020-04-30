#include <Ex_9_14.h>
#include <sstream>

HugeInteger::HugeInteger(const std::string digits) {
    input(digits);
}

void HugeInteger::input(const std::string digits) {

    if (digits.size() == 0 || digits.size() > maxDigits)
        throw std::invalid_argument("ERROR: invalid number of digits");

    for (char const&c : digits) {
        if (!std::isdigit(c))
            throw std::invalid_argument("ERROR: not a valid string of digits");
    }

    numDigits = digits.size();
    _storeDigits(digits);
}

void HugeInteger::_storeDigits(const std::string &digitStr) {

    size_t index{0};

    while (index < maxDigits - digitStr.size())
        digits[index++] = 0;

    for (size_t digit_index{0}; digit_index < digitStr.size(); digit_index++, index++)
        digits[index] = digitStr[digit_index] - '0';
}

bool HugeInteger::isNotEqualTo(const HugeInteger &other) const {

    if (numDigits != other.numDigits)
        return true;

    size_t index{maxDigits - numDigits};

    while (index < maxDigits && digits[index] == other.digits[index])
        index++;

    return (index == maxDigits);
}

bool HugeInteger::isGreaterThan(const HugeInteger &other) const {

    if (numDigits < other.numDigits)
        return false;
    else if (numDigits > other.numDigits)
        return true;
    else {
        size_t index{maxDigits - numDigits};

        while (index < maxDigits - 1 && digits[index] == other.digits[index])
            index++;

        return digits[index] > other.digits[index];
    }
}

bool HugeInteger::isLessThan(const HugeInteger &other) const {

    if (numDigits > other.numDigits)
        return false;
    else if (numDigits < other.numDigits)
        return true;
    else {
        size_t index{maxDigits - numDigits};

        while (index < maxDigits - 1 && digits[index] == other.digits[index])
            index++;

        return digits[index] < other.digits[index];
    }
}

bool HugeInteger::isGreaterThanOrEqualTo(const HugeInteger &other) const {

    if (numDigits < other.numDigits)
        return false;
    else if (numDigits > other.numDigits)
        return true;
    else {
        size_t index{maxDigits - numDigits};

        while (index < maxDigits - 1 && digits[index] == other.digits[index])
            index++;

        return digits[index] >= other.digits[index];
    }
}

bool HugeInteger::isLessThanOrEqualTo(const HugeInteger &other) const {
    if (numDigits > other.numDigits)
        return false;
    else if (numDigits < other.numDigits)
        return true;
    else {
        size_t index{maxDigits - numDigits};

        while (index < maxDigits - 1 && digits[index] == other.digits[index])
            index++;

        return digits[index] <= other.digits[index];
    }
}

bool HugeInteger::isZero(void) const {
    for (int8_t index{maxDigits-1}; index >= 0; index--)
        if (digits[index] != 0)
            return false;
    return true;
}

std::string HugeInteger::output(void) const {

    std::ostringstream output;
    size_t index{0};

    while (digits[index] == 0 && index < maxDigits)
       ++index;

    while (index < maxDigits)
        output << (int)digits[index++];

    return output.str();
}

void HugeInteger::multiply(const HugeInteger &other) {

    int8_t product_digits[maxDigits] = {0};
    int8_t index_tmp;
    size_t lastNonZero{maxDigits};

    for (int8_t index_other{maxDigits-1}; index_other >= (int8_t)(maxDigits - other.numDigits); index_other--) {

        index_tmp = index_other;

        for (int8_t index{maxDigits-1}; index >= (int8_t)(maxDigits - numDigits); index--) {

            product_digits[index_tmp] += other.digits[index_other] * digits[index];

            if (product_digits[index_tmp] >= 10) {
                if (index_tmp > 0)
                    product_digits[index_tmp-1] += product_digits[index_tmp] / 10;
                else /* rollover to end of array */
                    product_digits[maxDigits-1] += product_digits[index_tmp] / 10;
                product_digits[index_tmp] %= 10;
            }
            index_tmp--;
        }
    }

    /* copy temp product array to member digits array */
    for (int8_t idx{maxDigits-1}; idx >= 0; idx--) {
        digits[idx] = product_digits[idx];

        if (digits[idx])
            lastNonZero = idx;
    }

    numDigits = maxDigits - lastNonZero;
}

// void HugeInteger::divide(const HugeInteger &other) {

    // int8_t quotient_digits[maxDigits] = {0};
    // int8_t index_tmp;

    // for (int8_t index_other{maxDigits-1}; index_other >= (int8_t)(maxDigits - other.numDigits); index_other--) {
    // }
// }