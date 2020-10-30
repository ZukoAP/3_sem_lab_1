
#include <cstdlib>
#include <cassert>
#include <stdexcept>
#include <cstring>
#include <regex>

using namespace std;

template<typename T>
class dynamicArray {
private:
    T *data;
    int size;
public:
    dynamicArray();

    dynamicArray(int size);

    dynamicArray(dynamicArray<T> &arr);

//    dynamicArray(dynamicArray<T> const &arr);

    dynamicArray(string base);

    dynamicArray(T *items, int size);

    int length() { return this->size; }

    void resize(int size);

    void delByValue(T val);

    void delById(int id);
    void pop(int id){ delById(id);};

    void insert(T data, int index);

    void prepend(T data) { return insert(data, 0); }

    void append(T data) { return insert(data, this->size); }

    dynamicArray<T>* concat(dynamicArray<T>* arr);

    dynamicArray<T> slice(int start, int end);

    T& operator[](int index);

    T& operator[](int index) const;

    template<typename T1>
    friend ostream& operator<<(ostream& out, const dynamicArray<T1>& dynArr);

    void swap(int index1, int index2);

    ~dynamicArray() = default;
};

template<typename T>
dynamicArray<T>::dynamicArray() {
    this->data = (T *) malloc(0);
    this->size = 0;
}

template<typename T>
dynamicArray<T>::dynamicArray(int size) {
    assert(size >= 0);
    this->data = (T *) malloc(sizeof(T) * size);
    this->size = size;
    for (int i = 0; i < size; i++) {
        (*this)[i] = (T) NULL;
    }
}

template<typename T>
dynamicArray<T>::dynamicArray(dynamicArray<T> &arr) {
    this->data = (T *) malloc(sizeof(T) * arr.length());
    this->size = arr.length();
    for (int i = 0; i < arr.length(); i++) {
        (*this)[i] = arr[i];
    }
}

/*template<typename T>
dynamicArray<T>::dynamicArray(dynamicArray<T> const &arr) {
    this->data = (T *) malloc(sizeof(T) * arr.length());
    this->size = arr.length();
    for (int i = 0; i < arr.length(); i++) {
        (*this)[i] = arr[i];
    }
}*/

template<typename T>
dynamicArray<T>::dynamicArray(string base) {
    while (base.find("  ") != string::npos) {
        base = regex_replace(base, regex("  "), " ");
    }
    if (base[base.length() - 1] == ' ') base.erase(base.length() - 1, base.length());
    if (base[0] == ' ') base.erase(0, 1);
    this->data = (T *) malloc(0);
    this->size = 0;
    string token;
    unsigned long pos;
    while ((pos = base.find(' ')) != string::npos) {
        token = base.substr(0, pos);
        this->append(stoi(token));
        base.erase(0, pos + 1);
    }
    this->append(stoi(base));
}

template<typename T>
dynamicArray<T>::dynamicArray(T *items, int size) {
    assert(size >= 0);
    this->data = (T *) malloc(sizeof(T) * size);
    this->size = size;
    for (int i = 0; i < size; i++) {
        (*this)[i] = items[i];
    }
}

template<typename T>
void dynamicArray<T>::resize(int size) {
    assert(size >= 0);
    this->data = (T *) realloc(this->data, sizeof(T) * size);
    this->size = size;
}

template<typename T>
void dynamicArray<T>::delByValue(T val) {
    int flag = 0;
    for (int i = 0; i < this->size; i++) {
        if ((*this)[i] == val && !flag) {
            flag = 1;
        } else if (flag) (*this)[i - 1] = (*this)[i];
    }
    this->resize(this->size - 1);
}

template<typename T>
void dynamicArray<T>::delById(int id) {
    for (int i = id + 1; i < this->size; i++) {
        (*this)[i - 1] = (*this)[i];
    }
    this->resize(this->size - 1);
}

template<typename T>
void dynamicArray<T>::insert(T data, int index) {
    if (index > this->size) {
        throw out_of_range("Out of range");
    }
    this->size++;
    this->data = (T *) realloc(this->data, sizeof(T) * (this->size));
    for (int i = this->size - 2; i >= index; i--) {
        (*this)[i + 1] = (*this)[i];
    }
    (*this)[index] = data;
}

template<typename T>
dynamicArray<T> *dynamicArray<T>::concat(dynamicArray<T> *arr) {
    dynamicArray<T> *out = new dynamicArray(*this);
    for (int i = 0; i < arr->length(); i++) {
        out->append((*arr)[i]);
    }
    return out;
}

template<typename T>
dynamicArray<T> dynamicArray<T>::slice(int start, int end) {
    start = (start >= 0) ? start : this->size + start;
    end = (end >= 0) ? end : this->size + end;
    assert(start < end);
    dynamicArray<T> out;
    for (int i = start; i < end; i++) {
        out.append((*this)[i]);
    }
    return out;
}

template<typename T>
T& dynamicArray<T>::operator[](int index) {
    if ((index <= -size) or (index >= size)) {
        throw out_of_range("Index out of range");
    }
    return this->data[(index >= 0) ? index : (this->size + index)];
}

template<typename T>
T& dynamicArray<T>::operator[](int index) const {
    if ((index <= -size) or (index >= size)) {
        throw out_of_range("Index out of range");
    }
    return this->data[(index >= 0) ? index : (this->size + index)];
}

template<typename T1>
ostream& operator<<(ostream& out, const dynamicArray<T1>& dynArr) {
    for (int i = 0; i < dynArr.size; ++i) {
        if (i != dynArr.size - 1) {
            out << dynArr.data[i] << " ";
        } else { out << dynArr.data[i]; }
    }
    return out;
}

template<typename T>
void dynamicArray<T>::swap(int index1, int index2) {
    if (index1 < 0 || index1 >= this->size || index2 < 0 || index2 >= this->size)
        throw out_of_range("Index is out of range. Check line: " + std::to_string(__LINE__) + " in " + __FILE__);
    else {
        //std::swap<T>((*this)[index1], (*this)[index2]);
        T buffEl = (*this)[index1];
        (*this)[index1] = (*this)[index2];
        (*this)[index2] = buffEl;
    }
}

