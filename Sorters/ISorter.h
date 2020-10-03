#ifndef INC_3_SEM_LAB_1_ISORTER_H
#define INC_3_SEM_LAB_1_ISORTER_H
#include <iostream>
#include "../Sequence.h"
#include "Comparator.h"

template<typename T>
class ISorter{
public:
    virtual Sequence<T>* sort(Sequence<T> *seq, bool (*cmp)(const T&, const T&)) = 0;
public:
    ISorter() = default;
    ~ISorter() = default;
};


#endif //INC_3_SEM_LAB_1_ISORTER_H
