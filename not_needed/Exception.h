#ifndef INC_2_EXCEPTION_H
#define INC_2_EXCEPTION_H

#include <exception>
#include <string>
#include <utility>

class MyException : public std::exception {
private:
    std::string errorMessage;
public:
    MyException(std::string);

    const char *what() const noexcept override;

    ~MyException();
};

MyException::MyException(std::string error) {
    this->errorMessage = std::move(error);
}

const char *MyException::what() const noexcept {
    return this->errorMessage.c_str();
}

MyException::~MyException() = default;

#endif
