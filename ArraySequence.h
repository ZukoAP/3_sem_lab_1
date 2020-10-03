#ifndef INC_2_ARRAYSEQUENCE_H
#define INC_2_ARRAYSEQUENCE_H

#include "dynamicArray.hpp"
#include "Sequence.h"

template<typename T>
class ArraySeq : public Sequence<T> {
private:
    dynamicArray<T> data;
    int size{};
public:
    ArraySeq();

    int length() override;

     const std::type_info& getType() override;

    void append(T) override;

    void prepend(T) override;

    void pop(int) override;

    T &getElement(int) override;

    void *getFirst() override;

    void *getLast() override;

    void insert(int, T) override;

    void setElement(int, T) override;

    void swap(int, int) override;
};

template<typename T>
ArraySeq<T>::ArraySeq() {
    this->size = 0;
}

template<typename T>
int ArraySeq<T>::length() {
    return this->size;
}

template<typename T>
void ArraySeq<T>::append(T value) {
    this->data.append(value);
    this->size++;
}

template<typename T>
void ArraySeq<T>::prepend(T value) {
    this->data.prepend(value);
    this->size++;
}

template<typename T>
void ArraySeq<T>::pop(int index) {
    this->data.pop(index);
    this->size--;
}

template<typename T>
T &ArraySeq<T>::getElement(int index) {
    return this->data[index];
}

template<typename T>
void *ArraySeq<T>::getFirst() {
    return &this->data[0];
}

template<typename T>
void *ArraySeq<T>::getLast() {
    return &this->data[this->size - 1];
}

template<typename T>
void ArraySeq<T>::insert(int index, T value) {
    this->data.resize(this->size + 1);
    for (int i = this->size; i >= index; i--) {
        this->data[i + 1] = this->data[i];
    }
    this->data[index] = value;
}

template<typename T>
void ArraySeq<T>::setElement(int index, T value) {
    this->data[index] = value;
}

template<typename T>
void ArraySeq<T>::swap(int index1, int index2) {
    this->data.swap(index1, index2);
}

template<typename T>
const std::type_info& ArraySeq<T>::getType() {
    return typeid(this->data);
}

#endif