#ifndef INC_2_DYNARRAY_H
#define INC_2_DYNARRAY_H

#include "DynArrayElem.h"
#include <string.h>

template<typename T>
class DynArray {
private:
    DynArrayElem<T> *data;
    int size{};
public:
    DynArray();

    DynArray(int amount);

    DynArray(const DynArray<T> &arr);

    DynArray(T *arr, int amount);

    ~DynArray();

    void append(T value);

    void prepend(T value);

    int getSize() { return this->size; }

    void pop(int index);

//    void setVal(T value, int index);

    void resize(int newSize);

    void swap(int index1, int index2);

    T &operator[](int index);

    template<typename T1>
    friend std::ostream &operator<<(std::ostream &out, const DynArray<T1> &dynArr);
};

template<typename T>
DynArray<T>::DynArray() {
    this->data = (DynArrayElem<T> *) malloc(0);
    this->size = 0;
}

template<typename T>
void DynArray<T>::append(T value) {
    this->resize(this->size + 1);
    this->data[this->size - 1].setVal(value);
}

template<typename T>
DynArray<T>::DynArray(const DynArray<T> &arr) {
    this->data = (DynArrayElem<T> *) std::malloc(sizeof(DynArrayElem<T>) * arr.size);
    this->size = arr.size;
    for (int i = 0; i < arr.size; ++i) {
        this->data[i].setVal(arr.data[i]);
    }
}

template<typename T>
T &DynArray<T>::operator[](int index) {
    if ((index < 0) || (index >= this->size))
        throw std::out_of_range("Index is out of range. Check line: " + std::to_string(__LINE__) + " in " + __FILE__);
    else {
        this->data[index].setCheck();
        return this->data[index];
    }
}

template<typename T1>
std::ostream &operator<<(std::ostream &out, const DynArray<T1> &dynArr) {
    if (dynArr.size == 0) {
        out << NULL;
    } else {
        for (int i = 0; i < dynArr.size; ++i) {
            if (i != dynArr.size - 1) {
                out << dynArr.data[i] << " ";
            } else { out << dynArr.data[i]; }
        }
    }
    return out;
}

template<typename T>
void DynArray<T>::prepend(T value) {
    this->resize(this->size + 1);
    (DynArrayElem<T> *) memmove(this->data + 1, this->data, sizeof(DynArrayElem<T>) * (this->size - 1));
    this->data[0].setVal(value);
}

template<typename T>
DynArray<T>::DynArray(T *arr, int amount) {
    this->data = (DynArrayElem<T> *) std::malloc(sizeof(DynArrayElem<T>) * amount);
    for (int i = 0; i < amount; ++i) {
        this->data[i].setVal(arr[i]);
    }
    this->size = amount;
}

template<typename T>
DynArray<T>::DynArray(int amount) {
    this->data = (DynArrayElem<T> *) std::malloc(sizeof(DynArrayElem<T>) * amount);
    this->size = amount;
}

/*template<typename T>
void DynArray<T>::setVal(T value, int index) {
    if ((index < 0) || (index >= this->size))
        throw std::out_of_range("Index is out of range. Check line: " + std::to_string(__LINE__) + " in " + __FILE__);
    else {
        this->data[index].setVal(value);
    }
}*/

template<typename T>
void DynArray<T>::resize(int newSize) {
    this->data = (DynArrayElem<T> *) std::realloc(this->data, sizeof(DynArrayElem<T>) * newSize);
    this->size = newSize;
}

template<typename T>
void DynArray<T>::pop(int index) {
    if ((index < 0) || (index >= this->size))
        throw std::out_of_range("Index is out of range. Check line: " + std::to_string(__LINE__) + " in " + __FILE__);
    else {
        for (int i = index; i < this->size - 1; ++i) {
            this->data[i] = this->data[i + 1];
        }
        this->resize(this->size - 1);
    }
}

template<typename T>
void DynArray<T>::swap(int index1, int index2) {
    if (index1 < 0 || index1 >= this->size || index2 < 0 || index2 >= this->size)
        throw std::out_of_range("Index is out of range. Check line: " + std::to_string(__LINE__) + " in " + __FILE__);
    else {
        //std::swap<T>((*this)[index1], (*this)[index2]);
        T buffEl = (*this)[index1];
        (*this)[index1] = (*this)[index2];
        (*this)[index2] = buffEl;
    }
}

template<typename T>
DynArray<T>::~DynArray() = default;

#endif
