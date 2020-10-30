#ifndef INC_2_LINKLIST_H
#define INC_2_LINKLIST_H

#include "ListElem.h"

template<typename T>
class LinkList {
private:
    ListElem<T>* head;
    ListElem<T>* tail;
    int size{};
public:
    LinkList();

    LinkList(const LinkList<T>& list);

    LinkList(T* arr, int amount);

    ~LinkList();

    void append(T value);

    void prepend(T value);

    int getSize() { return this->size; }

    ListElem<T>* getFirst();

    ListElem<T>* getLast();

    LinkList<T>* sublist(int start, int end);

    LinkList<T>* concat(LinkList<T>* list);

    void insert(T value, int index);

    void pop(int index);

    void swap(int index1, int index2);

    T& operator[](int index);

    T& operator[](int index) const;

    template<typename T1>
    friend std::ostream& operator<<(std::ostream& out, const LinkList<T1>& dynArr);
};

template<typename T>
LinkList<T>::LinkList() {
    this->head = nullptr;
    this->tail = nullptr;
    this->size = 0;
}

template<typename T>
void LinkList<T>::append(T value) {
    if (this->size == 0) {
        ListElem<T>* buffEl = new ListElem<T>;
        buffEl->setVal(value);
        buffEl->setNextPtr(nullptr);
        buffEl->setPrevPtr(nullptr);
        this->head = buffEl;
        this->tail = buffEl;
    } else {
        ListElem<T>* buffEl = new ListElem<T>;
        buffEl->setVal(value);
        buffEl->setNextPtr(nullptr);
        buffEl->setPrevPtr(this->tail);
        this->tail->setNextPtr(buffEl);
        this->tail = buffEl;
    }
    this->size++;
}

template<typename T>
LinkList<T>::LinkList(const LinkList<T>& list) {
    this->head = nullptr;
    this->tail = nullptr;
    this->size = 0;
    ListElem<T>* buffEl = list.head;
    while (buffEl != nullptr) {
        append(*buffEl);
        buffEl = buffEl->getNextPtr();
    }
}

template<typename T>
T& LinkList<T>::operator[](int index) {
    if ((index < 0) || (index >= this->size))
        throw std::out_of_range("Index is out of range. Check line: " + std::to_string(__LINE__) + " in " + __FILE__);
    else {
        ListElem<T>* buffEl = this->head;
        int i = 0;
        while (buffEl != nullptr && i < index) {
            buffEl = buffEl->getNextPtr();
            ++i;
        }
        return *buffEl;
    }
}

template<typename T>
T& LinkList<T>::operator[](int index) const {
    if ((index < 0) || (index >= this->size))
        throw std::out_of_range("Index is out of range. Check line: " + std::to_string(__LINE__) + " in " + __FILE__);
    else {
        ListElem<T>* buffEl = this->head;
        int i = 0;
        while (buffEl != nullptr && i < index) {
            buffEl = buffEl->getNextPtr();
            ++i;
        }
        return *buffEl;
    }
}

template<typename T1>
std::ostream& operator<<(std::ostream& out, const LinkList<T1>& list) {
    if (list.size == 0)
        out << NULL;
    else {
        ListElem<T1>* buffEl = list.head;
        int i = 0;
        while (buffEl != nullptr) {
            if (i != list.size - 1) {
                out << buffEl->getVal() << " ";
            } else {
                out << buffEl->getVal();
            }
            buffEl = buffEl->getNextPtr();
            ++i;
        }
    }
    return out;
}

template<typename T>
void LinkList<T>::prepend(T value) {
    if (this->size == 0) {
        ListElem<T>* buffEl = new ListElem<T>;
        buffEl->setVal(value);
        buffEl->setNextPtr(nullptr);
        buffEl->setPrevPtr(nullptr);
        this->head = buffEl;
        this->tail = buffEl;
    } else {
        ListElem<T>* buffEl = new ListElem<T>;
        buffEl->setVal(value);
        buffEl->setNextPtr(this->head);
        buffEl->setPrevPtr(nullptr);
        this->head->setPrevPtr(buffEl);
        this->head = buffEl;
    }
    this->size++;

}

template<typename T>
LinkList<T>::LinkList(T* arr, int amount) {
    this->head = nullptr;
    this->tail = nullptr;
    this->size = 0;
    for (int i = 0; i < amount; ++i) {
        append(arr[i]);
    }
}


template<typename T>
void LinkList<T>::insert(T value, int index) {
    if ((index < 0) || (index > this->size))
        throw std::out_of_range("Index is out of range. Check line: " + std::to_string(__LINE__) + " in " + __FILE__);
    else {
        if (index == 0) {
            prepend(value);
        } else if (index == this->size) {
            append(value);
        } else {
            ListElem<T>* BuffElPrev = this->head;
            for (int i = 0; i < index - 1; ++i) {
                BuffElPrev = BuffElPrev->getNextPtr();
            }
            ListElem<T>* BuffElNext = BuffElPrev->getNextPtr();
            ListElem<T>* buffEl = new ListElem<T>;
            buffEl->setVal(value);
            buffEl->setPrevPtr(BuffElPrev);
            buffEl->setNextPtr(BuffElNext);
            BuffElPrev->setNextPtr(buffEl);
            BuffElNext->setPrevPtr(buffEl);
            this->size++;
        }
    }
}

template<typename T>
ListElem<T>* LinkList<T>::getFirst() {
    return this->head;
}

template<typename T>
ListElem<T>* LinkList<T>::getLast() {
    return this->tail;
}

template<typename T>
LinkList<T>* LinkList<T>::sublist(int start, int end) {
    if ((start < 0) || (start >= this->size) || (end < 0) || (end >= this->size))
        throw std::out_of_range("Index is out of range. Check line: " + std::to_string(__LINE__) + " in " + __FILE__);
    else {
        LinkList<T>* buff = new LinkList<T>;
        for (int i = start; i <= end; ++i) {
            buff->append((*this)[i]);
        }
        return buff;
    }
}

template<typename T>
LinkList<T>* LinkList<T>::concat(LinkList<T>* list) {
    for (int i = 0; i < list->size; ++i) {
        this->append((*list)[i]);
    }
}

template<typename T>
void LinkList<T>::pop(int index) {
    if ((index < 0) || (index >= this->size))
        throw std::out_of_range("Index is out of range. Check line: " + std::to_string(__LINE__) + " in " + __FILE__);
    else {
        if (this->size == 1) {
            delete this->head;
            this->head = nullptr;
            this->tail = nullptr;
        } else if (index == 0) {
            this->head = this->head->getNextPtr();
            delete this->head->getPrevPtr();
            this->head->setPrevPtr(nullptr);
        } else if (index == this->size - 1) {
            this->tail = this->tail->getPrevPtr();
            delete this->tail->getNextPtr();
            this->tail->setNextPtr(nullptr);
        } else {
            ListElem<T>* BuffEl = this->head;
            for (int i = 0; i < index - 1; ++i) {
                BuffEl = BuffEl->getNextPtr();
            }
            BuffEl->setNextPtr(BuffEl->getNextPtr()->getNextPtr());
            delete BuffEl->getNextPtr()->getPrevPtr();
            BuffEl->getNextPtr()->setPrevPtr(BuffEl);
        }
        --this->size;
    }
}

template<typename T>
void LinkList<T>::swap(int index1, int index2) {
    if (index1 < 0 || index1 >= this->size || index2 < 0 || index2 >= this->size)
        throw std::out_of_range("Index is out of range. Check line: " + std::to_string(__LINE__) + " in " + __FILE__);
    else {
        T buff = (*this)[index1];
        (*this)[index1] = (*this)[index2];
        (*this)[index2] = buff;
    }
}

template<typename T>
LinkList<T>::~LinkList() = default;


#endif
