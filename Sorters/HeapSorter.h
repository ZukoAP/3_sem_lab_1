#ifndef INC_3_SEM_LAB_1_HEAPSORTER_H
#define INC_3_SEM_LAB_1_HEAPSORTER_H

#include "ISorter.h"

template<typename T>
class HeapSorter : public ISorter<T> {
public:
    Sequence<T>* sort(Sequence<T>* seq, bool (* cmp)(const T&, const T&)) override;

private:
    void heapify(Sequence<T>* seq, int n, int i, bool (* cmp)(const T&, const T&));

    void heapSort(Sequence<T>* seq, int n, bool (* cmp)(const T&, const T&));
};

template<typename T>
Sequence<T>* HeapSorter<T>::sort(Sequence<T>* seq, bool (* cmp)(const T&, const T&)) {
    this->heapSort(seq,seq->length(),cmp);
    return seq;
}

template<typename T>
void HeapSorter<T>::heapify(Sequence<T>* seq, int n, int i, bool (* cmp)(const T&, const T&)) {
    int largest = i; // Initialize largest as root
    int left = 2*i + 1; // left = 2*i + 1
    int right = 2*i + 2; // right = 2*i + 2
    if (left < n && !cmp(seq->getElement(left), seq->getElement(largest)))
        largest = left;
    if (right < n && !cmp(seq->getElement(right), seq->getElement(largest)))
        largest = right;
    if (largest != i){
        seq->swap(i,largest);
        this->heapify(seq, n, largest,cmp);
    }
}

template<typename T>
void HeapSorter<T>::heapSort(Sequence<T>* seq, int n, bool (* cmp)(const T&, const T&)) {
    for (int i = n / 2 - 1; i >= 0; i--)
        this->heapify(seq, n, i,cmp);

    for (int i=n-1; i>0; i--){
        seq->swap(0,i);
        this->heapify(seq, i, 0,cmp);
    }
}

#endif //INC_3_SEM_LAB_1_HEAPSORTER_H
