#ifndef INC_2_LISTSEQUENCE_H
#define INC_2_LISTSEQUENCE_H

#include "LinkList.h"
#include "Sequence.h"

template<typename T>
class ListSeq : public Sequence<T> {
private:
    LinkList<T> data;
    int size{};
public:
    ListSeq();

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
ListSeq<T>::ListSeq() {
    this->size = 0;
}

template<typename T>
int ListSeq<T>::length() {
    return this->size;
}

template<typename T>
void ListSeq<T>::append(T value) {
    this->data.append(value);
    this->size++;
}

template<typename T>
void ListSeq<T>::prepend(T value) {
    this->data.prepend(value);
    this->size++;
}

template<typename T>
void ListSeq<T>::pop(int index) {
    this->data.pop(index);
    this->size--;
}

template<typename T>
T &ListSeq<T>::getElement(int index) {
    return this->data[index];
}

template<typename T>
void *ListSeq<T>::getFirst() {
    return this->data.getFirst();
}

template<typename T>
void *ListSeq<T>::getLast() {
    return this->data.getLast();
}

template<typename T>
void ListSeq<T>::insert(int index, T value) {
    this->data.insert(value, index);
    this->size++;
}

template<typename T>
void ListSeq<T>::setElement(int index, T value) {
    this->data[index] = value;
}

template<typename T>
void ListSeq<T>::swap(int index1, int index2) {
    this->data.swap(index1, index2);
}

template<typename T>
const std::type_info& ListSeq<T>::getType() {
    return typeid(this->data);
}

#endif
