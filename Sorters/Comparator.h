#ifndef INC_3_SEM_LAB_1_COMPARATOR_H
#define INC_3_SEM_LAB_1_COMPARATOR_H

template<typename T>
static bool lessThan(const T& a, const T& b) {
    return a < b;
}

template<typename T>
static bool lessOrEquaThan(const T& a, const T& b) {
    return a <= b;
}

template<typename T>
static bool greaterThan(const T& a, const T& b) {
    return a > b;
}

template<typename T>
static bool greaterOrEqualThan(const T& a, const T& b) {
    return a >= b;
}

#endif //INC_3_SEM_LAB_1_COMPARATOR_H
