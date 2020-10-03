#ifndef INC_2_SINGLELINKLIST_H
#define INC_2_SINGLELINKLIST_H

#include <ostream>
#include "Node.h"

template<typename T>
class SLinkList {
private:
    Node<T> *head;
    Node<T> *tail;
    int size;
public:
    SLinkList();

    SLinkList(const SLinkList<T> &list);

    SLinkList(T *arr, int amount);

    ~SLinkList();

    void append(T value);

    void prepend(T value);

    int getSize() { return this->size; }

    Node<T> *getFirst();

    Node<T> *getLast();

    void insert(T value, int index);

    void reverse();

    T &operator[](int index);

    template<typename T1>
    friend std::ostream &operator<<(std::ostream &out, const SLinkList<T1> &dynArr);
};

template<typename T>
SLinkList<T>::SLinkList() {
    this->head = nullptr;
    this->tail = nullptr;
    this->size = 0;
}

template<typename T>
void SLinkList<T>::append(T value) {
    if (this->size == 0) {
        Node<T> *buffEl = new Node<T>;
        buffEl->val = value;
        buffEl->next = nullptr;
        this->head = buffEl;
        this->tail = buffEl;
    } else {
        auto buffEl = new Node<T>;
        buffEl->val = value;
        buffEl->next = nullptr;
        this->tail->next = buffEl;
        this->tail = buffEl;
    }
    this->size++;
}

template<typename T>
SLinkList<T>::SLinkList(const SLinkList<T> &list) {
    this->head = nullptr;
    this->tail = nullptr;
    this->size = 0;
    Node<T> *buffEl = list.head;
    while (buffEl != nullptr) {
        append(*buffEl);
        buffEl = buffEl->next;
    }
}

template<typename T>
T &SLinkList<T>::operator[](int index) {
    if ((index < 0) || (index >= this->size))
        throw std::out_of_range("Index is out of range. Check line: " + std::to_string(__LINE__) + " in " + __FILE__);
    else {
        Node<T> *buffEl = this->head;
        int i = 0;
        while (buffEl != nullptr && i < index) {
            buffEl = buffEl->next;
            ++i;
        }
        return *buffEl;
    }
}

template<typename T1>
std::ostream &operator<<(std::ostream &out, const SLinkList<T1> &list) {
    if (list.size == 0)
        out << NULL;
    else {
        Node<T1> *buffEl = list.head;
        int i = 0;
        while (buffEl != nullptr) {
            if (i != list.size - 1) {
                out << buffEl->val << " ";
            } else {
                out << buffEl->val;
            }
            buffEl = buffEl->next;
            ++i;
        }
    }
    return out;
}

template<typename T>
void SLinkList<T>::prepend(T value) {
    if (this->size == 0) {
        Node<T> *buffEl = new Node<T>;
        buffEl->val = value;
        buffEl->next = nullptr;
        this->head = buffEl;
        this->tail = buffEl;
    } else {
        Node<T> *buffEl = new Node<T>;
        buffEl->val = value;
        buffEl->next = this->head;
        this->head = buffEl;
    }
    this->size++;

}

template<typename T>
SLinkList<T>::SLinkList(T *arr, int amount) {
    this->head = nullptr;
    this->tail = nullptr;
    this->size = 0;
    for (int i = 0; i < amount; ++i) {
        append(arr[i]);
    }
}


template<typename T>
void SLinkList<T>::insert(T value, int index) {
    if ((index < 0) || (index > this->size))
        throw std::out_of_range("Index is out of range. Check line: " + std::to_string(__LINE__) + " in " + __FILE__);
    else {
        if (index == 0) {
            prepend(value);
        } else if (index == this->size) {
            append(value);
        } else {
            Node<T> *BuffElPrev = this->head;
            for (int i = 0; i < index - 1; ++i) {
                BuffElPrev = BuffElPrev->next;
            }
            Node<T> *BuffElNext = BuffElPrev->next;
            Node<T> *buffEl = new Node<T>;
            buffEl->val = value;
            buffEl->next = BuffElNext;
            BuffElPrev->next = buffEl;
            this->size++;
        }
    }
}

template<typename T>
Node<T> *SLinkList<T>::getFirst() {
    return this->head;
}

template<typename T>
Node<T> *SLinkList<T>::getLast() {
    return this->tail;
}

template<typename T>
void SLinkList<T>::reverse() {
    this->tail = this->head;
    Node<T> *prev = nullptr;
    Node<T> *curr = this->head;
    Node<T> *next = this->head->next;
    while (next != nullptr) {
        curr->next = prev;
        prev = curr;
        curr = next;
        next = curr->next;
    }
    curr->next = prev;
    this->head = curr;
}

template<typename T>
SLinkList<T>::~SLinkList() = default;


#endif