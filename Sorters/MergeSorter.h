#ifndef INC_3_SEM_LAB_1_MERGESORTER_H
#define INC_3_SEM_LAB_1_MERGESORTER_H

#include "ISorter.h"

template<typename T>
class MergeSorter : public ISorter<T> {
public:
    Sequence<T>* sort(Sequence<T>* seq, bool (* cmp)(const T&, const T&)) override;

private:
    void mergeSort(Sequence<T>* seq, T* buff, int left, int right, bool (* cmp)(const T&, const T&));

    void merge(Sequence<T>* seq, T* buff, int left, int mid, int right, bool (* cmp)(const T&, const T&));
};

template<typename T>
Sequence<T>* MergeSorter<T>::sort(Sequence<T>* seq, bool (* cmp)(const T&, const T&)) {
    T buff[seq->length()];
    this->mergeSort(seq, buff, 0, (seq->length()), cmp);
    return seq;
}

template<typename T>
void MergeSorter<T>::merge(Sequence<T>* seq, T* buff, int left, int mid, int right, bool (* cmp)(const T&, const T&)) {
    int ileft = 0, iright = 0;

    while (ileft + left < mid && iright + mid < right) {
        if (cmp(seq->getElement(ileft + left), seq->getElement(iright + mid))) {
            buff[ileft + iright] = seq->getElement(left + ileft);
            ileft++;
        } else {
            buff[ileft + iright] = seq->getElement(iright + mid);
            iright++;
        }
    }

    while (ileft + left < mid) {
        buff[ileft + iright] = seq->getElement(left + ileft);
        ileft++;
    }
    while (iright + mid < right) {
        buff[ileft + iright] = seq->getElement(iright + mid);
        iright++;
    }

    for (int i = 0; i < ileft + iright; i++) {
        seq->setElement(left + i, buff[i]);
    }
}

template<typename T>
void MergeSorter<T>::mergeSort(Sequence<T>* seq, T* buff, int left, int right, bool (* cmp)(const T&, const T&)) {

    if (right - left <= 1) {
        return;
    }

    int mid = left + (right - left) / 2;

    this->mergeSort(seq, buff, left, mid, cmp);
    this->mergeSort(seq, buff, mid, right, cmp);

    this->merge(seq, buff, left, mid, right, cmp);
}


#endif //INC_3_SEM_LAB_1_MERGESORTER_H
