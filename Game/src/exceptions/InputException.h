#ifndef INPUT_EXCEPTION_H
#define INPUT_EXCEPTION_H

#include <exception>
#include <string>
#include <iostream>

class InputException : public std::exception {
private:
    std::string message;

public:
    InputException(const std::string& msg);
    virtual const char* what() const noexcept override;
};


class InvalidInputException : public InputException {
public:
    InvalidInputException(const std::string& details = "");
};


class OutOfRangeInputException : public InputException {
public:
    OutOfRangeInputException(int value, int minimo, int maximo);
};


class InputBufferException : public InputException {
public:
    InputBufferException();
};

#endif
