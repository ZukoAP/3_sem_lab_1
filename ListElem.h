#ifndef INC_2_LISTELEM_H
#define INC_2_LISTELEM_H

#include <stdexcept>

template<typename T>
class ListElem {
private:
    T val;
    ListElem<T> *next;
    ListElem<T> *prev;
    bool hasVal{};
public:
    ListElem();

    ~ListElem();

    void setVal(T val);

    void setNextPtr(ListElem<T> *);

    void setPrevPtr(ListElem<T> *);

    T getVal();

    ListElem<T> *getNextPtr();

    ListElem<T> *getPrevPtr();

    bool checkVal();

    operator T &();

    template<typename T1>
    friend std::ostream &operator<<(std::ostream &out, const ListElem<T1> &listEl);
};

template<typename T>
ListElem<T>::ListElem() {
    this->hasVal = false;
    this->prev = nullptr;
    this->next = nullptr;
}

template<typename T>
void ListElem<T>::setVal(T value) {
    this->val = value;
    this->hasVal = true;
}

template<typename T>
T ListElem<T>::getVal() {
    if (this->hasVal) {
        return this->val;
    } else {
        throw std::out_of_range(
                "This element has not been initialized. Check line: " + std::to_string(__LINE__) + " in " + __FILE__);
    }
}

template<typename T>
bool ListElem<T>::checkVal() {
    return this->hasVal;
}

template<typename T1>
std::ostream &operator<<(std::ostream &out, const ListElem<T1> &listEl) {
    if (listEl.hasVal) {
        out << listEl.val;
    } else {
        throw std::invalid_argument(
                "This element has not been initialized. Check line: " + std::to_string(__LINE__) + " in " + __FILE__);
    }
    return out;
}

template<typename T>
ListElem<T>::operator T &() {
    if (this->hasVal) {
        return this->val;
    } else {
        throw std::invalid_argument(
                "This element has not been initialized. Check line: " + std::to_string(__LINE__) + " in " + __FILE__);
    }
}

template<typename T>
void ListElem<T>::setNextPtr(ListElem<T> *nextPtr) {
    this->next = nextPtr;
}

template<typename T>
void ListElem<T>::setPrevPtr(ListElem<T> *prevPtr) {
    this->prev = prevPtr;
}

template<typename T>
ListElem<T> *ListElem<T>::getNextPtr() {
    return this->next;
}

template<typename T>
ListElem<T> *ListElem<T>::getPrevPtr() {
    return this->prev;
}

template<typename T>
ListElem<T>::~ListElem() = default;

#endif
