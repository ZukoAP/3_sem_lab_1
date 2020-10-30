#ifndef INC_3_SEM_LAB_1_QUICKSORTER_H
#define INC_3_SEM_LAB_1_QUICKSORTER_H

#include "ISorter.h"

template<typename T>
class QuickSorter : public ISorter<T> {
public:
    Sequence<T>* sort(Sequence<T>* seq, bool (* cmp)(const T&, const T&)) override;

private:
    int partition(Sequence<T>* seq, int left, int right, bool (* cmp)(const T&, const T&));

    void quickSort(Sequence<T>* seq, int left, int right, bool (* cmp)(const T&, const T&));
};

template<typename T>
Sequence<T>* QuickSorter<T>::sort(Sequence<T>* seq, bool (* cmp)(const T&, const T&)) {
    quickSort(seq, 0, seq->length() - 1, cmp);
    return seq;
}

template<typename T>
int QuickSorter<T>::partition(Sequence<T>* seq, int left, int right, bool (* cmp)(const T&, const T&)) {
    int pivot = seq->getElement(right);
    int i = left - 1;

    for (int j = left; j <= right - 1; j++) {
        if (cmp(seq->getElement(j), pivot)) {
            i++;
            seq->swap(i, j);
        }
    }
    seq->swap(i + 1, right);
    return i + 1;
}

template<typename T>
void QuickSorter<T>::quickSort(Sequence<T>* seq, int left, int right, bool (* cmp)(const T&, const T&)) {

    if (left < right) {
        int pi = partition(seq, left, right, cmp);
        quickSort(seq, left, pi - 1, cmp);
        quickSort(seq, pi + 1, right, cmp);
    }
}

#endif //INC_3_SEM_LAB_1_QUICKSORTER_H
