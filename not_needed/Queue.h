#ifndef INC_2_QUEUE_H
#define INC_2_QUEUE_H

#include <typeinfo>
#include "../ListSequence.h"
#include "../Sequence.h"
#include "../ArraySequence.h"

template<typename T>
class Queue {
public:
    Sequence<T> *data;
public:
/*    Queue(std::string str) {
        if (str == "list")
            this->data = new ListSeq<T>;
        else if (str == "array")
            this->data = new ArraySeq<T>;
    }*/
    Queue(Sequence<T>* seq) {
        this->data = seq;
    }

    Queue(Queue<T> &);

    Queue(T *arr, int amount);

    ~Queue() = default;

    int size() {
        return this->data->length();
    }

    bool empty() {
        return this->data->length() == 0;
    }

    T *front() {
        return (T *) this->data->getFirst();
    }

    T *back() {
        return (T *) this->data->getLast();
    }

    void push(T item) {
        this->data->append(item);
    }

    void pop() {
        this->data->pop(0);
    }

    void swap(int index1, int index2) {
        this->data->swap(index1, index2);
    }

    Queue<T> slice(int begin, int end);

    template<typename F>
    void map(F func);

    template<typename F>
    Queue<T> where(F func);

    template<typename F>
    T reduce(F func, T);

    Queue<T> operator+(Queue<T> &secQueue);

    template<typename T1>
    friend std::ostream &operator<<(std::ostream &out, Queue<T1> &queue);
};

template<typename T>
Queue<T>::Queue(T *arr, int amount) {
    for (int i = 0; i < amount; ++i) {
        this->data->append(arr[i]);
    }
}

template<typename T1>
std::ostream &operator<<(std::ostream &out, Queue<T1> &queue) {
    if (queue.size() == 0)
        out << NULL;
    else {
        for (int i = 0; i < queue.size(); ++i) {
            if (i != queue.size() - 1)
                out << queue.data->getElement(i) << " ";
            else
                out << queue.data->getElement(i);
        }
    }
    return out;
}

template<typename T>
Queue<T>::Queue(Queue<T> &source) {
    if (source.data->getType() == typeid(LinkList<T>)) {
        this->data = new ListSeq<T>;
    } else {
        this->data = new ArraySeq<T>;
    }
    for (int i = 0; i < source.size(); ++i) {
        this->push(source.data->getElement(i));
    }
}

template<typename T>
Queue<T> Queue<T>::operator+(Queue<T> &queue) {
    Queue<T> buff(*this);
    for (int i = 0; i < queue.size(); ++i) {
        buff.push(queue.data->getElement(i));
    }
    return buff;
}

template<typename T>
Queue<T> Queue<T>::slice(int begin, int end) {
    if (begin < 0 || begin >= this->size() || end < 0 || end >= this->size())
        throw std::out_of_range("Index is out of range. Check line: " + std::to_string(__LINE__) + " in " + __FILE__);
    else {
        if (typeid(this->data) == typeid(ListSeq<T> *)) {
            Queue<T> buff(new ListSeq<T>);
            for (int i = begin; i <= end; ++i) {
                buff.push(this->data->getElement(i));
            }
            return buff;
        } else {
            Queue<T> buff(new ArraySeq<T>);
            for (int i = begin; i <= end; ++i) {
                buff.push(this->data->getElement(i));
            }
            return buff;
        }
    }
}

template<typename T>
template<typename F>
void Queue<T>::map(F func) {
    for (int i = 0; i < this->size(); ++i) {
        func(this->data->getElement(i));
    }
}

template<typename T>
template<typename F>
Queue<T> Queue<T>::where(F func) {
    if (typeid(this->data) == typeid(ListSeq<T> *)) {
        Queue<T> buff(new ListSeq<T>);
        for (int i = 0; i < this->size(); ++i) {
            if (func(this->data->getElement(i)) == 1) {
                buff.push(this->data->getElement(i));
            }
        }
        return buff;
    } else {
        Queue<T> buff(new ListSeq<T>);
        for (int i = 0; i < this->size(); ++i) {
            if (func(this->data->getElement(i)) == 1) {
                buff.push(this->data->getElement(i));
            }
        }
        return buff;
    }
}

template<typename T>
template<typename F>
T Queue<T>::reduce(F func, T init) {
    T buff = func(this->data->getElement(0), init);
    for (int i = 1; i < this->size(); ++i) {
        buff = func(this->data->getElement(i), buff);
    }
    return buff;
}


#endif
