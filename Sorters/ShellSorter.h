#ifndef INC_3_SEM_LAB_1_SHELLSORTER_H
#define INC_3_SEM_LAB_1_SHELLSORTER_H

#include "ISorter.h"

template<typename T>
class ShellSorter : public ISorter<T> {
public:
    Sequence<T>* sort(Sequence<T>* seq, bool (* cmp)(const T&, const T&)) override;
};

template<typename T>
Sequence<T>* ShellSorter<T>::sort(Sequence<T>* seq, bool (* cmp)(const T&, const T&)) {
    int n = seq->length();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i += 1) {
            T temp = seq->getElement(i);
            int j;
            for (j = i; j >= gap && !cmp(seq->getElement(j - gap), temp); j -= gap)
                seq->setElement(j, seq->getElement(j - gap));
            seq->setElement(j, temp);
        }
    }
    return seq;
}

#endif //INC_3_SEM_LAB_1_SHELLSORTER_H
