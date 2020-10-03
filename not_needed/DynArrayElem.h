#ifndef INC_2_DYNARRAYELEM_H
#define INC_2_DYNARRAYELEM_H

template<typename T>
class DynArrayElem {
private:
    T val;
    bool hasVal{};
public:
    DynArrayElem();

    ~DynArrayElem();

    void setVal(T val);

    void setCheck();

    T getVal();

    bool checkVal();

    operator T &();

    template<typename T1>
    friend std::ostream &operator<<(std::ostream &out, const DynArrayElem<T1> &dynArrEl);
};

template<typename T>
DynArrayElem<T>::DynArrayElem() {
    this->hasVal = false;
}

template<typename T>
void DynArrayElem<T>::setVal(T value) {
    this->val = value;
    this->hasVal = true;
}

template<typename T>
T DynArrayElem<T>::getVal() {
    if (this->hasVal) {
        return this->val;
    } else {
        throw std::invalid_argument(
                "This element has not been initialized. Check line: " + std::to_string(__LINE__) + " in " + __FILE__);
    }
}

template<typename T>
bool DynArrayElem<T>::checkVal() {
    return this->hasVal;
}

template<typename T1>
std::ostream &operator<<(std::ostream &out, const DynArrayElem<T1> &dynArrEl) {
//    if (dynArrEl.hasVal) {
    out << dynArrEl.val;
//    } else {
//        throw std::invalid_argument(
//                "This element has not been initialized. Check line: " + std::to_string(__LINE__) + " in " + __FILE__);
//    }
    return out;
}

template<typename T>
DynArrayElem<T>::operator T &() {
    return this->val;
}

template<typename T>
void DynArrayElem<T>::setCheck() {
    this->hasVal = true;
}

template<typename T>
DynArrayElem<T>::~DynArrayElem() = default;

#endif
